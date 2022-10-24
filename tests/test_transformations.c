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

/*
Scenario: Rotating a point around the x axis
Given p ← point(0, 1, 0)
And half_quarter ← rotation_x(π / 4)
And full_quarter ← rotation_x(π / 2)
Then half_quarter * p = point(0, √2/2, √2/2)
And full_quarter * p = point(0, 0, 1)
*/
void	rotation_x_axis(void)
{
	t_point *p;
	t_matrix *half_quarter;
	t_matrix *full_quarter;
	t_tuple *first_solution;
	t_tuple	*second_solution;

	p = create_point(0, 1, 0);
	half_quarter = rotate_matrix_x(M_PI / 4);
	full_quarter = rotate_matrix_x(M_PI / 2);
	first_solution = multiply_matrix_tuple(half_quarter, p);
	TEST_ASSERT_TRUE(is_equal_tuple(first_solution, &(t_tuple){0, (sqrt(2)/2), (sqrt(2)/2), 1}));
	free(first_solution);
	free(half_quarter);
	second_solution = multiply_matrix_tuple(full_quarter, p);
	TEST_ASSERT_TRUE(is_equal_tuple(second_solution, &(t_tuple){0, 0, 1, 1}));
	free(second_solution);
	free(full_quarter);
	free(p);
}

/*
Scenario: The inverse of an x-rotation rotates in the opposite direction
Given p ← point(0, 1, 0)
And half_quarter ← rotation_x(π / 4)
And inv ← inverse(half_quarter)
Then inv * p = point(0, √2/2, -√2/2)
*/
void inverse_rotation_x_axis(void)
{
	t_point *p;
	t_matrix *half_quarter;
	t_matrix *inverse;
	t_tuple *solution;

	p = create_point(0, 1, 0);
	half_quarter = rotate_matrix_x(radians(180/4));
	inverse = inverse_matrix(half_quarter);
	solution = multiply_matrix_tuple(inverse, p);
	TEST_ASSERT_TRUE(is_equal_tuple(solution, &(t_tuple){0, (sqrt(2)/2), -(sqrt(2)/2), 1}));
	free(solution);
	free(inverse);
	free(half_quarter);
	free(p);
}

/*
Scenario: Rotating a point around the y axis
Given p ← point(0, 0, 1)
And half_quarter ← rotation_y(π / 4)
And full_quarter ← rotation_y(π / 2)
Then half_quarter * p = point(√2/2, 0, √2/2)
And full_quarter * p = point(1, 0, 0)
*/
void	rotation_y_axis(void)
{
	t_point *p;
	t_matrix *half_quarter;
	t_matrix *full_quarter;
	t_tuple *first_solution;
	t_tuple	*second_solution;

	p = create_point(0, 0, 1);
	half_quarter = rotate_matrix_y(radians(180/4));
	full_quarter = rotate_matrix_y(radians(180/2));
	first_solution = multiply_matrix_tuple(half_quarter, p);
	TEST_ASSERT_TRUE(is_equal_tuple(first_solution, &(t_tuple){(sqrt(2)/2), 0, (sqrt(2)/2), 1}));
	free(first_solution);
	free(half_quarter);
	second_solution = multiply_matrix_tuple(full_quarter, p);
	TEST_ASSERT_TRUE(is_equal_tuple(second_solution, &(t_tuple){1, 0, 0, 1}));
	free(second_solution);
	free(full_quarter);
	free(p);
}

/*
Scenario: Rotating a point around the z axis
Given p ← point(0, 1, 0)
And half_quarter ← rotation_z(π / 4)
And full_quarter ← rotation_z(π / 2)
Then half_quarter * p = point(-√2/2, √2/2, 0)
And full_quarter * p = point(-1, 0, 0)
*/
void	rotation_z_axis(void)
{
	t_point *p;
	t_matrix *half_quarter;
	t_matrix *full_quarter;
	t_tuple *first_solution;
	t_tuple	*second_solution;

	p = create_point(0, 1, 0);
	half_quarter = rotate_matrix_z(M_PI / 4);
	full_quarter = rotate_matrix_z(M_PI / 2);
	first_solution = multiply_matrix_tuple(half_quarter, p);
	TEST_ASSERT_TRUE(is_equal_tuple(first_solution, &(t_tuple){-(sqrt(2)/2), (sqrt(2)/2), 0, 1}));
	free(first_solution);
	free(half_quarter);
	second_solution = multiply_matrix_tuple(full_quarter, p);
	TEST_ASSERT_TRUE(is_equal_tuple(second_solution, &(t_tuple){-1, 0, 0, 1}));
	free(second_solution);
	free(full_quarter);
	free(p);
}

/*
Scenario: A shearing transformation moves x in proportion to y
Given transform ← shearing(1, 0, 0, 0, 0, 0)
And p ← point(2, 3, 4)
Then transform * p = point(5, 3, 4)
*/
void shearing_x_to_y(void)
{
	t_matrix	*shearing;
	t_tuple		*result;
	t_point		*p;
	t_shearing	s;

	ft_bzero(&s, sizeof(t_shearing));
	s.xy = 1;
	p = create_point(2, 3, 4);
	shearing = shearing_matrix(s);
	result = multiply_matrix_tuple(shearing, p);
	TEST_ASSERT_TRUE(is_equal_tuple(result, &(t_tuple){5, 3, 4, 1}));
	free(p);
	free(shearing);
	free(result);
}

/*
Scenario: A shearing transformation moves x in proportion to z
Given transform ← shearing(0, 1, 0, 0, 0, 0)
And p ← point(2, 3, 4)
Then transform * p = point(6, 3, 4)
*/
void shearing_x_to_z(void)
{
	t_matrix	*shearing;
	t_tuple		*result;
	t_point		*p;
	t_shearing	s;

	ft_bzero(&s, sizeof(t_shearing));
	s.xz = 1;
	p = create_point(2, 3, 4);
	shearing = shearing_matrix(s);
	result = multiply_matrix_tuple(shearing, p);
	TEST_ASSERT_TRUE(is_equal_tuple(result, &(t_tuple){6, 3, 4, 1}));
	free(p);
	free(shearing);
	free(result);
}

/*
Scenario: A shearing transformation moves y in proportion to x
Given transform ← shearing(0, 0, 1, 0, 0, 0)
And p ← point(2, 3, 4)
Then transform * p = point(2, 5, 4)
*/
void shearing_y_to_x(void)
{
	t_matrix	*shearing;
	t_tuple		*result;
	t_point		*p;
	t_shearing	s;

	ft_bzero(&s, sizeof(t_shearing));
	s.yx = 1;
	p = create_point(2, 3, 4);
	shearing = shearing_matrix(s);
	result = multiply_matrix_tuple(shearing, p);
	TEST_ASSERT_TRUE(is_equal_tuple(result, &(t_tuple){2, 5, 4, 1}));
	free(p);
	free(shearing);
	free(result);
}

/*
Scenario: A shearing transformation moves y in proportion to z
Given transform ← shearing(0, 0, 0, 1, 0, 0)
And p ← point(2, 3, 4)
Then transform * p = point(2, 7, 4)
*/
void shearing_y_to_z(void)
{
	t_matrix	*shearing;
	t_tuple		*result;
	t_point		*p;
	t_shearing	s;

	ft_bzero(&s, sizeof(t_shearing));
	s.yz = 1;
	p = create_point(2, 3, 4);
	shearing = shearing_matrix(s);
	result = multiply_matrix_tuple(shearing, p);
	TEST_ASSERT_TRUE(is_equal_tuple(result, &(t_tuple){2, 7, 4, 1}));
	free(p);
	free(shearing);
	free(result);
}

/*
Scenario: A shearing transformation moves z in proportion to x
Given transform ← shearing(0, 0, 0, 0, 1, 0)
And p ← point(2, 3, 4)
Then transform * p = point(2, 3, 6)
*/
void shearing_z_to_x(void)
{
	t_matrix	*shearing;
	t_tuple		*result;
	t_point		*p;
	t_shearing	s;

	ft_bzero(&s, sizeof(t_shearing));
	s.zx = 1;
	p = create_point(2, 3, 4);
	shearing = shearing_matrix(s);
	result = multiply_matrix_tuple(shearing, p);
	TEST_ASSERT_TRUE(is_equal_tuple(result, &(t_tuple){2, 3, 6, 1}));
	free(p);
	free(shearing);
	free(result);
}

/*
Scenario: A shearing transformation moves z in proportion to y
Given transform ← shearing(0, 0, 0, 0, 0, 1)
And p ← point(2, 3, 4)
Then transform * p = point(2, 3, 7)
*/
void shearing_z_to_y(void)
{
	t_matrix	*shearing;
	t_tuple		*result;
	t_point		*p;
	t_shearing	s;

	ft_bzero(&s, sizeof(t_shearing));
	s.zy = 1;
	p = create_point(2, 3, 4);
	shearing = shearing_matrix(s);
	result = multiply_matrix_tuple(shearing, p);
	TEST_ASSERT_TRUE(is_equal_tuple(result, &(t_tuple){2, 3, 7, 1}));
	free(p);
	free(shearing);
	free(result);
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
	RUN_TEST(rotation_x_axis);
	RUN_TEST(inverse_rotation_x_axis);
	RUN_TEST(rotation_y_axis);
	RUN_TEST(rotation_z_axis);
	RUN_TEST(shearing_x_to_y);
	RUN_TEST(shearing_x_to_z);
	RUN_TEST(shearing_y_to_x);
	RUN_TEST(shearing_y_to_z);
	RUN_TEST(shearing_z_to_x);
	RUN_TEST(shearing_z_to_y);
}
