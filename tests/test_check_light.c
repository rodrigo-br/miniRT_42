#include "unity/unity.h"
#include <minirt.h>

# define line_1 "10.0,10.0,-10.0"
# define line_2 "0,0,0"
# define line_3 "0.1,10.5,40.3"
# define line_4 "255.0,500.999,10.00001"
# define line_5 "255,5,2"
# define line_6 "255,5,-2"
# define full_line_1 "L 10,10,-10 1 250,250,250"
# define full_line_2 "L 10,10,-10 1 0,1,255"
# define full_line_3 "L 10,10,-10 1 0,0,0"
# define full_line_4 "L 10,10,-10 1 0,0,-1"
# define full_line_5 "L 10,10,-10 1 0,0,256"
# define full_line_6 "L 10.0.,10,-10 1 0,0,0"
# define full_line_7 "L 10.0,10,-10 2 0,0,0"

void	test_check_light_function(void)
{
	t_light 	*light;
	char		**splited;

	splited = ft_split(full_line_1, ' ');
	TEST_ASSERT_EQUAL_INT(0, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
	free(light->rgb);
	free(light);
	splited = ft_split(full_line_2, ' ');
	TEST_ASSERT_EQUAL_INT(0, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
	free(light->rgb);
	free(light);
	splited = ft_split(full_line_3, ' ');
	TEST_ASSERT_EQUAL_INT(0, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
	free(light->rgb);
	free(light);
	splited = ft_split(full_line_4, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_5, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_6, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_7, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_light(splited, &light));
	ft_free_matrix((void *)&splited);
}

void test_check_light(void)
{
	RUN_TEST(test_check_light_function);
}
