/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:09:33 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 11:58:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

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
	n1 = cyl->get_normal(cyl, &(t_point){1, 0, 0, 1});
	n2 = cyl->get_normal(cyl, &(t_point){0, 5, -1, 1});
	n3 = cyl->get_normal(cyl, &(t_point){0, -2, 1, 1});
	n4 = cyl->get_normal(cyl, &(t_point){-1, 1, 0, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){1, 0, 0, 0}, n1));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, -1, 0}, n2));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, 1, 0}, n3));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){-1, 0, 0, 0}, n4));
	destroy_shape(cyl);
	free(n1); free(n2); free(n3); free(n4);
}

void	test_cylinder(void)
{
	RUN_TEST(test_ray_misses_cylinder);
	RUN_TEST(test_ray_strikes_cylinder);
	RUN_TEST(test_get_cylinder_normal);
}
