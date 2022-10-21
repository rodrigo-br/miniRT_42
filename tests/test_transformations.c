#include <minirt.h>
#include "unity/unity.h"
#include <tests.h>


void	transform_point_tuple(void)
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
		TEST_ASSERT_EQUAL_DOUBLE(1, rand_w);
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

// void inverse_transform_point_tuple(void)
// {
// 	double	rand_x, rand_y, rand_z, rand_w;
// 	t_tuple	*a, *b, *translate;
// 	for (int i = 0; i < LOOP_ITERATIONS; i++)
// 	{
// 		rand_x = double_rand();
// 		rand_y = double_rand();
// 		rand_z = double_rand();
// 		rand_w = 1;
// 		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
// 		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
// 		translate = translate_inverse_matrix(a, b);
// 		TEST_ASSERT_EQUAL_DOUBLE((a->x + -b->x), translate->x);
// 		TEST_ASSERT_EQUAL_DOUBLE((a->y + -b->y), translate->y);
// 		TEST_ASSERT_EQUAL_DOUBLE((a->z + -b->z), translate->z);
// 		TEST_ASSERT_EQUAL_DOUBLE(rand_w, 1);
// 		free(a);
// 		free(b);
// 		free(translate);
// 	}
// 	/*Scenario: Multiplying by the inverse of a translation matrix
// 	Given transform ← translation(5, -3, 2)
// 	And inv ← inverse(transform)
// 	And p ← point(-3, 4, 5)
// 	Then inv * p = point(-8, 7, 3)*/
// 	a = create_point(-3, 4, 5);
// 	b = create_tuple(5, -3, 2, 0);
// 	translate = translate_inverse_matrix(a, b);
// 	TEST_ASSERT_EQUAL_DOUBLE(-8, translate->x);
// 	TEST_ASSERT_EQUAL_DOUBLE(7, translate->y);
// 	TEST_ASSERT_EQUAL_DOUBLE(3, translate->z);
// 	TEST_ASSERT_EQUAL_DOUBLE(1, translate->w);
// 	free(a);
// 	free(b);
// 	free(translate);
// }

// void	transform_vector_tuple(void)
// {
// 	double	rand_x, rand_y, rand_z, rand_w;
// 	t_tuple	*a, *b, *translate;

// 	for (int i = 0; i < LOOP_ITERATIONS; i++)
// 	{
// 		rand_x = double_rand();
// 		rand_y = double_rand();
// 		rand_z = double_rand();
// 		rand_w = 1;
// 		a = create_vector(rand_x, rand_y, rand_z);
// 		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
// 		translate = translate_matrix(a, b);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->x, translate->x);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->y, translate->y);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->z, translate->z);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->w, translate->w);
// 		free(a);
// 		free(b);
// 		free(translate);
// 	}
// 	/*Scenario: Translation does not affect vectors
// 	Given transform ← translation(5, -3, 2)
// 	And v ← vector(-3, 4, 5)
// 	Then transform * v = v*/
// 	a = create_vector(-3, 4, 5);
// 	b = create_point(5, -3, 2);
// 	translate = translate_matrix(a, b);
// 	TEST_ASSERT_EQUAL_DOUBLE(-3, translate->x);
// 	TEST_ASSERT_EQUAL_DOUBLE(4, translate->y);
// 	TEST_ASSERT_EQUAL_DOUBLE(5, translate->z);
// 	TEST_ASSERT_EQUAL_DOUBLE(0, translate->w);
// 	free(a);
// 	free(b);
// 	free(translate);
// }

// void inverse_transform_vector_tuple(void)
// {
// 	double	rand_x, rand_y, rand_z, rand_w;
// 	t_tuple	*a, *b, *translate;
// 	for (int i = 0; i < LOOP_ITERATIONS; i++)
// 	{
// 		rand_x = double_rand();
// 		rand_y = double_rand();
// 		rand_z = double_rand();
// 		rand_w = 1;
// 		a = create_vector(rand_x, rand_y, rand_z);
// 		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
// 		translate = translate_inverse_matrix(a, b);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->x, translate->x);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->y, translate->y);
// 		TEST_ASSERT_EQUAL_DOUBLE(a->z, translate->z);
// 		TEST_ASSERT_EQUAL_DOUBLE(rand_w, 1);
// 		free(a);
// 		free(b);
// 		free(translate);
// 	}
// }

void test_transformations(void)
{
	RUN_TEST(transform_point_tuple);
	// RUN_TEST(inverse_transform_point_tuple);
	// RUN_TEST(transform_vector_tuple);
	// RUN_TEST(inverse_transform_vector_tuple);
}