/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:24:49 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/17 21:08:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity/unity.h"
#include <minirt.h>
#include <time.h>

#define ARBITRARY_X 30
#define ARBITRARY_Y -20
#define ARBITRARY_Z 50
#define ARBITRARY_W 20
#define DOUBLE_RAND_OFFSET 1000000
#define LOOP_ITERATIONS 10

void	is_tuple_value_correct(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*tuple;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_y = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_z = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_w = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		tuple = create_tuple(rand_x, rand_y, rand_z, rand_w);
		TEST_ASSERT_EQUAL_INT(rand_x, tuple->x);
		TEST_ASSERT_EQUAL_INT(rand_y, tuple->y);
		TEST_ASSERT_EQUAL_INT(rand_z, tuple->z);
		TEST_ASSERT_EQUAL_INT(rand_w, tuple->w);
		free(tuple);
	}
}

void	is_point_value_correct(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*point;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_y = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_z = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		point = create_point(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_INT(rand_x, point->x);
		TEST_ASSERT_EQUAL_INT(rand_y, point->y);
		TEST_ASSERT_EQUAL_INT(rand_z, point->z);
		TEST_ASSERT_EQUAL_INT(1, point->w);
		free(point);
	}
}

void	is_vector_value_correct(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*vector;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_y = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_z = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		vector = create_vector(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_INT(rand_x, vector->x);
		TEST_ASSERT_EQUAL_INT(rand_y, vector->y);
		TEST_ASSERT_EQUAL_INT(rand_z, vector->z);
		TEST_ASSERT_EQUAL_INT(0, vector->w);
		free(vector);
	}
}

void	is_point_ending_in_one(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*point;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_y = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_z = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		point = create_point(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_INT(1, point->w);
		free(point);
	}
}

void	is_vector_ending_in_zero(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*vector;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_y = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		rand_z = rand() + ((double)rand() / DOUBLE_RAND_OFFSET);
		vector = create_vector(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_INT(0, vector->w);
		free(vector);
	}
}

void	sum_two_tuples(void)
{
	t_tuple	*a, *b, *sum, *expected;

	a = create_tuple(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z, ARBITRARY_W);
	b = create_tuple(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z, ARBITRARY_W);
	sum = sum_tuple(a, b);
	expected = create_tuple(ARBITRARY_X * 2, ARBITRARY_Y * 2, ARBITRARY_Z * 2, ARBITRARY_W * 2);
	TEST_ASSERT_EQUAL_INT(expected->x, sum->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sum->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sum->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sum->w);
	free(a);
	free(b);
	free(sum);
	free(expected);
}

void	sum_two_vectors(void)
{
	t_vector	*a;
	t_vector	*b;
	t_vector	*sum;
	t_vector	*expected;

	a = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	b = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	sum = sum_tuple(a, b);
	expected = create_vector(ARBITRARY_X * 2, ARBITRARY_Y * 2, ARBITRARY_Z * 2);
	TEST_ASSERT_EQUAL_INT(expected->x, sum->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sum->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sum->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sum->w);
	free(a);
	free(b);
	free(sum);
	free(expected);
}

void	sum_two_points(void)
{
	t_point	*a;
	t_point	*b;
	t_point	*sum;
	t_tuple	*expected;

	a = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	b = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	sum = sum_tuple(a, b);
	expected = create_tuple(ARBITRARY_X * 2, ARBITRARY_Y * 2, ARBITRARY_Z * 2, 2);
	TEST_ASSERT_EQUAL_INT(expected->x, sum->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sum->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sum->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sum->w);
	free(a);
	free(b);
	free(sum);
	free(expected);
}

void	sum_point_and_vector(void)
{
	t_point		*a;
	t_vector	*b;
	t_point		*sum;
	t_point		*expected;

	a = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	b = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	sum = sum_tuple(a, b);
	expected = create_point(ARBITRARY_X * 2, ARBITRARY_Y * 2, ARBITRARY_Z * 2);
	TEST_ASSERT_EQUAL_INT(expected->x, sum->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sum->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sum->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sum->w);
	free(a);
	free(b);
	free(sum);
	free(expected);
}

void	sub_two_tuples(void)
{
	t_tuple	*a;
	t_tuple	*b;
	t_tuple	*sub;
	t_tuple	*expected;

	a = create_tuple(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z, ARBITRARY_W);
	b = create_tuple(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z, ARBITRARY_W);
	sub = sub_tuple(a, b);
	expected = create_tuple(0, 0, 0, 0);
	TEST_ASSERT_EQUAL_INT(expected->x, sub->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sub->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sub->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sub->w);
	free(a);
	free(b);
	free(sub);
	free(expected);
}

void	sub_two_vectors(void)
{
	t_vector	*a;
	t_vector	*b;
	t_vector	*sub;
	t_vector	*expected;

	a = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	b = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	sub = sub_tuple(a, b);
	expected = create_vector(0, 0, 0);
	TEST_ASSERT_EQUAL_INT(expected->x, sub->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sub->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sub->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sub->w);
	free(a);
	free(b);
	free(sub);
	free(expected);
}

void	sub_two_points(void)
{
	t_point	*a;
	t_point	*b;
	t_point	*sub;
	t_tuple	*expected;

	a = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	b = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	sub = sub_tuple(a, b);
	expected = create_tuple(0, 0, 0, 0);
	TEST_ASSERT_EQUAL_INT(expected->x, sub->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sub->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sub->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sub->w);
	free(a);
	free(b);
	free(sub);
	free(expected);
}

void	sub_point_and_vector(void)
{
	t_point		*a;
	t_vector	*b;
	t_point		*sub;
	t_point		*expected;

	a = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	b = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	sub = sub_tuple(a, b);
	expected = create_point(0, 0, 0);
	TEST_ASSERT_EQUAL_INT(expected->x, sub->x);
	TEST_ASSERT_EQUAL_INT(expected->y, sub->y);
	TEST_ASSERT_EQUAL_INT(expected->z, sub->z);
	TEST_ASSERT_EQUAL_INT(expected->w, sub->w);
	free(a);
	free(b);
	free(sub);
	free(expected);
}

void	neg_a_tuple(void)
{
	t_tuple	*a;
	t_tuple	*neg;
	t_tuple *expected;

	a = create_tuple(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z, ARBITRARY_W);
	neg = neg_tuple(a);
	expected = create_tuple(-ARBITRARY_X, -ARBITRARY_Y, -ARBITRARY_Z, -ARBITRARY_W);
	TEST_ASSERT_EQUAL_INT(expected->x, neg->x);
	TEST_ASSERT_EQUAL_INT(expected->y, neg->y);
	TEST_ASSERT_EQUAL_INT(expected->z, neg->z);
	TEST_ASSERT_EQUAL_INT(expected->w, neg->w);
	free(a);
	free(neg);
	free(expected);
}

void	neg_a_point(void)
{
	t_point	*a;
	t_point	*neg;
	t_tuple *expected;

	a = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	neg = neg_tuple(a);
	expected = create_tuple(-ARBITRARY_X, -ARBITRARY_Y, -ARBITRARY_Z, -1);
	TEST_ASSERT_EQUAL_INT(expected->x, neg->x);
	TEST_ASSERT_EQUAL_INT(expected->y, neg->y);
	TEST_ASSERT_EQUAL_INT(expected->z, neg->z);
	TEST_ASSERT_EQUAL_INT(expected->w, neg->w);
	free(a);
	free(neg);
	free(expected);
}

void	neg_a_vector(void)
{
	t_vector	*a;
	t_vector	*neg;
	t_vector *expected;

	a = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	neg = neg_tuple(a);
	expected = create_vector(-ARBITRARY_X, -ARBITRARY_Y, -ARBITRARY_Z);
	TEST_ASSERT_EQUAL_INT(expected->x, neg->x);
	TEST_ASSERT_EQUAL_INT(expected->y, neg->y);
	TEST_ASSERT_EQUAL_INT(expected->z, neg->z);
	TEST_ASSERT_EQUAL_INT(expected->w, neg->w);
	free(a);
	free(neg);
	free(expected);
}

void	test_tuple_operations(void)
{
	srand(time(NULL));
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(is_vector_value_correct);
	RUN_TEST(is_point_value_correct);
	RUN_TEST(is_vector_ending_in_zero);
	RUN_TEST(is_point_ending_in_one);
	RUN_TEST(sum_two_tuples);
	RUN_TEST(sum_two_vectors);
	RUN_TEST(sum_two_points);
	RUN_TEST(sum_point_and_vector);
	RUN_TEST(sub_two_tuples);
	RUN_TEST(sub_two_vectors);
	RUN_TEST(sub_two_points);
	RUN_TEST(sub_point_and_vector);
	RUN_TEST(neg_a_tuple);
	RUN_TEST(neg_a_point);
	RUN_TEST(neg_a_vector);
}
