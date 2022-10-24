/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_light_and_shading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:22:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:41:43 by maolivei         ###   ########.fr       */
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
	set_transformation(sphere, translate_matrix(0, 1, 0));
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
	set_transformation(sphere, multiply_matrix(scale, rotate));
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
	TEST_ASSERT_EQUAL(1, light_point->intensity->red);
	TEST_ASSERT_EQUAL(1, light_point->intensity->green);
	TEST_ASSERT_EQUAL(1, light_point->intensity->blue);
	destroy_light_point(light_point);
}

void	test_create_material(void)
{
	t_material	*material;

	material = create_material();
	TEST_ASSERT_NOT_NULL(material);
	TEST_ASSERT_EQUAL(1, material->color->red);
	TEST_ASSERT_EQUAL(1, material->color->green);
	TEST_ASSERT_EQUAL(1, material->color->blue);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, material->ambient);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, material->diffuse);
	TEST_ASSERT_EQUAL_DOUBLE(0.9, material->specular);
	TEST_ASSERT_EQUAL_DOUBLE(200.0, material->shininess);
	destroy_material(material);
}

void	test_lighting_between_light_and_surface(void)
{
	t_material	*material;
	t_lightattr	args;
	t_rgb		*result;

	material = create_material();
	args.light_point = create_light_point(create_point(0, 0, -10), create_color(1, 1, 1));
	args.position = create_point(0, 0, 0);
	args.camera = create_vector(0, 0, -1);
	args.normal = create_vector(0, 0, -1);
	result = lighting(&args, material);
	TEST_ASSERT_EQUAL(1.9, result->red);
	TEST_ASSERT_EQUAL(1.9, result->green);
	TEST_ASSERT_EQUAL(1.9, result->blue);
	destroy_material(material);
	destroy_light_point(args.light_point);
	free(result);
	TEST_ASSERT_NOT_NULL(result);

}

void	test_lighting_camera_offset_45deg(void)
{
	t_material	*material;
	t_lightattr	args;
	t_rgb		*result;

	material = create_material();
	args.light_point = create_light_point(create_point(0, 0, -10), create_color(1, 1, 1));
	args.position = create_point(0, 0, 0);
	args.camera = create_vector(0, sqrt(2)/2, -sqrt(2)/2);
	args.normal = create_vector(0, 0, -1);
	result = lighting(&args, material);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_EQUAL(1.0, result->red);
	TEST_ASSERT_EQUAL(1.0, result->green);
	TEST_ASSERT_EQUAL(1.0, result->blue);
	destroy_material(material);
	destroy_light_point(args.light_point);
	free(result);
}

void	test_lighting_light_offset_45deg_and_camera_opposite(void)
{
	t_material	*material;
	t_lightattr	args;
	t_rgb		*result;

	material = create_material();
	args.light_point = create_light_point(create_point(0, 10, -10), create_color(1, 1, 1));
	args.position = create_point(0, 0, 0);
	args.camera = create_vector(0, 0, -1);
	args.normal = create_vector(0, 0, -1);
	result = lighting(&args, material);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_EQUAL(0.7364, result->red);
	TEST_ASSERT_EQUAL(0.7364, result->green);
	TEST_ASSERT_EQUAL(0.7364, result->blue);
	destroy_material(material);
	destroy_light_point(args.light_point);
	free(result);
}

void	test_lighting_camera_in_reflection_vector(void)
{
	t_material	*material;
	t_lightattr	args;
	t_rgb		*result;

	material = create_material();
	args.light_point = create_light_point(create_point(0, 10, -10), create_color(1, 1, 1));
	args.position = create_point(0, 0, 0);
	args.camera = create_vector(0, -sqrt(2)/2, -sqrt(2)/2);
	args.normal = create_vector(0, 0, -1);
	result = lighting(&args, material);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_EQUAL(1.6364, result->red);
	TEST_ASSERT_EQUAL(1.6364, result->green);
	TEST_ASSERT_EQUAL(1.6364, result->blue);
	destroy_material(material);
	destroy_light_point(args.light_point);
	free(result);
}

void	test_lighting_light_behind_surface(void)
{
	t_material	*material;
	t_lightattr	args;
	t_rgb		*result;

	material = create_material();
	args.light_point = create_light_point(create_point(0, 0, 10), create_color(1, 1, 1));
	args.position = create_point(0, 0, 0);
	args.camera = create_vector(0, 0, -1);
	args.normal = create_vector(0, 0, -1);
	result = lighting(&args, material);
	TEST_ASSERT_NOT_NULL(result);
	TEST_ASSERT_EQUAL(0.1, result->red);
	TEST_ASSERT_EQUAL(0.1, result->green);
	TEST_ASSERT_EQUAL(0.1, result->blue);
	destroy_material(material);
	destroy_light_point(args.light_point);
	free(result);
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
}
