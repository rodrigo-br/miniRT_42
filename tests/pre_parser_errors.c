
#include <minirt.h>
#include "unity/unity.h"

int fd;

void	dont_have_two_args(void)
{
	char *argv[4] = {"", "", "", ""};
	TEST_ASSERT_EQUAL_INT(errors(4, argv, &fd), 1);
	TEST_ASSERT_EQUAL_INT(errors(3, argv + 1, &fd), 1);
	TEST_ASSERT_EQUAL_INT(errors(1, argv + 3, &fd), 1);
}

void	is_invalid_extension(void)
{
	char *argv_1[2] = {"", "../rt_files/many_obj.rt"};
	char *argv_2[2] = {"../miniRT", "../rt_files/many_obj.rt"};
	char *argv_3[2] = {"", "../Makefile"};
	char *argv_4[2] = {"", ".rt"};
	TEST_ASSERT_EQUAL_INT(errors(2, argv_1, &fd), 0);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_2, &fd), 0);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_3, &fd), 1);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_4, &fd), 1);
}

void	can_open(void)
{
	char *argv_1[2] = {"", "../rt_files/many_obj.rt"};
	char *argv_2[2] = {"../miniRT", "../rt_files/many_obj.rt"};
	char *argv_3[2] = {"", "../Makefile.rt"};
	char *argv_4[2] = {"", "a.rt"};
	char *argv_5[2] = {"../rt_files/many_obj.rt", "../Makefile.rt"};
	char *argv_6[2] = {"../rt_files/many_obj.rt", "a.rt"};
	TEST_ASSERT_EQUAL_INT(errors(2, argv_1, &fd), 0);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_2, &fd), 0);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_3, &fd), 1);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_4, &fd), 1);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_5, &fd), 1);
	TEST_ASSERT_EQUAL_INT(errors(2, argv_6, &fd), 1);
}

void	pre_parser_errors(void)
{
	RUN_TEST(dont_have_two_args);
	RUN_TEST(is_invalid_extension);
	RUN_TEST(can_open);
}
