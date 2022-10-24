#include <minirt.h>
#include "unity/unity.h"

void	test_parser_only_1_each_unique_element(void)
{
	t_scene		*scene;
	t_list		*aux;
	t_object	*obj;
	int fd;

	scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	fd = open("../rt_files/many_obj.rt", O_RDONLY);
	TEST_ASSERT_EQUAL_INT(0, parser_1(fd, scene));
	TEST_ASSERT_EQUAL_DOUBLE(0.2, scene->ambience->ratio);
	TEST_ASSERT_EQUAL_CHAR(255, scene->ambience->rgb->red);
	TEST_ASSERT_EQUAL_CHAR(250, scene->ambience->rgb->green);
	TEST_ASSERT_EQUAL_CHAR(245, scene->ambience->rgb->blue);
	TEST_ASSERT_EQUAL_DOUBLE(0, scene->camera->view_x);
	TEST_ASSERT_EQUAL_DOUBLE(2, scene->camera->view_y);
	TEST_ASSERT_EQUAL_DOUBLE(-6, scene->camera->view_z);
	TEST_ASSERT_EQUAL_DOUBLE(0.5, scene->camera->x_3d);
	TEST_ASSERT_EQUAL_DOUBLE(-1, scene->camera->y_3d);
	TEST_ASSERT_EQUAL_DOUBLE(1, scene->camera->z_3d);
	TEST_ASSERT_EQUAL_DOUBLE(90, scene->camera->fov);
	TEST_ASSERT_EQUAL_DOUBLE(15, scene->light->x);
	TEST_ASSERT_EQUAL_DOUBLE(10, scene->light->y);
	TEST_ASSERT_EQUAL_DOUBLE(-10, scene->light->z);
	TEST_ASSERT_EQUAL_DOUBLE(1, scene->light->brightness);
	TEST_ASSERT_EQUAL_DOUBLE(250, scene->light->rgb->red);
	TEST_ASSERT_EQUAL_DOUBLE(255, scene->light->rgb->green);
	TEST_ASSERT_EQUAL_DOUBLE(245, scene->light->rgb->blue);
	aux = scene->objects;
	while (aux)
	{
		obj = (t_object *)aux->content;
		if (obj->type == ID_CYLINDER)
		{
			TEST_ASSERT_EQUAL_DOUBLE(9, obj->x);
			TEST_ASSERT_EQUAL_DOUBLE(3, obj->y);
			TEST_ASSERT_EQUAL_DOUBLE(0, obj->z);
			TEST_ASSERT_EQUAL_DOUBLE(250, obj->rgb->red);
			TEST_ASSERT_EQUAL_DOUBLE(90, obj->rgb->green);
			TEST_ASSERT_EQUAL_DOUBLE(201, obj->rgb->blue);
			TEST_ASSERT_EQUAL_DOUBLE(0, obj->cylinder.x_3d);
			TEST_ASSERT_EQUAL_DOUBLE(1, obj->cylinder.y_3d);
			TEST_ASSERT_EQUAL_DOUBLE(-0.3, obj->cylinder.z_3d);
			TEST_ASSERT_EQUAL_DOUBLE(3, obj->cylinder.diameter);
			TEST_ASSERT_EQUAL_DOUBLE(2, obj->cylinder.height);
			//cy 9,3,0  0,1,-0.3 3 2 250,90,201
		}
		else if (obj->type == ID_SPHERE)
		{
			TEST_ASSERT_EQUAL_DOUBLE(6.1, obj->x);
			TEST_ASSERT_EQUAL_DOUBLE(5.7, obj->y);
			TEST_ASSERT_EQUAL_DOUBLE(20.6, obj->z);
			TEST_ASSERT_EQUAL_DOUBLE(10, obj->rgb->red);
			TEST_ASSERT_EQUAL_DOUBLE(0, obj->rgb->green);
			TEST_ASSERT_EQUAL_DOUBLE(255, obj->rgb->blue);
			TEST_ASSERT_EQUAL_DOUBLE(12.6, obj->sphere.diameter);
			//sp 6.1,5.7,20.6 12.6 10,0,255
		}
		else if (obj->type == ID_PLANE)
		{
			TEST_ASSERT_EQUAL_DOUBLE(1, obj->x);
			TEST_ASSERT_EQUAL_DOUBLE(2, obj->y);
			TEST_ASSERT_EQUAL_DOUBLE(3, obj->z);
			TEST_ASSERT_EQUAL_DOUBLE(250, obj->rgb->red);
			TEST_ASSERT_EQUAL_DOUBLE(200, obj->rgb->green);
			TEST_ASSERT_EQUAL_DOUBLE(225, obj->rgb->blue);
			TEST_ASSERT_EQUAL_DOUBLE(0.3, obj->plane.x_3d);
			TEST_ASSERT_EQUAL_DOUBLE(0.1, obj->plane.y_3d);
			TEST_ASSERT_EQUAL_DOUBLE(-1, obj->plane.z_3d);
		}
		aux = aux->next;
	}
	free_scene(scene);
	close(fd);
	scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	fd = open("../tests/invalid_1.rt", O_RDONLY);
	TEST_ASSERT_EQUAL_INT(1, parser_1(fd, scene));
	close(fd);
	scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	fd = open("../tests/invalid_2.rt", O_RDONLY);
	TEST_ASSERT_EQUAL_INT(1, parser_1(fd, scene));
	close(fd);
	scene = (t_scene *)malloc(sizeof(t_scene));
	ft_bzero(scene, sizeof(t_scene));
	fd = open("../tests/invalid_3.rt", O_RDONLY);
	TEST_ASSERT_EQUAL_INT(1, parser_1(fd, scene));
	close(fd);
}

void test_parser(void)
{
	RUN_TEST(test_parser_only_1_each_unique_element);
}
