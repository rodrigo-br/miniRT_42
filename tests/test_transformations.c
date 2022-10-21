#include <minirt.h>
#include "unity/unity.h"
#include <tests.h>


void	transform_point_tuple(void)
{
	double	rand_x, rand_y, rand_z, rand_w;
	t_tuple	*a, *b, *translate;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		rand_x = double_rand();
		rand_y = double_rand();
		rand_z = double_rand();
		rand_w = 1;
		a = create_tuple(rand_x, rand_y, rand_z, rand_w);
		b = create_tuple(rand_x, rand_y, rand_z, rand_w);
		translate = translate_matrix(a, b);
		TEST_ASSERT_EQUAL_DOUBLE((a->x + b->x), translate->x);
		TEST_ASSERT_EQUAL_DOUBLE((a->y + b->y), translate->y);
		TEST_ASSERT_EQUAL_DOUBLE((a->z + b->z), translate->z);
		TEST_ASSERT_EQUAL_DOUBLE(rand_w, 1);
		free(a);
		free(b);
		free(translate);
	}
	/*Scenario: Multiplying by a translation matrix
	Given transform ← translation(5, -3, 2)
	And p ← point(-3, 4, 5)
	Then transform * p = point(2, 1, 7)*/
	a = create_point(-3, 4, 5);
	b = create_tuple(5, -3, 2, 0);
	translate = translate_matrix(a, b);
	TEST_ASSERT_EQUAL_DOUBLE(2, translate->x);
	TEST_ASSERT_EQUAL_DOUBLE(1, translate->y);
	TEST_ASSERT_EQUAL_DOUBLE(7, translate->z);
	TEST_ASSERT_EQUAL_DOUBLE(1, translate->w);
	free(a);
	free(b);
	free(translate);
}


void test_transformations(void)
{
	RUN_TEST(transform_point_tuple);
}