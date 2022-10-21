#include <minirt.h>
#include "unity/unity.h"
#include <tests.h>


void	translate_point_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = 1;
		a = create_point(rand_x, rand_y, rand_z);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		matrix = translate_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((a->x + b->x), matrix->matrix[0][3]);
		TEST_ASSERT_EQUAL_DOUBLE((a->y + b->y), matrix->matrix[1][3]);
		TEST_ASSERT_EQUAL_DOUBLE((a->z + b->z), matrix->matrix[2][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, rand_w);
		free(a);
		free(b);
		free(matrix);
	}
	/*Scenario: Multiplying by a translation matrix
	Given transform ← translation(5, -3, 2)
	And p ← point(-3, 4, 5)
	Then transform * p = point(2, 1, 7)*/
	a = create_point(-3, 4, 5);
	b = create_tuple(5, -3, 2, 0);
	matrix = translate_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(2, matrix->matrix[0][3]);
	TEST_ASSERT_EQUAL_DOUBLE(1, matrix->matrix[1][3]);
	TEST_ASSERT_EQUAL_DOUBLE(7, matrix->matrix[2][3]);
	TEST_ASSERT_EQUAL_DOUBLE(1, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void inverse_translate_point_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = 1;
		a = create_point(rand_x, rand_y, rand_z);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		matrix = translate_inverse_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((a->x + -b->x), matrix->matrix[0][3]);
		TEST_ASSERT_EQUAL_DOUBLE((a->y + -b->y), matrix->matrix[1][3]);
		TEST_ASSERT_EQUAL_DOUBLE((a->z + -b->z), matrix->matrix[2][3]);
		TEST_ASSERT_EQUAL_DOUBLE((a->w), matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/*Scenario: Multiplying by the inverse of a translation matrix
	Given transform ← translation(5, -3, 2)
	And inv ← inverse(transform)
	And p ← point(-3, 4, 5)
	Then inv * p = point(-8, 7, 3)*/
	a = create_point(-3, 4, 5);
	b = create_tuple(5, -3, 2, 0);
	matrix = translate_inverse_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-8, matrix->matrix[0][3]);
	TEST_ASSERT_EQUAL_DOUBLE(7, matrix->matrix[1][3]);
	TEST_ASSERT_EQUAL_DOUBLE(3, matrix->matrix[2][3]);
	TEST_ASSERT_EQUAL_DOUBLE(1, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void	translate_vector_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = 1;
		a = create_vector(rand_x, rand_y, rand_z);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		matrix = translate_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE(a->x, matrix->matrix[0][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->y, matrix->matrix[1][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->z, matrix->matrix[2][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/*Scenario: Translation does not affect vectors
	Given transform ← translation(5, -3, 2)
	And v ← vector(-3, 4, 5)
	Then transform * v = v*/
	a = create_vector(-3, 4, 5);
	b = create_tuple(5, -3, 2, 0);
	matrix = translate_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-3, matrix->matrix[0][3]);
	TEST_ASSERT_EQUAL_DOUBLE(4, matrix->matrix[1][3]);
	TEST_ASSERT_EQUAL_DOUBLE(5, matrix->matrix[2][3]);
	TEST_ASSERT_EQUAL_DOUBLE(0, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void inverse_translate_vector_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = 1;
		a = create_vector(rand_x, rand_y, rand_z);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		matrix = translate_inverse_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE(a->x, matrix->matrix[0][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->y, matrix->matrix[1][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->z, matrix->matrix[2][3]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/*Scenario: Translation does not affect vectors
	Given transform ← translation(5, -3, 2)
	And v ← vector(-3, 4, 5)
	Then transform * v = v*/
	a = create_vector(-3, 4, 5);
	b = create_tuple(5, -3, 2, 0);
	matrix = translate_inverse_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-3, matrix->matrix[0][3]);
	TEST_ASSERT_EQUAL_DOUBLE(4, matrix->matrix[1][3]);
	TEST_ASSERT_EQUAL_DOUBLE(5, matrix->matrix[2][3]);
	TEST_ASSERT_EQUAL_DOUBLE(0, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void test_scale_matrix_point(void)
{
	double		rand_x, rand_y, rand_z, rand_w;
	double		rand_x2, rand_y2, rand_z2, rand_w2;
	t_tuple		*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_x2 = double_rand();
		rand_y2 = double_rand();
		rand_z2 = double_rand();
		rand_w = 1;
		a = create_point(rand_x, rand_y, rand_z);
		b = create_point(rand_x2, rand_y2, rand_z2);
		matrix = scale_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x * rand_x2, matrix->matrix[0][0]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_x * rand_x2 - 1, matrix->matrix[0][0]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y * rand_y2, matrix->matrix[1][1]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_y * (rand_y2 - 1), matrix->matrix[1][1]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z * rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE((rand_z + 0.0001) * rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/* Scenario: A scaling matrix applied to a point
	Given transform ← scaling(2, 3, 4)
	And p ← point(-4, 6, 8)
	Then transform * p = point(-8, 18, 32) */
	a = create_point(-4, 6, 8);
	b = create_point(2, 3, 4);
	matrix = scale_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-8, matrix->matrix[0][0]);
	TEST_ASSERT_EQUAL_DOUBLE(18, matrix->matrix[1][1]);
	TEST_ASSERT_EQUAL_DOUBLE(32, matrix->matrix[2][2]);
	TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void test_scale_matrix_vector(void)
{
	double		rand_x, rand_y, rand_z, rand_w;
	double		rand_x2, rand_y2, rand_z2, rand_w2;
	t_tuple		*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_x2 = double_rand();
		rand_y2 = double_rand();
		rand_z2 = double_rand();
		rand_w = 1;
		a = create_vector(rand_x, rand_y, rand_z);
		b = create_vector(rand_x2, rand_y2, rand_z2);
		matrix = scale_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x * rand_x2, matrix->matrix[0][0]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_x * rand_x2 - 1, matrix->matrix[0][0]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y * rand_y2, matrix->matrix[1][1]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_y * (rand_y2 - 1), matrix->matrix[1][1]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z * rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE((rand_z + 0.0001) * rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/* Scenario: A scaling matrix applied to a point
	Given transform ← scaling(2, 3, 4)
	And p ← point(-4, 6, 8)
	Then transform * p = point(-8, 18, 32) */
	a = create_vector(-4, 6, 8);
	b = create_vector(2, 3, 4);
	matrix = scale_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-8, matrix->matrix[0][0]);
	TEST_ASSERT_EQUAL_DOUBLE(18, matrix->matrix[1][1]);
	TEST_ASSERT_EQUAL_DOUBLE(32, matrix->matrix[2][2]);
	TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void test_inverse_scale_matrix_point(void)
{
	double		rand_x, rand_y, rand_z, rand_w;
	double		rand_x2, rand_y2, rand_z2, rand_w2;
	t_tuple		*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_x2 = -double_rand();
		rand_y2 = -double_rand();
		rand_z2 = -double_rand();
		rand_w = 1;
		a = create_point(rand_x, rand_y, rand_z);
		b = create_point(rand_x2, rand_y2, rand_z2);
		matrix = inversed_scale_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x / rand_x2, matrix->matrix[0][0]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_x / rand_x2 + 1, matrix->matrix[0][0]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y / rand_y2, matrix->matrix[1][1]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_y / rand_y2 - 1, matrix->matrix[1][1]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z / rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE((rand_z + 1) / rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/* Scenario: Multiplying by the inverse of a scaling matrix
	Given transform ← scaling(2, 3, 4)
	And inv ← inverse(transform)
	And v ← vector(-4, 6, 8)
	Then inv * v = vector(-2, 2, 2) */
	a = create_point(-4, 6, 8);
	b = create_point(2, 3, 4);
	matrix = inversed_scale_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-2, matrix->matrix[0][0]);
	TEST_ASSERT_EQUAL_DOUBLE(2, matrix->matrix[1][1]);
	TEST_ASSERT_EQUAL_DOUBLE(2, matrix->matrix[2][2]);
	TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void test_reflection(void)
{
	double		rand_x, rand_y, rand_z, rand_w;
	double		rand_x2, rand_y2, rand_z2, rand_w2;
	t_tuple		*a, *b;
	t_matrix	*matrix;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_x2 = -double_rand();
		rand_y2 = double_rand();
		rand_z2 = double_rand();
		rand_w = 1;
		a = create_vector(rand_x, rand_y, rand_z);
		b = create_vector(rand_x2, rand_y2, rand_z2);
		matrix = scale_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE(rand_x * rand_x2, matrix->matrix[0][0]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_x * rand_x2 - 1, matrix->matrix[0][0]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_y * rand_y2, matrix->matrix[1][1]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE(rand_y * (rand_y2 - 1), matrix->matrix[1][1]);
		TEST_ASSERT_EQUAL_DOUBLE(rand_z * rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_NOT_EQUAL_DOUBLE((rand_z + 0.0001) * rand_z2, matrix->matrix[2][2]);
		TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
		free(a);
		free(b);
		free(matrix);
	}
	/*Scenario: Reflection is scaling by a negative value
	Given transform ← scaling(-1, 1, 1)
	And p ← point(2, 3, 4)
	Then transform * p = point(-2, 3, 4)*/
	a = create_point(2, 3, 4);
	b = create_point(-1, 1, 1);
	matrix = scale_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(-2, matrix->matrix[0][0]);
	TEST_ASSERT_EQUAL_DOUBLE(3, matrix->matrix[1][1]);
	TEST_ASSERT_EQUAL_DOUBLE(4, matrix->matrix[2][2]);
	TEST_ASSERT_EQUAL_DOUBLE(a->w, matrix->matrix[3][3]);
	free(a);
	free(b);
	free(matrix);
}

void test_transformations(void)
{
	RUN_TEST(translate_point_tuple);
	RUN_TEST(inverse_translate_point_tuple);
	RUN_TEST(translate_vector_tuple);
	RUN_TEST(inverse_translate_vector_tuple);
	RUN_TEST(test_scale_matrix_point);
	RUN_TEST(test_scale_matrix_vector);
	RUN_TEST(test_inverse_scale_matrix_point);
	RUN_TEST(test_reflection);
}