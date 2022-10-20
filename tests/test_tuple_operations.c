/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tuple_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:24:49 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/20 14:29:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

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
		multiply = scalar_multiply_tuple(a, multiplier);
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
		multiply = scalar_multiply_tuple(a, multiplier);
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
		multiply = scalar_multiply_tuple(a, multiplier);
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
		divide = scalar_divide_tuple(a, divider);
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
		divide = scalar_divide_tuple(a, divider);
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
		divide = scalar_divide_tuple(a, divider);
		TEST_ASSERT_EQUAL_DOUBLE((rand_x / divider), divide->x);
		TEST_ASSERT_EQUAL_DOUBLE((rand_y / divider), divide->y);
		TEST_ASSERT_EQUAL_DOUBLE((rand_z / divider), divide->z);
		TEST_ASSERT_EQUAL_DOUBLE((POINT_W / divider), divide->w);
		free(a);
		free(divide);
	}
}

void	test_magnitude(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*a;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		TEST_ASSERT_EQUAL_DOUBLE(
			sqrt((rand_x * rand_x) + (rand_y * rand_y) + (rand_z * rand_z)),
			magnitude(a)
		);
		free(a);
	}
}

void	test_normalize(void)
{
	double		rand_x, rand_y, rand_z;
	t_vector	*a, *normal;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		a = create_vector(rand_x, rand_y, rand_z);
		normal = normalize(a);
		TEST_ASSERT_EQUAL_DOUBLE(1.0, magnitude(normal));
		free(a);
		free(normal);
	}
}

void	test_dot_product(void)
{
	double		rand_xa, rand_ya, rand_za, rand_xb, rand_yb, rand_zb;
	t_vector	*a, *b;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_xa = double_rand();
		rand_ya = double_rand();
		rand_za = double_rand();
		rand_xb = double_rand();
		rand_yb = double_rand();
		rand_zb = double_rand();
		a = create_vector(rand_xa, rand_ya, rand_za);
		b = create_vector(rand_xb, rand_yb, rand_zb);
		TEST_ASSERT_EQUAL_DOUBLE(
			((rand_xa * rand_xb) + (rand_ya * rand_yb) + (rand_za * rand_zb)),
			dot_product(a, b)
		);
		free(a);
		free(b);
	}
}

void	test_cross_product(void)
{
	t_vector	*a, *b, *cross_ab, *cross_ba;

	a = create_vector(1, 2, 3);
	b = create_vector(2, 3, 4);
	cross_ab = cross_product(a, b);
	cross_ba = cross_product(b, a);
	TEST_ASSERT_EQUAL_DOUBLE(-1, cross_ab->x);
	TEST_ASSERT_EQUAL_DOUBLE(2, cross_ab->y);
	TEST_ASSERT_EQUAL_DOUBLE(-1, cross_ab->z);
	TEST_ASSERT_EQUAL_DOUBLE(1, cross_ba->x);
	TEST_ASSERT_EQUAL_DOUBLE(-2, cross_ba->y);
	TEST_ASSERT_EQUAL_DOUBLE(1, cross_ba->z);
	free(a);
	free(b);
	free(cross_ab);
	free(cross_ba);
}

void	test_tuple_operations(void)
{
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
	RUN_TEST(test_magnitude);
	RUN_TEST(test_normalize);
	RUN_TEST(test_dot_product);
	RUN_TEST(test_cross_product);
}
