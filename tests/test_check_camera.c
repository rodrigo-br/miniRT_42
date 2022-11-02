// #include "unity/unity.h"
// #include <minirt.h>

// # define line_1 "10.0,10.0,-10.0"
// # define line_2 "0,0,0"
// # define line_3 "0.1,10.5,40.3"
// # define line_4 "255.0,500.999,10.00001"
// # define line_5 "255,5,2"
// # define line_6 "255,5,-2"
// # define full_line_1 "L 10,10,-10 1 250,250,250"
// # define full_line_2 "L 10,10,-10 1 250,250,250"
// # define full_line_3 "L 10,10,-10 1 250,250,250"
// # define full_line_4 "C 0,2,-6 0,0,1 90"
// # define full_line_5 "C 0,2.0.0,-6 0,0,1 90"
// # define full_line_6 "C 0,2.0.0,-6 0,0.0.0,1 90"
// # define full_line_7 "C 0,2.0.0,-6 0,0.0.0,1 -1"
// # define full_line_8 "C 0,2.0.0,-6 0,0.0.0,1 181"

// void	test_check_camera_function(void)
// {
// 	t_camera 	*camera;
// 	char		**splited;

// 	splited = ft_split(full_line_1, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_2, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_3, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_4, ' ');
// 	TEST_ASSERT_EQUAL_INT(0, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	free(camera);
// 	splited = ft_split(full_line_5, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_6, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_7, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_8, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_camera(splited, &camera));
// 	ft_free_matrix((void *)&splited);
// }

// void test_check_camera(void)
// {
// 	RUN_TEST(test_check_camera_function);
// }
