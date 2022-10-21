/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:01 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/21 08:57:15 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	print_matrix(t_matrix *m)
{
	size_t	i, j;

	for (i = 0; i < m->size; i++)
	{
		for (j = 0; j < m->size; j++)
		{
			printf("{ %5.1f } ", m->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void	test_4x4_matrix(void)
{
	size_t		i, j;
	double		m[MATRIX_MAX][MATRIX_MAX];
	t_matrix	*matrix;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			m[i][j] = double_rand();
	matrix = create_matrix(4, m);
	TEST_ASSERT_NOT_NULL(matrix);
	TEST_ASSERT_TRUE(matrix->size);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], matrix->matrix[i][j]);
	free(matrix);
}

void	test_3x3_matrix(void)
{
	size_t		i, j;
	double		m[MATRIX_MAX][MATRIX_MAX];
	t_matrix	*matrix;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			m[i][j] = double_rand();
	matrix = create_matrix(3, m);
	TEST_ASSERT_NOT_NULL(matrix);
	TEST_ASSERT_TRUE(matrix->size);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], matrix->matrix[i][j]);
	free(matrix);
}

void	test_2x2_matrix(void)
{
	size_t		i, j;
	double		m[MATRIX_MAX][MATRIX_MAX];
	t_matrix	*matrix;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			m[i][j] = double_rand();
	matrix = create_matrix(2, m);
	TEST_ASSERT_NOT_NULL(matrix);
	TEST_ASSERT_TRUE(matrix->size);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			TEST_ASSERT_EQUAL_DOUBLE(m[i][j], matrix->matrix[i][j]);
	free(matrix);
}

void	test_4x4_matrix_equality(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	double	diff[MATRIX_MAX][MATRIX_MAX] = {
		{2, 3, 4, 5},
		{6, 7, 8, 9},
		{8, 7, 6, 5},
		{4, 3, 2, 1}
	};
	t_matrix	*a, *b, *c;

	a = create_matrix(4, same);
	b = create_matrix(4, same);
	c = create_matrix(4, diff);
	TEST_ASSERT_TRUE((a->size == b->size) && (b->size == c->size) && (c->size == a->size));
	TEST_ASSERT_TRUE(is_equal_matrix(a, b));
	TEST_ASSERT_FALSE(is_equal_matrix(a, c));
	TEST_ASSERT_FALSE(is_equal_matrix(c, b));
	free(a);
	free(b);
	free(c);
}

void	test_3x3_matrix_equality(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	double	diff[MATRIX_MAX][MATRIX_MAX] = {
		{2, 3, 4},
		{5, 6, 7},
		{8, 9, 0}
	};
	t_matrix	*a, *b, *c;

	a = create_matrix(3, same);
	b = create_matrix(3, same);
	c = create_matrix(3, diff);
	TEST_ASSERT_TRUE((a->size == b->size) && (b->size == c->size) && (c->size == a->size));
	TEST_ASSERT_TRUE(is_equal_matrix(a, b));
	TEST_ASSERT_FALSE(is_equal_matrix(a, c));
	TEST_ASSERT_FALSE(is_equal_matrix(c, b));
	free(a);
	free(b);
	free(c);
}

void	test_2x2_matrix_equality(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2},
		{4, 5}
	};
	double	diff[MATRIX_MAX][MATRIX_MAX] = {
		{2, 3},
		{5, 6}
	};
	t_matrix	*a, *b, *c;

	a = create_matrix(2, same);
	b = create_matrix(2, same);
	c = create_matrix(2, diff);
	TEST_ASSERT_TRUE((a->size == b->size) && (b->size == c->size) && (c->size == a->size));
	TEST_ASSERT_TRUE(is_equal_matrix(a, b));
	TEST_ASSERT_FALSE(is_equal_matrix(a, c));
	TEST_ASSERT_FALSE(is_equal_matrix(c, b));
	free(a);
	free(b);
	free(c);
}

void	test_multiply_4x4_matrix(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	double	diff[MATRIX_MAX][MATRIX_MAX] = {
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	};
	double	expc[MATRIX_MAX][MATRIX_MAX] = {
		{20, 22, 50, 48},
		{44, 54, 114, 108},
		{40, 58, 110, 102},
		{16, 26, 46, 42}
	};
	t_matrix	*a, *b, *multiply, *expected;

	a = create_matrix(4, same);
	b = create_matrix(4, diff);
	expected = create_matrix(4, expc);
	multiply = multiply_matrix(a, b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, expected));
	free(a);
	free(b);
	free(expected);
	free(multiply);
}

void	test_multiply_3x3_matrix(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3},
		{5, 6, 7},
		{9, 8, 7}
	};
	double	diff[MATRIX_MAX][MATRIX_MAX] = {
		{-2, 1, 2},
		{3, 2, 1},
		{4, 3, 6}
	};
	double	expc[MATRIX_MAX][MATRIX_MAX] = {
		{16, 14, 22},
		{36, 38, 58},
		{34, 46, 68}
	};
	t_matrix	*a, *b, *multiply, *expected;

	a = create_matrix(3, same);
	b = create_matrix(3, diff);
	expected = create_matrix(3, expc);
	multiply = multiply_matrix(a, b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, expected));
	free(a);
	free(b);
	free(expected);
	free(multiply);
}

void	test_multiply_2x2_matrix(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2},
		{5, 6}
	};
	double	diff[MATRIX_MAX][MATRIX_MAX] = {
		{-2, 1},
		{3, 2}
	};
	double	expc[MATRIX_MAX][MATRIX_MAX] = {
		{4, 5},
		{8, 17}
	};
	t_matrix	*a, *b, *multiply, *expected;

	a = create_matrix(2, same);
	b = create_matrix(2, diff);
	expected = create_matrix(2, expc);
	multiply = multiply_matrix(a, b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, expected));
	free(a);
	free(b);
	free(expected);
	free(multiply);
}

void	test_multiply_matrix_tuple(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}
	};
	t_matrix	*m;
	t_tuple		*t, *expected, *multiply;

	m = create_matrix(4, aux);
	t = create_tuple(1, 2, 3, 1);
	expected = create_tuple(18, 24, 33, 1);
	multiply = multiply_matrix_tuple(m, t);
	TEST_ASSERT_TRUE(is_equal_tuple(multiply, expected));
	free(m);
	free(t);
	free(expected);
	free(multiply);
}

void	test_multiply_identity_matrix(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	t_matrix	*a, *b, *multiply;

	a = create_matrix(4, aux);
	b = create_identity_matrix();
	multiply = multiply_matrix(a, b);
	TEST_ASSERT_TRUE(is_equal_matrix(multiply, a));
	free(a);
	free(b);
	free(multiply);
}

void	test_multiply_identity_matrix_tuple(void)
{
	t_matrix	*m;
	t_tuple		*t, *multiply;

	m = create_identity_matrix();
	t = create_tuple(1, 2, 3, 4);
	multiply = multiply_matrix_tuple(m, t);
	TEST_ASSERT_TRUE(is_equal_tuple(multiply, t));
	free(m);
	free(t);
	free(multiply);
}

void	test_matrix(void)
{
	RUN_TEST(test_4x4_matrix);
	RUN_TEST(test_3x3_matrix);
	RUN_TEST(test_2x2_matrix);
	RUN_TEST(test_4x4_matrix_equality);
	RUN_TEST(test_3x3_matrix_equality);
	RUN_TEST(test_2x2_matrix_equality);
	RUN_TEST(test_multiply_4x4_matrix);
	RUN_TEST(test_multiply_3x3_matrix);
	RUN_TEST(test_multiply_2x2_matrix);
	RUN_TEST(test_multiply_matrix_tuple);
	RUN_TEST(test_multiply_identity_matrix);
	RUN_TEST(test_multiply_identity_matrix_tuple);
}
