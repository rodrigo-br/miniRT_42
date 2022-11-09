/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:08:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/08 15:27:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

/* Scenario Outline: Intersecting a cone with a ray
Given shape ← cone()
And direction ← normalize(<direction>)
And r ← ray(<origin>, direction)
When xs ← local_intersect(shape, r)
Then xs.count = 2
And xs[0].t = <t0>
And xs[1].t = <t1>
Examples:
| origin          | direction           | t0      | t1       |
| point(0, 0, -5) | vector(0, 0, 1)     | 5       | 5        |
| point(0, 0, -5) | vector(1, 1, 1)     | 8.66025 | 8.66025  |
| point(1, 1, -5) | vector(-0.5, -1, 1) | 4.55006 | 49.44994 | */
void	test_intersect_cone(void)
{
	t_object	*cone;
	t_vector	*d1, *d2, *d3;
	t_point		*o1, *o2, *o3;
	t_ray		*r1, *r2, *r3;
	t_intersect	*xs = NULL;

	cone = create_cone();
	cone->cone.capped = FALSE;
	o1 = create_point(0, 0, -5);
	o2 = create_point(0, 0, -5);
	o3 = create_point(1, 1, -5);
	d1 = normalize(&(t_vector){0, 0, 1, 0});
	d2 = normalize(&(t_vector){1, 1, 1, 0});
	d3 = normalize(&(t_vector){-0.5, -1, 1, 0});
	r1 = create_ray(o1, d1);
	r2 = create_ray(o2, d2);
	r3 = create_ray(o3, d3);
	cone->intersect(cone, r1, &xs);
	cone->intersect(cone, r2, &xs);
	cone->intersect(cone, r3, &xs);
	TEST_ASSERT_EQUAL(4, intersection_list_size(xs));
	TEST_ASSERT_TRUE(is_equal_double(4.55006, xs->time));
	TEST_ASSERT_TRUE(is_equal_double(5.0, xs->next->time));
	TEST_ASSERT_TRUE(is_equal_double(8.66025, xs->next->next->time));
	TEST_ASSERT_TRUE(is_equal_double(49.44994, xs->next->next->next->time));
	destroy_ray(r1);
	destroy_ray(r2);
	destroy_ray(r3);
	destroy_shape(cone);
	intersection_list_clear(&xs);
}

/* Scenario: Intersecting a cone with a ray parallel to one of its halves
Given shape ← cone()
And direction ← normalize(vector(0, 1, 1))
And r ← ray(point(0, 0, -1), direction)
When xs ← local_intersect(shape, r)
Then xs.count = 1
And xs[0].t = 0.35355 */
void	test_intersect_parallel_to_half(void)
{
	t_object	*cone;
	t_vector	*d;
	t_point		*o;
	t_ray		*r;
	t_intersect	*xs = NULL;

	cone = create_cone();
	o = create_point(0, 0, -1);
	d = normalize(&(t_vector){0, 1, 1, 0});
	r = create_ray(o, d);
	cone->intersect(cone, r, &xs);
	TEST_ASSERT_EQUAL(1, intersection_list_size(xs));
	TEST_ASSERT_TRUE(is_equal_double(0.35355, xs->time));
	destroy_ray(r);
	destroy_shape(cone);
	intersection_list_clear(&xs);
}

/* Scenario Outline: Intersecting a cone's end caps
Given shape ← cone()
And shape.minimum ← -0.5
And shape.maximum ← 0.5
And shape.closed ← true
And direction ← normalize(<direction>)
And r ← ray(<origin>, direction)
When xs ← local_intersect(shape, r)
Then xs.count = <count>
Examples:
| origin             | direction       | count |
| point(0, 0, -5)    | vector(0, 1, 0) | 0     |
| point(0, 0, -0.25) | vector(0, 1, 1) | 2     |
| point(0, 0, -0.25) | vector(0, 1, 0) | 4     | */
void	test_intersect_cone_caps(void)
{
	t_object	*cone;
	t_vector	*d1, *d2, *d3;
	t_point		*o1, *o2, *o3;
	t_ray		*r1, *r2, *r3;
	t_intersect	*xs = NULL;

	cone = create_cone();
	cone->cone.min = -0.5;
	cone->cone.max = 0.5;
	o1 = create_point(0, 0, -5);
	o2 = create_point(0, 0, -0.25);
	o3 = create_point(0, 0, -0.25);
	d1 = normalize(&(t_vector){0, 1, 0, 0});
	d2 = normalize(&(t_vector){0, 1, 1, 0});
	d3 = normalize(&(t_vector){0, 1, 0, 0});
	r1 = create_ray(o1, d1);
	r2 = create_ray(o2, d2);
	r3 = create_ray(o3, d3);
	cone->intersect(cone, r1, &xs);
	cone->intersect(cone, r2, &xs);
	cone->intersect(cone, r3, &xs);
	TEST_ASSERT_EQUAL(6, intersection_list_size(xs));
	destroy_ray(r1);
	destroy_ray(r2);
	destroy_ray(r3);
	destroy_shape(cone);
	intersection_list_clear(&xs);
}

/* Scenario Outline: Computing the normal vector on a cone
Given shape ← cone()
When n ← local_normal_at(shape, <point>)
Then n = <normal>
Examples:
| point            | normal            |
| point(0, 0, 0)   | vector(0, 0, 0)   |
| point(1, 1, 1)   | vector(1, -√2, 1) |
| point(-1, -1, 0) | vector(-1, 1, 0)  | */
void	test_get_cone_normal(void)
{
	t_object	*cone;
	t_vector	*n1, *n2, *n3;

	cone = create_cone();
	n1 = cone->get_normal(cone, &(t_point){0, 0, 0, 1});
	n2 = cone->get_normal(cone, &(t_point){1, 1, 1, 1});
	n3 = cone->get_normal(cone, &(t_point){-1, -1, 0, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, 0, 0}, n1));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){1, -sqrt(2), 1, 0}, n2));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){-1, 1, 0, 0}, n3));
	destroy_shape(cone);
	free(n1); free(n2); free(n3);
}

/* Note to self:
	this leaks                              a lot.
	only run this if you have a display available.
*/
void	test_print_cylinder_and_cone(void)
{
	t_object	*floor, *backdrop, *cone;
	t_matrix	*aux;
	t_world		*world;
	t_cam		*camera;
	t_canvas	*canvas;
	void		*win;

	floor = create_plane();

	backdrop = create_plane();
	aux = translate_matrix(0, 0, 100);
	set_object_transformation(backdrop, multiply_matrix(aux, rotate_matrix_x(radians(90))));
	free(aux);
	set_color(backdrop->material->color, 1, 0, 0);

	cone = create_cone();
	set_color(cone->material->color, 0.7, 0.7, 0.7);
	set_object_transformation(cone,
		multiply_matrix(translate_matrix(0, 1, 5), full_rotation_matrix(create_vector(0,-0.78935,-0.61394))));
	cone->material->specular = 1.0;
	cone->cone.min = -1.5;
	cone->cone.max = 1.5;

	world = create_world();
	world->light_point = ft_lstnew(create_light_point(
			create_point(-10, 10, -10),
			create_color(1, 1, 1)
		));
	// ft_lstadd_front(&world->objects, ft_lstnew(floor));
	// ft_lstadd_front(&world->objects, ft_lstnew(backdrop));
	ft_lstadd_front(&world->objects, ft_lstnew(cone));

	camera = create_camera(RT_WIDTH, RT_HEIGHT, radians(90));
	set_camera_transformation(camera, view_transform(
		create_point(0, 1.5, -5),
		normalize(sub_tuple(&(t_point){0, 1, 0, 1}, &(t_point){0, 1.5, -5, 1})),
		create_vector(0, 1, 0)
	));

	canvas = render(camera, world);
	win = mlx_new_window(
		canvas->mlx,
		(int)round(camera->h_size),
		(int)round(camera->v_size),
		"uwu"
	);
	mlx_put_image_to_window(canvas->mlx, win, canvas->image, 0, 0);
	mlx_loop(canvas->mlx);
}

void	test_cone(void)
{
	RUN_TEST(test_intersect_cone);
	RUN_TEST(test_intersect_parallel_to_half);
	RUN_TEST(test_intersect_cone_caps);
	RUN_TEST(test_get_cone_normal);
	// uncomment at your own risk
	// RUN_TEST(test_print_cylinder_and_cone);
}
