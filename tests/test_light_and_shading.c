/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_light_and_shading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:22:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 10:30:26 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	test_normalat_sphere_x_axis(void)
{
	t_object	*sphere;
	t_vector	*normal;

	sphere = create_sphere();
	normal = get_sphere_normal(sphere, &(t_point){1, 0, 0, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){1, 0, 0, 0}, normal));
	destroy_shape(sphere);
	free(normal);
}

void	test_normalat_sphere_y_axis(void)
{
	t_object	*sphere;
	t_vector	*normal;

	sphere = create_sphere();
	normal = get_sphere_normal(sphere, &(t_point){0, 1, 0, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, normal));
	destroy_shape(sphere);
	free(normal);
}

void	test_normalat_sphere_z_axis(void)
{
	t_object	*sphere;
	t_vector	*normal;

	sphere = create_sphere();
	normal = get_sphere_normal(sphere, &(t_point){0, 0, 1, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, 1, 0}, normal));
	destroy_shape(sphere);
	free(normal);
}

void	test_normalat_sphere_nonaxial(void)
{
	t_object	*sphere;
	t_vector	*normal;
	double		wtf = sqrt(3)/3;

	sphere = create_sphere();
	normal = get_sphere_normal(sphere, &(t_point){wtf, wtf, wtf, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){wtf, wtf, wtf, 0}, normal));
	destroy_shape(sphere);
	free(normal);
}

void	test_normalat_is_normalized(void)
{
	t_object	*sphere;
	t_vector	*normal, *_normalize;
	double		wtf = sqrt(3)/3;

	sphere = create_sphere();
	normal = get_sphere_normal(sphere, &(t_point){wtf, wtf, wtf, 1});
	_normalize = normalize(normal);
	TEST_ASSERT_TRUE(is_equal_tuple(_normalize, normal));
	destroy_shape(sphere);
	free(normal); free(_normalize);
}

void	test_normalat_translated_sphere(void)
{
	t_object	*sphere;
	t_vector	*normal;

	sphere = create_sphere();
	set_object_transformation(sphere, translate_matrix(0, 1, 0));
	normal = get_sphere_normal(sphere, &(t_point){0, 1.70711, -0.70711, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0.70711, -0.70711, 0}, normal));
	destroy_shape(sphere);
	free(normal);
}

void	test_normalat_scaled_sphere(void)
{
	t_object	*sphere;
	t_vector	*normal;
	t_matrix	*scale, *rotate;

	sphere = create_sphere();
	scale = scale_matrix(1, 0.5, 1);
	rotate = rotate_matrix_z(radians(180 / 5));
	set_object_transformation(sphere, multiply_matrix(scale, rotate));
	normal = get_sphere_normal(sphere, &(t_point){0, sqrt(2)/2, -sqrt(2)/2, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0.97014, -0.24254, 0}, normal));
	destroy_shape(sphere);
	free(normal);
	free(scale);
	free(rotate);
}

void	test_reflect_vector_45deg(void)
{
	t_vector	*reflection;

	reflection = reflect(&(t_vector){1, -1, 0, 0}, &(t_vector){0, 1, 0, 0});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){1, 1, 0, 0}, reflection));
	free(reflection);
}

void	test_reflect_vector_slant(void)
{
	t_vector	*reflection;

	reflection = reflect(&(t_vector){0, -1, 0, 0}, &(t_vector){sqrt(2)/2, sqrt(2)/2, 0, 0});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){1, 0, 0, 0}, reflection));
	free(reflection);
}

void	test_create_light_point(void)
{
	t_light_pnt	*light_point;

	light_point = create_light_point(create_point(0, 0, 0), create_color(1, 1, 1));
	TEST_ASSERT_NOT_NULL(light_point);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_point){0, 0, 0, 1}, light_point->position));
	TEST_ASSERT_TRUE(is_equal_double(1, light_point->intensity->red));
	TEST_ASSERT_TRUE(is_equal_double(1, light_point->intensity->green));
	TEST_ASSERT_TRUE(is_equal_double(1, light_point->intensity->blue));
	destroy_light_point(light_point);
}

void	test_create_material(void)
{
	t_material	*material;

	material = create_material();
	TEST_ASSERT_NOT_NULL(material);
	TEST_ASSERT_TRUE(is_equal_double(1, material->color->red));
	TEST_ASSERT_TRUE(is_equal_double(1, material->color->green));
	TEST_ASSERT_TRUE(is_equal_double(1, material->color->blue));
	TEST_ASSERT_TRUE(is_equal_double(0.1, material->ambient));
	TEST_ASSERT_TRUE(is_equal_double(0.9, material->diffuse));
	TEST_ASSERT_TRUE(is_equal_double(0.9, material->specular));
	TEST_ASSERT_TRUE(is_equal_double(200.0, material->shininess));
	destroy_material(material);
}

void	test_lighting_between_light_and_surface(void)
{
	t_lightattr	*args;
	t_rgb		*result;

	args = create_lightattr(
		create_light_point(create_point(0, 0, -10), create_color(1, 1, 1)),
		create_pos_attr(create_vector(0, 0, -1), create_vector(0, 0, -1), create_point(0, 0, 0)),
		create_material()
	);
	result = lighting(args);
	TEST_ASSERT_TRUE(is_equal_double(1.9, result->red));
	TEST_ASSERT_TRUE(is_equal_double(1.9, result->green));
	TEST_ASSERT_TRUE(is_equal_double(1.9, result->blue));
	destroy_lightattr(args);
	free(result);
	TEST_ASSERT_NOT_NULL(result);

}

void	test_lighting_camera_offset_45deg(void)
{
	t_lightattr	*args;
	t_rgb		*result;

	args = create_lightattr(
		create_light_point(create_point(0, 0, -10), create_color(1, 1, 1)),
		create_pos_attr(create_vector(0, sqrt(2)/2, -sqrt(2)/2), create_vector(0, 0, -1), create_point(0, 0, 0)),
		create_material()
	);
	result = lighting(args);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_TRUE(is_equal_double(1.0, result->red));
	TEST_ASSERT_TRUE(is_equal_double(1.0, result->green));
	TEST_ASSERT_TRUE(is_equal_double(1.0, result->blue));
	destroy_lightattr(args);
	free(result);
}

void	test_lighting_light_offset_45deg_and_camera_opposite(void)
{
	t_lightattr	*args;
	t_rgb		*result;

	args = create_lightattr(
		create_light_point(create_point(0, 10, -10), create_color(1, 1, 1)),
		create_pos_attr(create_vector(0, 0, -1), create_vector(0, 0, -1), create_point(0, 0, 0)),
		create_material()
	);
	result = lighting(args);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_TRUE(is_equal_double(0.7364, result->red));
	TEST_ASSERT_TRUE(is_equal_double(0.7364, result->green));
	TEST_ASSERT_TRUE(is_equal_double(0.7364, result->blue));
	destroy_lightattr(args);
	free(result);
}

void	test_lighting_camera_in_reflection_vector(void)
{
	t_lightattr	*args;
	t_rgb		*result;

	args = create_lightattr(
		create_light_point(create_point(0, 10, -10), create_color(1, 1, 1)),
		create_pos_attr(create_vector(0, -sqrt(2)/2, -sqrt(2)/2), create_vector(0, 0, -1), create_point(0, 0, 0)),
		create_material()
	);
	result = lighting(args);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_TRUE(is_equal_double(1.6364, result->red));
	TEST_ASSERT_TRUE(is_equal_double(1.6364, result->green));
	TEST_ASSERT_TRUE(is_equal_double(1.6364, result->blue));
	destroy_lightattr(args);
	free(result);
}

void	test_lighting_light_behind_surface(void)
{
	t_lightattr	*args;
	t_rgb		*result;

	args = create_lightattr(
		create_light_point(create_point(0, 0, 10), create_color(1, 1, 1)),
		create_pos_attr(create_vector(0, 0, -1), create_vector(0, 0, -1), create_point(0, 0, 0)),
		create_material()
	);
	result = lighting(args);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_TRUE(is_equal_double(0.1, result->red));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result->green));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result->blue));
	destroy_lightattr(args);
	free(result);
}

/* Scenario: Lighting with the surface in shadow
Given eyev ← vector(0, 0, -1)
And normalv ← vector(0, 0, -1)
And light ← point_light(point(0, 0, -10), color(1, 1, 1))
And in_shadow ← true
When result ← lighting(m, light, position, eyev, normalv, in_shadow)
Then result = color(0.1, 0.1, 0.1) */
void	test_lighting_surface_in_shadow(void)
{
	t_lightattr	*args;
	t_rgb		*result;

	args = create_lightattr(
		create_light_point(create_point(0, 0, -10), create_color(1, 1, 1)),
		create_pos_attr(create_vector(0, 0, -1), create_vector(0, 0, -1), create_point(0, 0, 0)),
		create_material()
	);
	args->in_shadow = TRUE;
	result = lighting(args);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_TRUE(is_equal_double(0.1, result->red));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result->green));
	TEST_ASSERT_TRUE(is_equal_double(0.1, result->blue));
	destroy_lightattr(args);
	free(result);
}

/* Note to self:
	this leaks                              a lot.
	only run this if you have a display available.
*/
void	test_print_3d_sphere(void)
{
	double		wall_size = 7.0;
	double		world_x = 500;
	double		world_y = 500;
	double		world_z = 10;
	int			canvas_pixels = 500;
	double		pixel_size = wall_size / canvas_pixels;
	double		half = wall_size / 2;
	t_canvas	*canvas = create_canvas(canvas_pixels, canvas_pixels);
	t_object	*sphere = create_sphere();
	t_point		*origin = create_point(0, 0, -5);
	void		*win = mlx_new_window(canvas->mlx, world_x, world_y, "uwu");
	t_intersect	*list = NULL;
	t_rgb		*color;
	t_intersect	*just_hit;
	t_light_pnt	*lp;
	t_point		*position;
	t_point		*point;
	t_vector	*normal;
	t_vector	*eye;
	t_ray		*ray;
	t_lightattr	*attr;

	free(sphere->material->color);
	sphere->material->color = create_color(color_rand(), color_rand(), color_rand());
	lp = create_light_point(create_point(-10, 10, -10), create_color(0.9, 0.9, 0.9));
	for (int y = 0; y < canvas_pixels - 1; y++)
	{
		world_y = half - pixel_size * y;
		for (int x = 0; x < canvas_pixels - 1; x++)
		{
			world_x = -half + pixel_size * x;
			position = create_point(world_x, world_y, world_z);
			ray = create_ray(origin, normalize(sub_tuple(position, origin)));
			intersect_sphere(sphere, ray, &list);
			just_hit = get_hit(list);
			if (just_hit)
			{
				point = get_position(ray, just_hit->time);
				normal = get_sphere_normal(just_hit->object, point);
				eye = neg_tuple(ray->direction);
				attr = create_lightattr(lp, create_pos_attr(eye, normal, point), just_hit->object->material);
				color = lighting(attr);
				write_to_canvas(canvas, x, y, color->merged);
			}
			intersection_list_clear(&list);
		}
	}
	mlx_put_image_to_window(canvas->mlx, win, canvas->image, 0, 0);
	mlx_loop(canvas->mlx);
}

void	test_light_and_shading(void)
{
	RUN_TEST(test_normalat_sphere_x_axis);
	RUN_TEST(test_normalat_sphere_y_axis);
	RUN_TEST(test_normalat_sphere_z_axis);
	RUN_TEST(test_normalat_sphere_nonaxial);
	RUN_TEST(test_normalat_is_normalized);
	RUN_TEST(test_normalat_translated_sphere);
	RUN_TEST(test_normalat_scaled_sphere);
	RUN_TEST(test_reflect_vector_45deg);
	RUN_TEST(test_reflect_vector_slant);
	RUN_TEST(test_create_light_point);
	RUN_TEST(test_create_material);
	RUN_TEST(test_lighting_between_light_and_surface);
	RUN_TEST(test_lighting_camera_offset_45deg);
	RUN_TEST(test_lighting_light_offset_45deg_and_camera_opposite);
	RUN_TEST(test_lighting_camera_in_reflection_vector);
	RUN_TEST(test_lighting_light_behind_surface);
	RUN_TEST(test_lighting_surface_in_shadow);
	// uncomment at your own risk
	// RUN_TEST(test_print_3d_sphere);
}
