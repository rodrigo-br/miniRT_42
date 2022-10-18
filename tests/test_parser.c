#include <minirt.h>
#include "unity/unity.h"

void	test_parser_only_1_each_unique_element(void)
{
	int fd = open("../rt_files/many_obj.rt", O_RDONLY);
	TEST_ASSERT_EQUAL_INT(0, parser_1(fd));
}

void test_parser(void)
{
	RUN_TEST(test_parser_only_1_each_unique_element);
}
