#include "unity/unity.h"
#include <minirt.h>

void	test_atod_valid_values(void)
{
	TEST_ASSERT_EQUAL_DOUBLE(ft_atod(22.3), 22.3);
}

void test_atod(void)
{
	RUN_TEST(test_atod_valid_values);
}
