#include "unity/unity.h"
#include <minirt.h>

# define line_1 "10.0,10.0,-10.0"
# define line_2 "0,0,0"
# define line_3 "0.1,10.5,40.3"
# define line_4 "255.0,500.999,10.00001"
# define line_5 "255,5,2"
# define line_6 "255,5,-2"
# define full_line_1 ft_split("L 10,10,-10 1 250,250,250", ' ')
# define full_line_2 ft_split("A 0.2 255,255,255", ' ')
# define full_line_3 ft_split("A 1 0,50,200", ' ')

void	test_set_ambient_rgb(void)
{
	t_ambience ambient;

	ambient.rgb.opacity = 255;
	TEST_ASSERT_EQUAL_INT(1, set_object_rgb(&ambient.rgb.red, &ambient.rgb.green, &ambient.rgb.blue, ft_strdup(line_1)));
	TEST_ASSERT_EQUAL_INT(0, set_object_rgb(&ambient.rgb.red, &ambient.rgb.green, &ambient.rgb.blue, ft_strdup(line_2)));
	TEST_ASSERT_EQUAL_CHAR(0, ambient.rgb.red);
	TEST_ASSERT_EQUAL_CHAR(0, ambient.rgb.green);
	TEST_ASSERT_EQUAL_CHAR(0, ambient.rgb.blue);
	TEST_ASSERT_EQUAL_CHAR(255, ambient.rgb.opacity);
	TEST_ASSERT_EQUAL_INT(1, set_object_rgb(&ambient.rgb.red, &ambient.rgb.green, &ambient.rgb.blue, ft_strdup(line_3)));
	TEST_ASSERT_EQUAL_INT(1, set_object_rgb(&ambient.rgb.red, &ambient.rgb.green, &ambient.rgb.blue, ft_strdup(line_4)));
	TEST_ASSERT_EQUAL_INT(0, set_object_rgb(&ambient.rgb.red, &ambient.rgb.green, &ambient.rgb.blue, ft_strdup(line_5)));
	TEST_ASSERT_EQUAL_CHAR(255, ambient.rgb.red);
	TEST_ASSERT_EQUAL_CHAR(5, ambient.rgb.green);
	TEST_ASSERT_EQUAL_CHAR(2, ambient.rgb.blue);
	TEST_ASSERT_EQUAL_CHAR(255, ambient.rgb.opacity);
	TEST_ASSERT_EQUAL_INT(1, set_object_rgb(&ambient.rgb.red, &ambient.rgb.green, &ambient.rgb.blue, ft_strdup(line_6)));
}

void test_set_ambient_ratio(void)
{
	t_ambience ambient;
	TEST_ASSERT_EQUAL_INT(0, set_ambient_light_ratio(&ambient, ft_strdup("1")));
	TEST_ASSERT_EQUAL_DOUBLE(1, ambient.ratio);
	TEST_ASSERT_EQUAL_INT(0, set_ambient_light_ratio(&ambient, ft_strdup("0.7")));
	TEST_ASSERT_EQUAL_DOUBLE(0.7, ambient.ratio);
	TEST_ASSERT_EQUAL_INT(0, set_ambient_light_ratio(&ambient, ft_strdup("0.0000000001")));
	TEST_ASSERT_EQUAL_DOUBLE(0.0000000001, ambient.ratio);
	TEST_ASSERT_EQUAL_INT(1, set_ambient_light_ratio(&ambient, ft_strdup("48")));
	TEST_ASSERT_EQUAL_INT(1, set_ambient_light_ratio(&ambient, ft_strdup("1.0000000001")));
}

void	test_check_ambient_function(void)
{
	TEST_ASSERT_EQUAL_INT(1, check_ambient(full_line_1));
	TEST_ASSERT_EQUAL_INT(0, check_ambient(full_line_2));
	TEST_ASSERT_EQUAL_INT(0, check_ambient(full_line_3));
}

void test_check_ambient(void)
{
	RUN_TEST(test_set_ambient_ratio);
	RUN_TEST(test_set_ambient_rgb);
	RUN_TEST(test_check_ambient_function);
}
