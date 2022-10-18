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

void	test_set_light_coordinates(void)
{
	t_light	light;

	set_coordinates(&light, ft_strdup(line_1));
	TEST_ASSERT_EQUAL_DOUBLE(10, light.x);
	TEST_ASSERT_EQUAL_DOUBLE(10, light.y);
	TEST_ASSERT_EQUAL_DOUBLE(-10, light.z);
	set_coordinates(&light, ft_strdup(line_2));
	TEST_ASSERT_EQUAL_DOUBLE(0, light.x);
	TEST_ASSERT_EQUAL_DOUBLE(0, light.y);
	TEST_ASSERT_EQUAL_DOUBLE(0, light.z);
	set_coordinates(&light, ft_strdup(line_3));
	TEST_ASSERT_EQUAL_DOUBLE(0.1, light.x);
	TEST_ASSERT_EQUAL_DOUBLE(10.5, light.y);
	TEST_ASSERT_EQUAL_DOUBLE(40.3, light.z);
	set_coordinates(&light, ft_strdup(line_4));
	TEST_ASSERT_EQUAL_DOUBLE(255.0, light.x);
	TEST_ASSERT_EQUAL_DOUBLE(500.999, light.y);
	TEST_ASSERT_EQUAL_DOUBLE(10.00001, light.z);
	TEST_ASSERT_EQUAL_INT(1, set_coordinates(&light, ft_strdup("abc")));
	TEST_ASSERT_EQUAL_INT(1, set_coordinates(&light, ft_strdup("10,0,0.a")));
	TEST_ASSERT_EQUAL_INT(1, set_coordinates(&light, ft_strdup("10,0,0.0a")));
}

void	test_set_light_brightness(void)
{
	t_light	light;
	TEST_ASSERT_EQUAL_INT(0, set_brightness(&light, ft_strdup("1")));
	TEST_ASSERT_EQUAL_INT(1, light.brightness);
	TEST_ASSERT_EQUAL_INT(0, set_brightness(&light, ft_strdup("0.7")));
	TEST_ASSERT_EQUAL_INT(0.7, light.brightness);
	TEST_ASSERT_EQUAL_INT(0, set_brightness(&light, ft_strdup("0.0000000001")));
	TEST_ASSERT_EQUAL_INT(0.0000000001, light.brightness);
	TEST_ASSERT_EQUAL_INT(1, set_brightness(&light, ft_strdup("48")));
	TEST_ASSERT_EQUAL_INT(1, set_brightness(&light, ft_strdup("1.0000000001")));
}

void	test_set_light_rgb(void)
{
	t_light light;

	TEST_ASSERT_EQUAL_INT(1, set_light_rgb(&light, ft_strdup(line_1)));
	TEST_ASSERT_EQUAL_INT(0, set_light_rgb(&light, ft_strdup(line_2)));
	TEST_ASSERT_EQUAL_INT(0, light.rgb.red);
	TEST_ASSERT_EQUAL_INT(0, light.rgb.green);
	TEST_ASSERT_EQUAL_INT(0, light.rgb.blue);
	TEST_ASSERT_EQUAL_INT(255, light.rgb.opacity);
	TEST_ASSERT_EQUAL_INT(1, set_light_rgb(&light, ft_strdup(line_3)));
	TEST_ASSERT_EQUAL_INT(1, set_light_rgb(&light, ft_strdup(line_4)));
	TEST_ASSERT_EQUAL_INT(0, set_light_rgb(&light, ft_strdup(line_5)));
	TEST_ASSERT_EQUAL_INT(255, light.rgb.red);
	TEST_ASSERT_EQUAL_INT(5, light.rgb.green);
	TEST_ASSERT_EQUAL_INT(2, light.rgb.blue);
	TEST_ASSERT_EQUAL_INT(255, light.rgb.opacity);
	TEST_ASSERT_EQUAL_INT(1, set_light_rgb(&light, ft_strdup(line_6)));
}

void	test_check_light_function(void)
{
	TEST_ASSERT_EQUAL_INT(0, check_light(full_line_1));
	TEST_ASSERT_EQUAL_INT(0, check_light(full_line_1));
	TEST_ASSERT_EQUAL_INT(0, check_light(full_line_1));
	TEST_ASSERT_EQUAL_INT(0, check_light(full_line_1));
}

void test_check_light(void)
{
	RUN_TEST(test_set_light_coordinates);
	RUN_TEST(test_set_light_brightness);
	RUN_TEST(test_set_light_rgb);
	RUN_TEST(test_check_light_function);
}