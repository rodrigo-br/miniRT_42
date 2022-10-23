/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:00:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 19:20:53 by maolivei         ###   ########.fr       */
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
	free(origin); free(direction); free(ray);
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
		free(origin); free(direction); free(ray);
	}
}

void	test_position_hard(void)
{
	t_ray	*ray;
	t_point	*e1, *e2, *e3, *e4;
	t_point	*p1, *p2, *p3, *p4;

	ray = create_ray(create_point(2, 3, 4), create_vector(1, 0, 0));
	p1 = position(ray, 0);
	p2 = position(ray, 1);
	p3 = position(ray, -1);
	p4 = position(ray, 2.5);
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
	free(ray->origin); free(ray->direction); free(ray);
}

void	test_sphere_creation(void)
{
	t_object	*sphere;

	sphere = create_sphere();
	TEST_ASSERT_NOT_NULL(sphere);
	TEST_ASSERT_TRUE(sphere->type == ID_SPHERE); free(sphere);
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
	free(ray->origin); free(ray->direction); free(ray); free(sphere);
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
	free(ray->origin); free(ray->direction); free(ray); free(sphere);
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
	free(ray->origin); free(ray->direction); free(ray); free(sphere);
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
	free(ray->origin); free(ray->direction); free(ray); free(sphere);
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
	free(ray->origin); free(ray->direction); free(ray); free(sphere);
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
	free(sphere); free(intersection);
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
	h = hit(xslist);
	TEST_ASSERT_NOT_NULL(h);
	TEST_ASSERT_EQUAL(1, h->time);
	free(sphere);
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
	h = hit(xslist);
	TEST_ASSERT_NOT_NULL(h);
	TEST_ASSERT_EQUAL(42, h->time);
	free(sphere);
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
	h = hit(xslist);
	TEST_ASSERT_NULL(h);
	free(sphere);
	intersection_list_clear(&xslist);
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
}
