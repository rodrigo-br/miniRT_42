/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:24:49 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/18 14:07:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity/unity.h"
#include <minirt.h>
#include <time.h>

#define DOUBLE_RAND_OFFSET 1000000
#define LOOP_ITERATIONS 100

double double_rand()
{
	return (rand() + ((double)rand() / DOUBLE_RAND_OFFSET));
}

void	is_tuple_value_correct(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*tuple;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		tuple = create_tuple(rand_x, rand_y, rand_z, rand_w);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x, tuple->x);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y, tuple->y);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z, tuple->z);
		TEST_ASSERT_EQUAL_DOUBLE(rand_w, tuple->w);
		free(tuple);
	}
}

void	is_point_value_correct(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*point;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		point = create_point(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x, point->x);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y, point->y);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z, point->z);
		TEST_ASSERT_EQUAL_DOUBLE(POINT_W, point->w);
		free(point);
	}
}

void	is_vector_value_correct(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*vector;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		vector = create_vector(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x, vector->x);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y, vector->y);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z, vector->z);
		TEST_ASSERT_EQUAL_DOUBLE(VECTOR_W, vector->w);
		free(vector);
	}
}

void	is_point_ending_in_one(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*point;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		point = create_point(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_DOUBLE(POINT_W, point->w);
		free(point);
	}
}

void	is_vector_ending_in_zero(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*vector;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		vector = create_vector(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_DOUBLE(VECTOR_W, vector->w);
		free(vector);
	}
}

void	sum_two_tuples(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b, *sum;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		sum = sum_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x + rand_x), sum->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y + rand_y), sum->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z + rand_z), sum->z);
		TEST_ASSERT_EQUAL_DOUBLE((rand_w + rand_w), sum->w);
		free(a);
		free(b);
		free(sum);
	}
}

void	sum_two_vectors(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*a, *b, *sum;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		b = create_vector(rand_x, rand_y, rand_z);
		sum = sum_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x + rand_x), sum->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y + rand_y), sum->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z + rand_z), sum->z);
		TEST_ASSERT_EQUAL_DOUBLE((VECTOR_W + VECTOR_W), sum->w);
		free(a);
		free(b);
		free(sum);
	}
}

void	sum_two_points(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*a, *b, *sum;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		b = create_point(rand_x, rand_y, rand_z);
		sum = sum_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x + rand_x), sum->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y + rand_y), sum->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z + rand_z), sum->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W + POINT_W), sum->w);
		free(a);
		free(b);
		free(sum);
	}
}

void	sum_point_and_vector(void)
{
	double		rand_x, rand_y, rand_z;
	t_point		*a, *sum;
	t_vector	*b;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		b = create_vector(rand_x, rand_y, rand_z);
		sum = sum_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x + rand_x), sum->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y + rand_y), sum->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z + rand_z), sum->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W + VECTOR_W), sum->w);
		free(a);
		free(b);
		free(sum);
	}
}

void	sub_two_tuples(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b, *sub;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		sub = sub_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x - rand_x), sub->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y - rand_y), sub->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z - rand_z), sub->z);
		TEST_ASSERT_EQUAL_DOUBLE((rand_w - rand_w), sub->w);
		free(a);
		free(b);
		free(sub);
	}
}

void	sub_two_vectors(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*a, *b, *sub;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		b = create_vector(rand_x, rand_y, rand_z);
		sub = sub_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x - rand_x), sub->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y - rand_y), sub->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z - rand_z), sub->z);
		TEST_ASSERT_EQUAL_DOUBLE((VECTOR_W - VECTOR_W), sub->w);
		free(a);
		free(b);
		free(sub);
	}
}

void	sub_two_points(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*a, *b, *sub;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		b = create_point(rand_x, rand_y, rand_z);
		sub = sub_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x - rand_x), sub->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y - rand_y), sub->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z - rand_z), sub->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W - POINT_W), sub->w);
		free(a);
		free(b);
		free(sub);
	}
}

void	sub_point_and_vector(void)
{
	double		rand_x, rand_y, rand_z;
	t_point		*a, *sub;
	t_vector	*b;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		b = create_vector(rand_x, rand_y, rand_z);
		sub = sub_tuple(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x - rand_x), sub->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y - rand_y), sub->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z - rand_z), sub->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W - VECTOR_W), sub->w);
		free(a);
		free(b);
		free(sub);
	}
}

void	neg_a_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *neg;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
		neg = neg_tuple(a);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_x, neg->x);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_y, neg->y);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_z, neg->z);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_w, neg->w);
		free(a);
		free(neg);
	}
}

void	neg_a_vector(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*a, *neg;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		neg = neg_tuple(a);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_x, neg->x);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_y, neg->y);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_z, neg->z);
		TEST_ASSERT_EQUAL_DOUBLE(-VECTOR_W, neg->w);
		free(a);
		free(neg);
	}
}

void	neg_a_point(void)
{
	double	rand_x, rand_y, rand_z;
	t_point	*a, *neg;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		neg = neg_tuple(a);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_x, neg->x);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_y, neg->y);
		TEST_ASSERT_EQUAL_DOUBLE(-rand_z, neg->z);
		TEST_ASSERT_EQUAL_DOUBLE(-POINT_W, neg->w);
		free(a);
		free(neg);
	}
}

void	multiply_a_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w, multiplier;
	t_tuple	*a, *multiply;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		multiplier = double_rand();
		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
		multiply = scalar_multiply(a, multiplier);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x * multiplier), multiply->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y * multiplier), multiply->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z * multiplier), multiply->z);
		TEST_ASSERT_EQUAL_DOUBLE((rand_w * multiplier), multiply->w);
		free(a);
		free(multiply);
	}
}

void	multiply_a_vector(void)
{
	double		rand_x, rand_y, rand_z, multiplier;
	t_vector	*a;
	t_tuple		*multiply;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		multiplier = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		multiply = scalar_multiply(a, multiplier);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x * multiplier), multiply->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y * multiplier), multiply->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z * multiplier), multiply->z);
		TEST_ASSERT_EQUAL_DOUBLE((VECTOR_W * multiplier), multiply->w);
		free(a);
		free(multiply);
	}
}

void	multiply_a_point(void)
{
	double	rand_x, rand_y, rand_z, multiplier;
	t_point	*a;
	t_tuple	*multiply;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		multiplier = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		multiply = scalar_multiply(a, multiplier);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x * multiplier), multiply->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y * multiplier), multiply->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z * multiplier), multiply->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W * multiplier), multiply->w);
		free(a);
		free(multiply);
	}
}

void	divide_a_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w, divider;
	t_tuple	*a, *divide;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = double_rand();
		divider = double_rand();
		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
		divide = scalar_divide(a, divider);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x / divider), divide->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y / divider), divide->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z / divider), divide->z);
		TEST_ASSERT_EQUAL_DOUBLE((rand_w / divider), divide->w);
		free(a);
		free(divide);
	}
}

void	divide_a_vector(void)
{
	double		rand_x, rand_y, rand_z, divider;
	t_vector	*a;
	t_tuple		*divide;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		divider = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		divide = scalar_divide(a, divider);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x / divider), divide->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y / divider), divide->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z / divider), divide->z);
		TEST_ASSERT_EQUAL_DOUBLE((VECTOR_W / divider), divide->w);
		free(a);
		free(divide);
	}
}

void	divide_a_point(void)
{
	double	rand_x, rand_y, rand_z, divider;
	t_point	*a;
	t_tuple	*divide;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		divider = double_rand();
		a = create_point(rand_x, rand_y, rand_z);
		divide = scalar_divide(a, divider);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x / divider), divide->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y / divider), divide->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z / divider), divide->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W / divider), divide->w);
		free(a);
		free(divide);
	}
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
	RUN_TEST(neg_a_vector);
	RUN_TEST(neg_a_point);
	RUN_TEST(multiply_a_tuple);
	RUN_TEST(multiply_a_vector);
	RUN_TEST(multiply_a_point);
	RUN_TEST(divide_a_tuple);
	RUN_TEST(divide_a_vector);
	RUN_TEST(divide_a_point);
}
