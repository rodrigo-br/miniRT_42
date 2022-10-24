/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_light_and_shading.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:22:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 13:41:00 by maolivei         ###   ########.fr       */
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

/*
Scenario: Computing the normal on a transformed sphere
Given s ← sphere()
And m ← scaling(1, 0.5, 1) * rotation_z(π/5)
And set_transform(s, m)
When n ← normal_at(s, point(0, √2/2, -√2/2))
Then n = vector(0, 0.97014, -0.24254)
*/
// void	test_normalat_scaled_sphere(void)
// {
// 	t_object	*sphere;
// 	t_vector	*normal;
// 	t_matrix	*scale, *rotate;

// 	sphere = create_sphere();
// 	scale = scale_matrix(1, 0.5, 1);
// 	rotate =
// 	set_transformation(sphere, _matrix(0, 1, 0));
// 	normal = get_sphere_normal(sphere, &(t_point){0, 1.70711, -0.70711, 1});
// 	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0.70711, -0.70711, 0}, normal));
// 	destroy_shape(sphere);
// 	free(normal);
// }

void	test_light_and_shading(void)
{
	RUN_TEST(test_normalat_sphere_x_axis);
	RUN_TEST(test_normalat_sphere_y_axis);
	RUN_TEST(test_normalat_sphere_z_axis);
	RUN_TEST(test_normalat_sphere_nonaxial);
	RUN_TEST(test_normalat_is_normalized);
}
