// #include "unity/unity.h"
// #include <minirt.h>

// # define full_line_1 "L 10,10,-10 1 250,250,250"
// # define full_line_2 "C 0,2,-6 0,0,1 90"
// # define full_line_3 "cy 0,3,0  0,1,0 3 2 250,90,201"
// # define full_line_4 "cy 0,3,0.0.0  0,1,0 3 2 250,90,201"
// # define full_line_5 "cy 0,3,0  0,1,a 3 2 250,90,201"
// # define full_line_6 "cy 0,3,0  0,1,0 a 2 250,90,201"
// # define full_line_7 "cy 0,3,0  0,1,0 3 a 250,90,201"
// # define full_line_8 "cy 0,3,0  0,1,0 3 2 256,90,201"
// # define full_line_9 "cy 0,3,0  0,1,0 3 2 -1,90,201"
// # define full_line_10 "cy 0,3,0  0,1,0 3 2 1.1,90,201"

// void	test_check_cylinder_function(void)
// {
// 	t_scene 	*scene;
// 	t_object	*object;
// 	char		**splited;

// 	scene = (t_scene *)malloc(sizeof(t_scene));
// 	ft_bzero(scene, sizeof(t_scene));
// 	splited = ft_split(full_line_1, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_2, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_3, ' ');
// 	TEST_ASSERT_EQUAL_INT(0, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	object = (t_object *)scene->objects->content;
// 	TEST_ASSERT_EQUAL_DOUBLE(0, (object->x));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->x));
// 	TEST_ASSERT_EQUAL_DOUBLE(3, (object->y));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(2, (object->y));
// 	TEST_ASSERT_EQUAL_DOUBLE(0, (object->z));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->z));
// 	TEST_ASSERT_EQUAL_DOUBLE(0, (object->cylinder.x_3d));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->cylinder.x_3d));
// 	TEST_ASSERT_EQUAL_DOUBLE(1, (object->cylinder.y_3d));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(0, (object->cylinder.y_3d));
// 	TEST_ASSERT_EQUAL_DOUBLE(0, (object->cylinder.z_3d));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->cylinder.z_3d));
// 	TEST_ASSERT_EQUAL_DOUBLE(250.0 / 255.0, object->rgb->red);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(251.0 / 255.0, object->rgb->red);
// 	TEST_ASSERT_EQUAL_DOUBLE(90.0 / 255.0, object->rgb->green);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(91.0 / 255.0, object->rgb->green);
// 	TEST_ASSERT_EQUAL_DOUBLE(201.0 / 255.0, object->rgb->blue);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(202.0 / 255.0, object->rgb->blue);
// 	TEST_ASSERT_EQUAL_DOUBLE(3.0000, object->cylinder.diameter);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(2.9999, object->cylinder.diameter);
// 	TEST_ASSERT_EQUAL_DOUBLE(2.0000, object->cylinder.height);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(2.0001, object->cylinder.height);
// 	ft_lstclear(&scene->objects, free_lst_obj);
// 	free(scene);
// 	splited = ft_split(full_line_4, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_5, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_6, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_7, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_8, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_9, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_10, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_cylinder(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// }

// void test_check_cylinder(void)
// {
// 	RUN_TEST(test_check_cylinder_function);
// }
