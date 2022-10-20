#include "unity/unity.h"
#include <minirt.h>

# define full_line_1 "L 10,10,-10 1 250,250,250"
# define full_line_2 "C 0,2,-6 0,0,1 90"
# define full_line_3 "pl 0,0,0 0,0,0 250,200,200"
# define full_line_4 "pl 0,0,0.0.0 0,0,0 250,200,200"
# define full_line_5 "pl 0,0,0 0,0,0a 250,200,200"
# define full_line_6 "pl 0,0,0 0,0,0 256,200,200"
# define full_line_7 "pl 0,0,0 0,0,0 250,256,200"
# define full_line_8 "pl 0,0,0 0,0,0 250,200,256"
# define full_line_9 "pl 0,0,0 0,0,0 250,200,a"
# define full_line_10 "pl 0,0,0 0,0,0 250 200,200"

void	test_check_plane_function(void)
{
	t_scene 	*scene;
	t_object	*object;
	char		**splited;

	scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	splited = ft_split(full_line_1, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_2, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_3, ' ');
	TEST_ASSERT_EQUAL_INT(0, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	object = (t_object *)scene->objects->content;
	TEST_ASSERT_EQUAL_DOUBLE(0, (object->x));
	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->x));
	TEST_ASSERT_EQUAL_DOUBLE(0, (object->y));
	TEST_ASSERT_NOT_EQUAL_DOUBLE(2, (object->y));
	TEST_ASSERT_EQUAL_DOUBLE(0, (object->z));
	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->z));
	TEST_ASSERT_EQUAL_DOUBLE(0, (object->plane.x_3d));
	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->plane.x_3d));
	TEST_ASSERT_EQUAL_DOUBLE(0, (object->plane.y_3d));
	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->plane.y_3d));
	TEST_ASSERT_EQUAL_DOUBLE(0, (object->plane.z_3d));
	TEST_ASSERT_NOT_EQUAL_DOUBLE(1, (object->plane.z_3d));
	TEST_ASSERT_EQUAL_CHAR(250, object->rgb->red);
	TEST_ASSERT_NOT_EQUAL_CHAR(251, object->rgb->red);
	TEST_ASSERT_EQUAL_CHAR(200, object->rgb->green);
	TEST_ASSERT_NOT_EQUAL_CHAR(91, object->rgb->green);
	TEST_ASSERT_EQUAL_CHAR(200, object->rgb->blue);
	TEST_ASSERT_NOT_EQUAL_CHAR(202, object->rgb->blue);
	ft_lstclear(&scene->objects, free_lst_obj);
	free(scene);
	splited = ft_split(full_line_4, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_5, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_6, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_7, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_8, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_9, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_10, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_plane(splited, &scene->objects));
	ft_free_matrix((void *)&splited);
}

void test_check_plane(void)
{
	RUN_TEST(test_check_plane_function);
}
