// #include <tests.h>
// #include "unity/unity.h"

// void	sub_main_inexistent_file(void)
// {
// 	char **argv = ft_split("./miniRT ../tests/asdasdas.rt", ' ');

// 	TEST_ASSERT_EQUAL_INT(1, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);
// }

// void	sub_main_empty_file(void)
// {
// 	char **argv = ft_split("./miniRT ../tests/empty_1.rt", ' ');

// 	TEST_ASSERT_EQUAL_INT(1, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);
// }

// void	sub_main_test_invalid_files(void)
// {
// 	char **argv = ft_split("./miniRT ../tests/invalid_1.rt", ' ');

// 	TEST_ASSERT_EQUAL_INT(1, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);

// 	argv = ft_split("./miniRT ../tests/invalid_2.rt", ' ');
// 	TEST_ASSERT_EQUAL_INT(1, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);

// 	argv = ft_split("./miniRT ../tests/invalid_3.rt", ' ');
// 	TEST_ASSERT_EQUAL_INT(1, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);

// 	argv = ft_split("./miniRT ../tests/invalid_4.rt", ' ');
// 	TEST_ASSERT_EQUAL_INT(1, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);
// }

// void	sub_main_valid_scene(void)
// {
// 	char **argv = ft_split("./miniRT ../rt_files/many_obj.rt", ' ');

// 	TEST_ASSERT_EQUAL_INT(0, sub_main(2, argv));
// 	ft_free_matrix((void *)&argv);
// }

// void test_sub_main(void)
// {
// 	// RUN_TEST(sub_main_inexistent_file);
// 	// RUN_TEST(sub_main_empty_file);
// 	// RUN_TEST(sub_main_test_invalid_files);
// 	RUN_TEST(sub_main_valid_scene);
// }
