/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:00:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:13:13 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	test_ray_creation_hard(void)
{
	t_point		*origin;
	t_vector	*direction;
	t_ray		*ray;

	origin = create_point(1, 2, 3);
	direction = create_point(4, 5, 6);
	ray = create_ray(origin, direction);
	TEST_ASSERT_NOT_NULL(ray);
	TEST_ASSERT_EQUAL(origin, ray->origin);
	TEST_ASSERT_EQUAL(direction, ray->direction);
	destroy_ray(ray);
}

void	test_ray_creation_rand(void)
{
	t_point		*origin;
	t_vector	*direction;
	t_ray		*ray;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		origin = create_point(double_rand(), double_rand(), double_rand());
		direction = create_point(double_rand(), double_rand(), double_rand());
		ray = create_ray(origin, direction);
		TEST_ASSERT_NOT_NULL(ray);
		TEST_ASSERT_EQUAL(origin, ray->origin);
		TEST_ASSERT_EQUAL(direction, ray->direction);
		destroy_ray(ray);
	}
}

void	test_position_hard(void)
{
	t_ray	*ray;
	t_point	*e1, *e2, *e3, *e4;
	t_point	*p1, *p2, *p3, *p4;

	ray = create_ray(create_point(2, 3, 4), create_vector(1, 0, 0));
	p1 = get_position(ray, 0);
	p2 = get_position(ray, 1);
	p3 = get_position(ray, -1);
	p4 = get_position(ray, 2.5);
	e1 = create_point(2, 3, 4);
	e2 = create_point(3, 3, 4);
	e3 = create_point(1, 3, 4);
	e4 = create_point(4.5, 3, 4);
	TEST_ASSERT_TRUE(is_equal_tuple(p1, e1));
	TEST_ASSERT_TRUE(is_equal_tuple(p2, e2));
	TEST_ASSERT_TRUE(is_equal_tuple(p3, e3));
	TEST_ASSERT_TRUE(is_equal_tuple(p4, e4));
	free(p1); free(p2); free(p3); free(p4);
	free(e1); free(e2); free(e3); free(e4);
	destroy_ray(ray);
}

void	test_sphere_creation(void)
{
	t_object	*sphere;
	t_matrix	*identity;

	identity = create_identity_matrix();
	sphere = create_sphere();
	TEST_ASSERT_NOT_NULL(sphere);
	TEST_ASSERT_TRUE(sphere->type == ID_SPHERE);
	TEST_ASSERT_TRUE(is_equal_matrix(identity, sphere->transformation));
	destroy_shape(sphere);
	free(identity);
}

void	test_intersect_two_points(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, ray, &xslist);
	TEST_ASSERT_EQUAL(2, intersection_list_size(xslist));
	TEST_ASSERT_EQUAL_DOUBLE(4.0, xslist->time);
	TEST_ASSERT_EQUAL_DOUBLE(6.0, xslist->next->time);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_intersect_same_point(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	ray = create_ray(create_point(0, 1, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, ray, &xslist);
	TEST_ASSERT_EQUAL(1, intersection_list_size(xslist));
	TEST_ASSERT_EQUAL_DOUBLE(5.0, xslist->time);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_intersect_zero_points(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	ray = create_ray(create_point(0, 2, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, ray, &xslist);
	TEST_ASSERT_NULL(xslist);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_ray_inside_sphere(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, ray, &xslist);
	TEST_ASSERT_EQUAL(2, intersection_list_size(xslist));
	TEST_ASSERT_EQUAL_DOUBLE(-1.0, xslist->time);
	TEST_ASSERT_EQUAL_DOUBLE(1.0, xslist->next->time);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_sphere_behind_ray(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	ray = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	sphere = create_sphere();
	intersect_sphere(sphere, ray, &xslist);
	TEST_ASSERT_EQUAL(2, intersection_list_size(xslist));
	TEST_ASSERT_EQUAL_DOUBLE(-6.0, xslist->time);
	TEST_ASSERT_EQUAL_DOUBLE(-4.0, xslist->next->time);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_intersect_creation(void)
{
	t_intersect	*intersection;
	t_object	*sphere;

	sphere = create_sphere();
	intersection = create_intersection(3.5, sphere);
	TEST_ASSERT_NOT_NULL(intersection);
	TEST_ASSERT_EQUAL_PTR(sphere, intersection->object);
	TEST_ASSERT_EQUAL_DOUBLE(3.5, intersection->time);
	destroy_shape(sphere); free(intersection);
}

void	test_hit_all_positive(void)
{
	t_intersect	*h;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	sphere = create_sphere();
	intersection_sorted_insert(&xslist, create_intersection(2, sphere));
	intersection_sorted_insert(&xslist, create_intersection(12, sphere));
	intersection_sorted_insert(&xslist, create_intersection(1, sphere));
	h = get_hit(xslist);
	TEST_ASSERT_NOT_NULL(h);
	TEST_ASSERT_EQUAL(1, h->time);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_hit_some_negative(void)
{
	t_intersect	*h;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	sphere = create_sphere();
	intersection_sorted_insert(&xslist, create_intersection(-2, sphere));
	intersection_sorted_insert(&xslist, create_intersection(-12, sphere));
	intersection_sorted_insert(&xslist, create_intersection(42, sphere));
	intersection_sorted_insert(&xslist, create_intersection(-1, sphere));
	h = get_hit(xslist);
	TEST_ASSERT_NOT_NULL(h);
	TEST_ASSERT_EQUAL(42, h->time);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_hit_all_negative(void)
{
	t_intersect	*h;
	t_object	*sphere;
	t_intersect	*xslist = NULL;

	sphere = create_sphere();
	intersection_sorted_insert(&xslist, create_intersection(-2, sphere));
	intersection_sorted_insert(&xslist, create_intersection(-12, sphere));
	intersection_sorted_insert(&xslist, create_intersection(-42, sphere));
	intersection_sorted_insert(&xslist, create_intersection(-1, sphere));
	h = get_hit(xslist);
	TEST_ASSERT_NULL(h);
	destroy_shape(sphere);
	intersection_list_clear(&xslist);
}

void	test_ray_translation(void)
{
	t_ray		*ray, *transformed;
	t_matrix	*matrix;

	ray = create_ray(create_point(1, 2, 3), create_vector(0, 1, 0));
	matrix = translate_matrix(3, 4, 5);
	transformed = transform_ray(ray, matrix);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_point){4, 6, 8, 1}, transformed->origin));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, transformed->direction));
	destroy_ray(ray);
	destroy_ray(transformed);
	free(matrix);
}

void	test_ray_scaling(void)
{
	t_ray		*ray, *transformed;
	t_matrix	*matrix;

	ray = create_ray(create_point(1, 2, 3), create_vector(0, 1, 0));
	matrix = scale_matrix(2, 3, 4);
	transformed = transform_ray(ray, matrix);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_point){2, 6, 12, 1}, transformed->origin));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 3, 0, 0}, transformed->direction));
	destroy_ray(ray);
	destroy_ray(transformed);
	free(matrix);
}

void	test_sphere_set_transform(void)
{
	t_object	*sphere;
	t_matrix	*transformation;

	sphere = create_sphere();
	transformation = translate_matrix(2, 3, 4);
	set_transformation(sphere, transformation);
	TEST_ASSERT_TRUE(is_equal_matrix(transformation, sphere->transformation));
	destroy_shape(sphere);
}

void	test_intersect_scaled_sphere(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*list = NULL;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	set_transformation(sphere, scale_matrix(2, 2, 2));
	intersect_sphere(sphere, ray, &list);
	TEST_ASSERT_EQUAL(2, intersection_list_size(list));
	TEST_ASSERT_EQUAL_DOUBLE(3.0, list->time);
	TEST_ASSERT_EQUAL_DOUBLE(7.0, list->next->time);
	TEST_ASSERT_NULL(list->next->next);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&list);
}

void	test_intersect_translated_sphere(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*list = NULL;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	set_transformation(sphere, translate_matrix(5, 0, 0));
	intersect_sphere(sphere, ray, &list);
	TEST_ASSERT_EQUAL(0, intersection_list_size(list));
	TEST_ASSERT_NULL(list);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&list);
}

/* Note to self:
	this leaks                              a lot.
	only run this if you have a display available.
*/
void	test_print_circle(void)
{
	double		wall_size = 10.0;
	double		world_x = 500;
	double		world_y = 500;
	double		world_z = 10;
	int			canvas_pixels = 500;
	double		pixel_size = wall_size / canvas_pixels;
	double		half = wall_size / 2;
	void		*mlx = mlx_init();
	void		*win = mlx_new_window(mlx, world_x, world_y, "uwu");
	t_canvas	*canvas = create_canvas(mlx, canvas_pixels, canvas_pixels);
	t_object	*sphere = create_sphere();
	t_point		*origin = create_point(0, 0, -5);
	t_rgb		*color = create_color(rand(), rand(), rand());
	t_intersect	*list = NULL;
	t_point		*position;
	t_ray		*ray;

	for (int y = 0; y < canvas_pixels - 1; y++)
	{
		world_y = half - pixel_size * y;
		for (int x = 0; x < canvas_pixels - 1; x++)
		{
			world_x = -half + pixel_size * x;
			position = create_point(world_x, world_y, world_z);
			ray = create_ray(origin, normalize(sub_tuple(position, origin)));
			intersect_sphere(sphere, ray, &list);
			if (get_hit(list))
				write_to_canvas(canvas, x, y, *color);
			intersection_list_clear(&list);
		}
	}
	mlx_put_image_to_window(mlx, win, canvas->image, 0, 0);
	mlx_loop(mlx);
}

void	test_ray(void)
{
	RUN_TEST(test_ray_creation_hard);
	RUN_TEST(test_ray_creation_rand);
	RUN_TEST(test_position_hard);
	RUN_TEST(test_sphere_creation);
	RUN_TEST(test_intersect_two_points);
	RUN_TEST(test_intersect_same_point);
	RUN_TEST(test_intersect_zero_points);
	RUN_TEST(test_ray_inside_sphere);
	RUN_TEST(test_sphere_behind_ray);
	RUN_TEST(test_intersect_creation);
	RUN_TEST(test_hit_all_positive);
	RUN_TEST(test_hit_some_negative);
	RUN_TEST(test_hit_all_negative);
	RUN_TEST(test_ray_translation);
	RUN_TEST(test_ray_scaling);
	RUN_TEST(test_sphere_set_transform);
	RUN_TEST(test_intersect_scaled_sphere);
	RUN_TEST(test_intersect_translated_sphere);
	// uncomment at your own risk
	// RUN_TEST(test_print_circle);
}
