#include "unity/unity.h"
#include <minirt.h>

void	test_atod_valid_values(void)
{
	TEST_ASSERT_EQUAL_DOUBLE(ft_atod("21.3"), 21.3);
	TEST_ASSERT_EQUAL_DOUBLE(ft_atod("22"), 22.0);
	TEST_ASSERT_EQUAL_DOUBLE(ft_atod("0.1"), 0.1);
	TEST_ASSERT_EQUAL_DOUBLE(ft_atod("0.01"), 0.01);
	TEST_ASSERT_NOT_EQUAL_DOUBLE(ft_atod("0.01"), 0.1);
	TEST_ASSERT_NOT_EQUAL_DOUBLE(ft_atod("1"), 1.1);
}

void test_atod(void)
{
	RUN_TEST(test_atod_valid_values);
}
