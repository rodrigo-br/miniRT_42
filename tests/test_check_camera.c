#include "unity/unity.h"
#include <minirt.h>

# define line_1 "10.0,10.0,-10.0"
# define line_2 "0,0,0"
# define line_3 "0.1,10.5,40.3"
# define line_4 "255.0,500.999,10.00001"
# define line_5 "255,5,2"
# define line_6 "255,5,-2"
# define full_line_1 ft_split("L 10,10,-10 1 250,250,250", ' ')
# define full_line_2 ft_split("L 10,10,-10 1 250,250,250", ' ')
# define full_line_3 ft_split("L 10,10,-10 1 250,250,250", ' ')

void	test_set_object_coordinates(void)
{
	t_camera	camera;

	set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup(line_1));
	TEST_ASSERT_EQUAL_DOUBLE(10, camera.view_x);
	TEST_ASSERT_EQUAL_DOUBLE(10, camera.view_y);
	TEST_ASSERT_EQUAL_DOUBLE(-10, camera.view_z);
	set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup(line_2));
	TEST_ASSERT_EQUAL_DOUBLE(0, camera.view_x);
	TEST_ASSERT_EQUAL_DOUBLE(0, camera.view_y);
	TEST_ASSERT_EQUAL_DOUBLE(0, camera.view_z);
	set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup(line_3));
	TEST_ASSERT_EQUAL_DOUBLE(0.1, camera.view_x);
	TEST_ASSERT_EQUAL_DOUBLE(10.5, camera.view_y);
	TEST_ASSERT_EQUAL_DOUBLE(40.3, camera.view_z);
	set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup(line_4));
	TEST_ASSERT_EQUAL_DOUBLE(255.0, camera.view_x);
	TEST_ASSERT_EQUAL_DOUBLE(500.999, camera.view_y);
	TEST_ASSERT_EQUAL_DOUBLE(10.00001, camera.view_z);
	TEST_ASSERT_EQUAL_INT(1, set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup("abc")));
	TEST_ASSERT_EQUAL_INT(1, set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup("10,0,0.a")));
	TEST_ASSERT_EQUAL_INT(1, set_object_coordinates(&camera.view_x, &camera.view_y, &camera.view_z, ft_strdup("10,0,0.0a")));
}

void test_set_camera_3d_orientation(void)
{
	t_camera	camera;

	TEST_ASSERT_EQUAL_INT(1, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup(line_1)));
	TEST_ASSERT_EQUAL_INT(0, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup(line_2)));
	TEST_ASSERT_EQUAL_INT(0, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, "0,0,0"));
	TEST_ASSERT_EQUAL_DOUBLE(0.0, camera.x_3d);
	TEST_ASSERT_EQUAL_DOUBLE(0.0, camera.y_3d);
	TEST_ASSERT_EQUAL_DOUBLE(0.0, camera.z_3d);
	TEST_ASSERT_EQUAL_INT(1, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup(line_3)));
	TEST_ASSERT_EQUAL_INT(1, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup(line_4)));
	TEST_ASSERT_EQUAL_INT(1, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup("abc")));
	TEST_ASSERT_EQUAL_INT(1, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup("10,0,0.a")));
	TEST_ASSERT_EQUAL_INT(1, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup("10,0,0.0a")));
	TEST_ASSERT_EQUAL_INT(0, set_object_3d_orientation(&camera.x_3d, &camera.y_3d, &camera.z_3d, ft_strdup("1,-1,0.0")));
	TEST_ASSERT_EQUAL_DOUBLE(1.0, camera.x_3d);
	TEST_ASSERT_EQUAL_DOUBLE(-1.0, camera.y_3d);
	TEST_ASSERT_EQUAL_DOUBLE(0.0, camera.z_3d);
}

void	test_set_camera_fov(void)
{
	t_camera camera;

	TEST_ASSERT_EQUAL_INT(0, set_camera_fov(&camera, "1"));
	TEST_ASSERT_EQUAL_INT(0, set_camera_fov(&camera, "180"));
	TEST_ASSERT_EQUAL_INT(1, set_camera_fov(&camera, "-1"));
	TEST_ASSERT_EQUAL_INT(1, set_camera_fov(&camera, "181"));
}

void test_check_camera(void)
{
	RUN_TEST(test_set_object_coordinates);
	RUN_TEST(test_set_camera_3d_orientation);
	RUN_TEST(test_set_camera_fov);
}
