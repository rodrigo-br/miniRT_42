/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:09:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 22:11:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	test_cylinder_creation(void)
{
	t_object	*cyl;

	cyl = create_cylinder();
	TEST_ASSERT_NOT_NULL(cyl);
	TEST_ASSERT_EQUAL_DOUBLE(1.0, cyl->cylinder.diameter);
	TEST_ASSERT_EQUAL_DOUBLE(-INFINITY, cyl->cylinder.min);
	TEST_ASSERT_EQUAL_DOUBLE(INFINITY, cyl->cylinder.max);
	TEST_ASSERT_TRUE(cyl->cylinder.capped);
	destroy_shape(cyl);
}

/* Scenario Outline: A ray misses a cylinder
Given cyl ← cylinder()
And direction ← normalize(<direction>)
And r ← ray(<origin>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = 0
Examples:
| origin          | direction       |
| point(1, 0, 0)  | vector(0, 1, 0) |
| point(0, 0, 0)  | vector(0, 1, 0) |
| point(0, 0, -5) | vector(1, 1, 1) | */
void	test_ray_misses_cylinder(void)
{
	t_object	*cyl;
	t_vector	*d1, *d2, *d3;
	t_point		*o1, *o2, *o3;
	t_ray		*r1, *r2, *r3;
	t_intersect	*xs = NULL;

	cyl = create_cylinder();
	o1 = create_point(1, 0, 0);
	o2 = create_point(0, 0, 0);
	o3 = create_point(0, 0, -5);
	d1 = normalize(&(t_vector){0, 1, 0, 0});
	d2 = normalize(&(t_vector){0, 1, 0, 0});
	d3 = normalize(&(t_vector){1, 1, 1, 0});
	r1 = create_ray(o1, d1);
	r2 = create_ray(o2, d2);
	r3 = create_ray(o3, d3);
	cyl->intersect(cyl, r1, &xs);
	cyl->intersect(cyl, r2, &xs);
	cyl->intersect(cyl, r3, &xs);
	TEST_ASSERT_NULL(xs);
	TEST_ASSERT_EQUAL(0, intersection_list_size(xs));
	destroy_ray(r1);
	destroy_ray(r2);
	destroy_ray(r3);
	destroy_shape(cyl);
	intersection_list_clear(&xs);
}

/* Scenario Outline: A ray strikes a cylinder
Given cyl ← cylinder()
And direction ← normalize(<direction>)
And r ← ray(<origin>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = 2
And xs[0].t = <t0>
And xs[1].t = <t1>
Examples:
| origin            | direction         | t0      | t1      |
| point(1, 0, -5)   | vector(0, 0, 1)   | 5       | 5       |
| point(0, 0, -5)   | vector(0, 0, 1)   | 4       | 6       |
| point(0.5, 0, -5) | vector(0.1, 1, 1) | 6.80798 | 7.08872 | */
void	test_ray_strikes_cylinder(void)
{
	t_object	*cyl;
	t_vector	*d1, *d2, *d3;
	t_point		*o1, *o2, *o3;
	t_ray		*r1, *r2, *r3;
	t_intersect	*xs = NULL;

	cyl = create_cylinder();
	o1 = create_point(1, 0, -5);
	o2 = create_point(0, 0, -5);
	o3 = create_point(0.5, 0, -5);
	d1 = normalize(&(t_vector){0, 0, 1, 0});
	d2 = normalize(&(t_vector){0, 0, 1, 0});
	d3 = normalize(&(t_vector){0.1, 1, 1, 0});
	r1 = create_ray(o1, d1);
	r2 = create_ray(o2, d2);
	r3 = create_ray(o3, d3);
	cyl->intersect(cyl, r1, &xs);
	cyl->intersect(cyl, r2, &xs);
	cyl->intersect(cyl, r3, &xs);
	TEST_ASSERT_NOT_NULL(xs);
	TEST_ASSERT_EQUAL(5, intersection_list_size(xs));
	TEST_ASSERT_TRUE(is_equal_double(4.0, xs->time));
	TEST_ASSERT_TRUE(is_equal_double(5.0, xs->next->time));
	TEST_ASSERT_TRUE(is_equal_double(6.0, xs->next->next->time));
	TEST_ASSERT_TRUE(is_equal_double(6.80798, xs->next->next->next->time));
	TEST_ASSERT_TRUE(is_equal_double(7.08872, xs->next->next->next->next->time));
	destroy_ray(r1);
	destroy_ray(r2);
	destroy_ray(r3);
	destroy_shape(cyl);
	intersection_list_clear(&xs);
}

/* Scenario Outline: Normal vector on a cylinder
Given cyl ← cylinder()
When n ← local_normal_at(cyl, <point>)
Then n = <normal>
Examples:
| point           | normal           |
| point(1, 0, 0)  | vector(1, 0, 0)  |
| point(0, 5, -1) | vector(0, 0, -1) |
| point(0, -2, 1) | vector(0, 0, 1)  |
| point(-1, 1, 0) | vector(-1, 0, 0) | */
void	test_get_cylinder_normal(void)
{
	t_object	*cyl;
	t_vector	*n1, *n2, *n3, *n4;

	cyl = create_cylinder();
	n1 = normal_at(cyl, &(t_point){1, 0, 0, 1});
	n2 = normal_at(cyl, &(t_point){0, 5, -1, 1});
	n3 = normal_at(cyl, &(t_point){0, -2, 1, 1});
	n4 = normal_at(cyl, &(t_point){-1, 1, 0, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){1, 0, 0, 0}, n1));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, -1, 0}, n2));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, 1, 0}, n3));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){-1, 0, 0, 0}, n4));
	destroy_shape(cyl);
	free(n1); free(n2); free(n3); free(n4);
}

/* Scenario Outline: Intersecting a constrained cylinder
Given cyl ← cylinder()
And cyl.minimum ← 1
And cyl.maximum ← 2
And direction ← normalize(<direction>)
And r ← ray(<point>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = <count>
Examples:
|   | point             | direction         | count |
| 1 | point(0, 1.5, 0)  | vector(0.1, 1, 0) | 0     |
| 2 | point(0, 3, -5)   | vector(0, 0, 1)   | 0     |
| 3 | point(0, 0, -5)   | vector(0, 0, 1)   | 0     |
| 4 | point(0, 2, -5)   | vector(0, 0, 1)   | 0     |
| 5 | point(0, 1, -5)   | vector(0, 0, 1)   | 0     |
| 6 | point(0, 1.5, -2) | vector(0, 0, 1)   | 2     | */
void	test_intersect_truncated_cylinder(void)
{
	t_object	*cyl;
	t_vector	*d1, *d2, *d3, *d4, *d5, *d6;
	t_point		*o1, *o2, *o3, *o4, *o5, *o6;
	t_ray		*r1, *r2, *r3, *r4, *r5, *r6;
	t_intersect	*xs = NULL;

	cyl = create_cylinder();
	cyl->cylinder.min = 1;
	cyl->cylinder.max = 2;
	cyl->cylinder.capped = FALSE;
	o1 = create_point(0, 1.5, 0);
	o2 = create_point(0, 3, -5);
	o3 = create_point(0, 0, -5);
	o4 = create_point(0, 2, -5);
	o5 = create_point(0, 1, -5);
	o6 = create_point(0, 1.5, -2);
	d1 = normalize(&(t_vector){0.1, 1, 0, 0});
	d2 = normalize(&(t_vector){0, 0, 1, 0});
	d3 = normalize(&(t_vector){0, 0, 1, 0});
	d4 = normalize(&(t_vector){0, 0, 1, 0});
	d5 = normalize(&(t_vector){0, 0, 1, 0});
	d6 = normalize(&(t_vector){0, 0, 1, 0});
	r1 = create_ray(o1, d1);
	r2 = create_ray(o2, d2);
	r3 = create_ray(o3, d3);
	r4 = create_ray(o4, d4);
	r5 = create_ray(o5, d5);
	r6 = create_ray(o6, d6);
	cyl->intersect(cyl, r1, &xs);
	cyl->intersect(cyl, r2, &xs);
	cyl->intersect(cyl, r3, &xs);
	cyl->intersect(cyl, r4, &xs);
	cyl->intersect(cyl, r5, &xs);
	cyl->intersect(cyl, r6, &xs);
	TEST_ASSERT_NOT_NULL(xs);
	TEST_ASSERT_EQUAL(2, intersection_list_size(xs));
	destroy_ray(r1);
	destroy_ray(r2);
	destroy_ray(r3);
	destroy_ray(r4);
	destroy_ray(r5);
	destroy_ray(r6);
	destroy_shape(cyl);
	intersection_list_clear(&xs);
}

/* Scenario Outline: Intersecting the caps of a closed cylinder
Given cyl ← cylinder()
And cyl.minimum ← 1
And cyl.maximum ← 2
And cyl.closed ← true
And direction ← normalize(<direction>)
And r ← ray(<point>, direction)
When xs ← local_intersect(cyl, r)
Then xs.count = <count>
Examples:
|   | point            | direction        | count |
| 1 | point(0, 3, 0)   | vector(0, -1, 0) | 2     |
| 2 | point(0, 3, -2)  | vector(0, -1, 2) | 2     |
| 3 | point(0, 4, -2)  | vector(0, -1, 1) | 2     | # corner case
| 4 | point(0, 0, -2)  | vector(0, 1, 2)  | 2     |
| 5 | point(0, -1, -2) | vector(0, 1, 1)  | 2     | # corner case */
void	test_intersect_cylinder_caps(void)
{
	t_object	*cyl;
	t_vector	*d1, *d2, *d3, *d4, *d5;
	t_point		*o1, *o2, *o3, *o4, *o5;
	t_ray		*r1, *r2, *r3, *r4, *r5;
	t_intersect	*xs = NULL;

	cyl = create_cylinder();
	cyl->cylinder.min = 1;
	cyl->cylinder.max = 2;
	o1 = create_point(0, 3, 0);
	o2 = create_point(0, 3, -2);
	o3 = create_point(0, 4, -2);
	o4 = create_point(0, 0, -2);
	o5 = create_point(0, -1, -2);
	d1 = normalize(&(t_vector){0, -1, 0, 0});
	d2 = normalize(&(t_vector){0, -1, 2, 0});
	d3 = normalize(&(t_vector){0, -1, 1, 0});
	d4 = normalize(&(t_vector){0, 1, 2, 0});
	d5 = normalize(&(t_vector){0, 1, 1, 0});
	r1 = create_ray(o1, d1);
	r2 = create_ray(o2, d2);
	r3 = create_ray(o3, d3);
	r4 = create_ray(o4, d4);
	r5 = create_ray(o5, d5);
	cyl->intersect(cyl, r1, &xs);
	cyl->intersect(cyl, r2, &xs);
	cyl->intersect(cyl, r3, &xs);
	cyl->intersect(cyl, r4, &xs);
	cyl->intersect(cyl, r5, &xs);
	TEST_ASSERT_NOT_NULL(xs);
	TEST_ASSERT_EQUAL(10, intersection_list_size(xs));
	destroy_ray(r1);
	destroy_ray(r2);
	destroy_ray(r3);
	destroy_ray(r4);
	destroy_ray(r5);
	destroy_shape(cyl);
	intersection_list_clear(&xs);
}

/*
Scenario Outline: The normal vector on a cylinder's end caps
Given cyl ← cylinder()
And cyl.minimum ← 1
And cyl.maximum ← 2
And cyl.closed ← true
When n ← local_normal_at(cyl, <point>)
Then n = <normal>
Examples:
| point            | normal           |
| point(0, 1, 0)   | vector(0, -1, 0) |
| point(0.5, 1, 0) | vector(0, -1, 0) |
| point(0, 1, 0.5) | vector(0, -1, 0) |
| point(0, 2, 0)   | vector(0, 1, 0)  |
| point(0.5, 2, 0) | vector(0, 1, 0)  |
| point(0, 2, 0.5) | vector(0, 1, 0)  | */
void	test_get_cylinder_caps_normal(void)
{
	t_object	*cyl;
	t_vector	*n1, *n2, *n3, *n4, *n5, *n6;

	cyl = create_cylinder();
	cyl->cylinder.min = 1;
	cyl->cylinder.max = 2;
	n1 = normal_at(cyl, &(t_point){0, 1, 0, 1});
	n2 = normal_at(cyl, &(t_point){0.5, 1, 0, 1});
	n3 = normal_at(cyl, &(t_point){0, 1, 0.5, 1});
	n4 = normal_at(cyl, &(t_point){0, 2, 0, 1});
	n5 = normal_at(cyl, &(t_point){0.5, 2, 0, 1});
	n6 = normal_at(cyl, &(t_point){0, 2, 0.5, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, -1, 0, 0}, n1));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, -1, 0, 0}, n2));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, -1, 0, 0}, n3));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, n4));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, n5));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, n6));
	destroy_shape(cyl);
	free(n1); free(n2); free(n3); free(n4); free(n5); free(n6);
}

void	test_cylinder(void)
{
	RUN_TEST(test_cylinder_creation);
	RUN_TEST(test_ray_misses_cylinder);
	RUN_TEST(test_ray_strikes_cylinder);
	RUN_TEST(test_get_cylinder_normal);
	RUN_TEST(test_intersect_truncated_cylinder);
	RUN_TEST(test_intersect_cylinder_caps);
	RUN_TEST(test_get_cylinder_caps_normal);
}
