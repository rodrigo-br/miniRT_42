/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:01 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/21 12:43:32 by maolivei         ###   ########.fr       */
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

void	test_transpose_matrix(void)
{
	double	same[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	double	tpos[MATRIX_MAX][MATRIX_MAX] = {
		{1, 5, 9, 5},
		{2, 6, 8, 4},
		{3, 7, 7, 3},
		{4, 8, 6, 2}
	};
	t_matrix	*m, *transpose, *expected;

	m = create_matrix(4, same);
	transpose = transpose_matrix(m);
	expected = create_matrix(4, tpos);
	TEST_ASSERT_TRUE(is_equal_matrix(transpose, expected));
	free(m);
	free(expected);
	free(transpose);
}

void	test_transpose_identity_matrix(void)
{
	double	idty[MATRIX_MAX][MATRIX_MAX] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	t_matrix	*transpose, *expected;

	expected = create_matrix(4, idty);
	transpose = transpose_matrix(expected);
	TEST_ASSERT_TRUE(is_equal_matrix(transpose, expected));
	free(expected);
	free(transpose);
}

void	test_4x4_submatrix(void)
{
	double	main[MATRIX_MAX][MATRIX_MAX] = {
		{-6, 1, 1, 6},
		{-8, 5, 8, 6},
		{-1, 0, 8, 2},
		{-7, 1, -1 ,1}
	};
	double	expc[MATRIX_MAX][MATRIX_MAX] = {
		{-6, 1, 6},
		{-8, 8, 6},
		{-7, -1 ,1}
	};
	t_matrix	*m, *submatrix, *expected;

	m = create_matrix(4, main);
	submatrix = create_submatrix(m, 2, 1);
	expected = create_matrix(3, expc);
	TEST_ASSERT_TRUE(is_equal_matrix(expected, submatrix));
	free(m);
	free(submatrix);
	free(expected);
}

void	test_3x3_submatrix(void)
{
	double	main[MATRIX_MAX][MATRIX_MAX] = {
		{-1, 5, 0},
		{-3, 2, 7},
		{0, 6, -3}
	};
	double	expc[MATRIX_MAX][MATRIX_MAX] = {
		{-3, 2},
		{0, 6}
	};
	t_matrix	*m, *submatrix, *expected;

	m = create_matrix(3, main);
	submatrix = create_submatrix(m, 0, 2);
	expected = create_matrix(2, expc);
	TEST_ASSERT_TRUE(is_equal_matrix(expected, submatrix));
	free(m);
	free(submatrix);
	free(expected);
}

void	test_minor_hard(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	t_matrix	*matrix, *submatrix;

	matrix = create_matrix(3, aux);
	submatrix = create_submatrix(matrix, 1, 0);
	TEST_ASSERT_EQUAL_DOUBLE(determinant(submatrix), minor(matrix, 1, 0));
	free(matrix);
	free(submatrix);
}

void	test_minor_rand(void)
{
	size_t		i, j;
	double		aux[MATRIX_MAX][MATRIX_MAX];
	t_matrix	*matrix, *submatrix;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			aux[i][j] = double_rand();
	matrix = create_matrix(3, aux);
	submatrix = create_submatrix(matrix, 1, 0);
	TEST_ASSERT_EQUAL_DOUBLE(determinant(submatrix), minor(matrix, 1, 0));
	free(matrix);
	free(submatrix);
}

void	test_cofactor_hard(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	t_matrix	*matrix;

	matrix = create_matrix(3, aux);
	TEST_ASSERT_EQUAL_DOUBLE(minor(matrix, 0, 0), cofactor(matrix, 0, 0));
	TEST_ASSERT_EQUAL_DOUBLE(minor(matrix, 1, 0), -cofactor(matrix, 1, 0));
	free(matrix);
}

void	test_cofactor_rand(void)
{
	size_t		i, j;
	double		aux[MATRIX_MAX][MATRIX_MAX];
	t_matrix	*matrix;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			aux[i][j] = double_rand();
	matrix = create_matrix(3, aux);
	TEST_ASSERT_EQUAL_DOUBLE(minor(matrix, 0, 0), cofactor(matrix, 0, 0));
	TEST_ASSERT_EQUAL_DOUBLE(minor(matrix, 1, 0), -cofactor(matrix, 1, 0));
	free(matrix);
}

void	test_2x2_determinant(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{1, 5},
		{-3, 2}
	};
	t_matrix	*m;

	m = create_matrix(2, aux);
	TEST_ASSERT_EQUAL(17, determinant(m));
	free(m);
}

void	test_3x3_determinant(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{1, 2, 6},
		{-5, 8, -4},
		{2, 6, 4}
	};
	t_matrix	*m;

	m = create_matrix(3, aux);
	TEST_ASSERT_EQUAL(-196, determinant(m));
	free(m);
}

void	test_4x4_determinant(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{-2, -8, 3, 5},
		{-3, 1, 7, 3},
		{1, 2, -9, 6},
		{-6, 7, 7, -9}
	};
	t_matrix	*m;

	m = create_matrix(4, aux);
	TEST_ASSERT_EQUAL(-4071, determinant(m));
	free(m);
}

void	test_for_invertability(void)
{
	double	yes[MATRIX_MAX][MATRIX_MAX] = {
		{6, 4, 4, 4},
		{5, 5, 7, 6},
		{4, -9, 3, -7},
		{9, 1, 7, -6}
	};
	double	no[MATRIX_MAX][MATRIX_MAX] = {
		{-4, 2, -2, -3},
		{9, 6, 2, 6},
		{0, -5, 1, -5},
		{0, 0, 0, 0}
	};
	t_matrix	*a, *b;

	a = create_matrix(4, yes);
	b = create_matrix(4, no);
	TEST_ASSERT_TRUE(determinant(a));
	TEST_ASSERT_FALSE(determinant(b));
	free(a);
	free(b);
}

void	test_inverse_matrix1(void)
{
	double	main[MATRIX_MAX][MATRIX_MAX] = {
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}
	};
	double	invr[MATRIX_MAX][MATRIX_MAX] = {
		{0.21805, 0.45113, 0.24060, -0.04511},
		{-0.80827, -1.45677, -0.44361, 0.52068},
		{-0.07895, -0.22368, -0.05263, 0.19737},
		{-0.52256, -0.81391, -0.30075, 0.30639}
	};
	t_matrix	*a, *b, *expected;

	a = create_matrix(4, main);
	b = inverse_matrix(a);
	expected = create_matrix(4, invr);
	TEST_ASSERT_TRUE(is_equal_matrix(expected, b));
	TEST_ASSERT_EQUAL_DOUBLE(532, determinant(a));
	TEST_ASSERT_EQUAL_DOUBLE(-160, cofactor(a, 2, 3));
	TEST_ASSERT_EQUAL_DOUBLE((cofactor(a, 2, 3) / determinant(a)), b->matrix[3][2]);
	TEST_ASSERT_EQUAL_DOUBLE(105, cofactor(a, 3, 2));
	TEST_ASSERT_EQUAL_DOUBLE((cofactor(a, 3, 2) / determinant(a)), b->matrix[2][3]);
	free(a);
	free(b);
	free(expected);
}

void	test_inverse_matrix2(void)
{
	double	main[MATRIX_MAX][MATRIX_MAX] = {
		{ 8, -5, 9, 2 },
		{ 7, 5, 6, 1 },
		{ -6, 0, 9, 6 },
		{ -3, 0, -9, -4 }
	};
	double	invr[MATRIX_MAX][MATRIX_MAX] = {
		{ -0.15385, -0.15385, -0.28205, -0.53846 },
		{ -0.07692, 0.12308, 0.02564, 0.03077 },
		{ 0.35897, 0.35897, 0.43590, 0.92308 },
		{ -0.69231, -0.69231, -0.76923, -1.92308 }
	};
	t_matrix	*a, *b, *expected;

	a = create_matrix(4, main);
	b = inverse_matrix(a);
	expected = create_matrix(4, invr);
	TEST_ASSERT_TRUE(is_equal_matrix(expected, b));
	free(a);
	free(b);
	free(expected);
}

void	test_inverse_matrix3(void)
{
	double	main[MATRIX_MAX][MATRIX_MAX] = {
		{ 9, 3, 0, 9 },
		{ -5, -2, -6, -3 },
		{ -4, 9, 6, 4 },
		{ -7, 6, 6, 2 }
	};
	double	invr[MATRIX_MAX][MATRIX_MAX] = {
		{ -0.04074, -0.07778, 0.14444, -0.22222 },
		{ -0.07778, 0.03333, 0.36667, -0.33333 },
		{ -0.02901, -0.14630, -0.10926, 0.12963 },
		{ 0.17778, 0.06667, -0.26667, 0.33333 }
	};
	t_matrix	*a, *b, *expected;

	a = create_matrix(4, main);
	b = inverse_matrix(a);
	expected = create_matrix(4, invr);
	TEST_ASSERT_TRUE(is_equal_matrix(expected, b));
	free(a);
	free(b);
	free(expected);
}

void	test_inverse_matrix4(void)
{
	double	aux[MATRIX_MAX][MATRIX_MAX] = {
		{-4, 2, -2, -3},
		{9, 6, 2, 6},
		{0, -5, 1, -5},
		{0, 0, 0, 0}
	};
	t_matrix	*a, *b;

	a = create_matrix(4, aux);
	b = inverse_matrix(a);
	TEST_ASSERT_NULL(b);
	free(a);
}

void	test_inverse_matrix5(void)
{
	double	auxa[MATRIX_MAX][MATRIX_MAX] = {
		{ 3, -9, 7, 3 },
		{ 3, -8, 2, -9 },
		{ -4, 4, 4, 1 },
		{ -6, 5, -1, 1 },
	};
	double	auxb[MATRIX_MAX][MATRIX_MAX] = {
		{ 8, 2, 2, 2 },
		{ 3, -1, 7, 0 },
		{ 7, 0, 5, 4 },
		{ 6, -2, 0, 5 }
	};
	t_matrix	*a, *b, *multiply, *inverse, *expected;

	a = create_matrix(4, auxa);
	b = create_matrix(4, auxb);
	multiply = multiply_matrix(a, b);
	inverse = inverse_matrix(b);
	expected = multiply_matrix(multiply, inverse);
	TEST_ASSERT_TRUE(is_equal_matrix(a, expected));
	free(a);
	free(b);
	free(multiply);
	free(inverse);
	free(expected);
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
	RUN_TEST(test_transpose_matrix);
	RUN_TEST(test_transpose_identity_matrix);
	RUN_TEST(test_4x4_submatrix);
	RUN_TEST(test_3x3_submatrix);
	RUN_TEST(test_minor_hard);
	RUN_TEST(test_minor_rand);
	RUN_TEST(test_cofactor_hard);
	RUN_TEST(test_cofactor_rand);
	RUN_TEST(test_2x2_determinant);
	RUN_TEST(test_3x3_determinant);
	RUN_TEST(test_4x4_determinant);
	RUN_TEST(test_for_invertability);
	RUN_TEST(test_inverse_matrix1);
	RUN_TEST(test_inverse_matrix2);
	RUN_TEST(test_inverse_matrix3);
	RUN_TEST(test_inverse_matrix4);
	RUN_TEST(test_inverse_matrix5);
}
