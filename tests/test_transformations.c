#include <minirt.h>
#include "unity/unity.h"
#include <tests.h>

/*Scenario: Multiplying by a translation matrix
	Given transform ← translation(5, -3, 2)
	And p ← point(-3, 4, 5)
	Then transform * p = point(2, 1, 7)*/
void	translate_point_tuple(void)
{
	t_tuple *b;
	t_tuple	*a;
	t_matrix	*matrix;
	
	a = create_point(-3, 4, 5);
	matrix = translate_matrix(5, -3, 2);
	b = multiply_matrix_tuple(matrix, a);
	TEST_ASSERT_EQUAL_DOUBLE(2, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(1, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(7, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(1, b->w);
	free(a);
	free(b);
	free(matrix);
}


/* Scenario: Translation does not affect vectors
Given transform ← translation(5, -3, 2)
And v ← vector(-3, 4, 5)
Then transform * v = v
 */
void	translate_vector_tuple(void)
{
	t_tuple *b;
	t_tuple	*a;
	t_matrix	*matrix;
	a = create_vector(-3, 4, 5);
	matrix = translate_matrix(5, -3, 2);
	b = multiply_matrix_tuple(matrix, a);
	TEST_ASSERT_EQUAL_DOUBLE(-3, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(4, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(5, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(0, b->w);
	free(a);
	free(b);
	free(matrix);
}


/* Scenario: Multiplying by the inverse of a translation matrix
Given transform ← translation(5, -3, 2)
And inv ← inverse(transform)
And p ← point(-3, 4, 5)
Then inv * p = point(-8, 7, 3) */
void	translate_point_inversed_tuple(void)
{
	t_tuple *b;
	t_tuple	*a;
	t_matrix	*matrix;
	t_matrix	*inversed;
	
	a = create_point(-3, 4, 5);
	matrix = translate_matrix(5, -3, 2);
	inversed = inverse_matrix(matrix);
	b = multiply_matrix_tuple(inversed, a);
	TEST_ASSERT_EQUAL_DOUBLE(-8, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(7, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(3, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(1, b->w);
	free(a);
	free(b);
	free(inversed);
	free(matrix);
}

void	translate_vector_inversed_tuple(void)
{
	t_tuple *b;
	t_tuple	*a;
	t_matrix	*matrix;
	t_matrix	*inversed;
	
	a = create_vector(-3, 4, 5);
	matrix = translate_matrix(5, -3, 2);
	inversed = inverse_matrix(matrix);
	b = multiply_matrix_tuple(inversed, a);
	TEST_ASSERT_EQUAL_DOUBLE(-3, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(4, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(5, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(0, b->w);
	free(a);
	free(b);
	free(inversed);
	free(matrix);
}

/*
Scenario: A scaling matrix applied to a point
Given transform ← scaling(2, 3, 4)
And p ← point(-4, 6, 8)
Then transform * p = point(-8, 18, 32)
*/
void	scaling_point_tuple(void)
{
	t_tuple		*a;
	t_matrix	*matrix;
	t_tuple		*b;

	matrix = scale_matrix(2, 3, 4);
	a = create_point(-4, 6, 8);
	b = multiply_matrix_tuple(matrix, a);
	TEST_ASSERT_EQUAL_DOUBLE(-8, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(18, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(32, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(1, b->w);
	free(a);
	free(b);
	free(matrix);
}

void	scaling_vector_tuple(void)
{
	t_tuple		*a;
	t_matrix	*matrix;
	t_tuple		*b;

	matrix = scale_matrix(2, 3, 4);
	a = create_vector(-4, 6, 8);
	b = multiply_matrix_tuple(matrix, a);
	TEST_ASSERT_EQUAL_DOUBLE(-8, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(18, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(32, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(0, b->w);
	free(a);
	free(b);
	free(matrix);
}

/*
Scenario: Multiplying by the inverse of a scaling matrix
Given transform ← scaling(2, 3, 4)
And inv ← inverse(transform)
And v ← vector(-4, 6, 8)
Then inv * v = vector(-2, 2, 2)
*/
void	scaling_vector_inversed_tuple(void)
{
	t_tuple		*a;
	t_matrix	*matrix;
	t_matrix	*inversed;
	t_tuple		*b;

	matrix = scale_matrix(2, 3, 4);
	inversed = inverse_matrix(matrix);
	a = create_vector(-4, 6, 8);
	b = multiply_matrix_tuple(inversed, a);
	TEST_ASSERT_EQUAL_DOUBLE(-2, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(2, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(2, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(0, b->w);
	free(a);
	free(b);
	free(inversed);
	free(matrix);
}

/*
Scenario: Reflection is scaling by a negative value
Given transform ← scaling(-1, 1, 1)
And p ← point(2, 3, 4)
Then transform * p = point(-2, 3, 4)
*/
void	scaling_reflection_tuple(void)
{
	t_tuple		*a;
	t_matrix	*matrix;
	t_tuple		*b;

	matrix = scale_matrix(-1, 1, 1);
	a = create_vector(2, 3, 4);
	b = multiply_matrix_tuple(matrix, a);
	TEST_ASSERT_EQUAL_DOUBLE(-2, b->x);
	TEST_ASSERT_EQUAL_DOUBLE(3, b->y);
	TEST_ASSERT_EQUAL_DOUBLE(4, b->z);
	TEST_ASSERT_EQUAL_DOUBLE(0, b->w);
	free(a);
	free(b);
	free(matrix);
}

void test_transformations(void)
{
	RUN_TEST(translate_point_tuple);
	RUN_TEST(translate_vector_tuple);
	RUN_TEST(translate_point_inversed_tuple);
	RUN_TEST(translate_vector_inversed_tuple);
	RUN_TEST(scaling_point_tuple);
	RUN_TEST(scaling_vector_tuple);
	RUN_TEST(scaling_vector_inversed_tuple);
	RUN_TEST(scaling_reflection_tuple);
}
