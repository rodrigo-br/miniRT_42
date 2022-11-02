// #include "unity/unity.h"
// #include <minirt.h>

// # define full_line_1 "L 10,10,-10 1a 250,250,250"
// # define full_line_2 "C 0,2,-6 0,0,1 90"
// # define full_line_3 "sp 0.0,0.0,20.6 12.6 10,0,255"
// # define full_line_4 "sp 0.0.,0.0,20.6 12.6 10,0,255"
// # define full_line_5 "sp 0.0,a.0,20.6 12.6 10,0,255"
// # define full_line_6 "sp 0.0,0.0,20.-6 12.6 10,0,255"
// # define full_line_7 "sp 0.0,0.0,20.6 a 10,0,255"
// # define full_line_8 "sp 0.0,0.0,20.6 12.6 -1,0,255"
// # define full_line_9 "sp 0.0,0.0,20.6 12.6 10,256,255"
// # define full_line_10 "sp 0.0,0.0,20.6 12.6 10,0,256"

// void	test_check_sphere_function(void)
// {
// 	t_scene 	*scene;
// 	t_object	*object;
// 	char		**splited;

// 	scene = (t_scene *)malloc(sizeof(t_scene));
// 	ft_bzero(scene, sizeof(t_scene));
// 	splited = ft_split(full_line_1, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_2, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_3, ' ');
// 	TEST_ASSERT_EQUAL_INT(0, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	object = (t_object *)scene->objects->content;
// 	TEST_ASSERT_EQUAL_DOUBLE(0, (object->x));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->x));
// 	TEST_ASSERT_EQUAL_DOUBLE(0, (object->y));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(2, (object->y));
// 	TEST_ASSERT_EQUAL_DOUBLE(20.6, (object->z));
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->z));
// 	TEST_ASSERT_EQUAL_DOUBLE(10.0 / 255.0, object->rgb->red);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(251.0 / 255.0, object->rgb->red);
// 	TEST_ASSERT_EQUAL_DOUBLE(0.0 / 255.0, object->rgb->green);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(91.0 / 255.0, object->rgb->green);
// 	TEST_ASSERT_EQUAL_DOUBLE(255.0 / 255.0, object->rgb->blue);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(202.0 / 255.0, object->rgb->blue);
// 	TEST_ASSERT_EQUAL_DOUBLE(12.6, object->sphere.diameter);
// 	TEST_ASSERT_NOT_EQUAL_DOUBLE(12.7, object->sphere.diameter);
// 	ft_lstclear(&scene->objects, free_lst_obj);
// 	free(scene);
// 	splited = ft_split(full_line_4, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_5, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_6, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_7, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_8, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_9, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// 	splited = ft_split(full_line_10, ' ');
// 	TEST_ASSERT_EQUAL_INT(1, check_sphere(splited, &scene->objects));
// 	ft_free_matrix((void *)&splited);
// }

// void test_check_sphere(void)
// {
// 	RUN_TEST(test_check_sphere_function);
// }
