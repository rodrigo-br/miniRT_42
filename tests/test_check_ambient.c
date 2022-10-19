#include "unity/unity.h"
#include <minirt.h>

# define line_1 "10.0,10.0,-10.0"
# define line_2 "0,0,0"
# define line_3 "0.1,10.5,40.3"
# define line_4 "255.0,500.999,10.00001"
# define line_5 "255,5,2"
# define line_6 "255,5,-2"
# define full_line_1 "L 10,10,-10 1 250,250,250"
# define full_line_2 "A 0.2 255,255,255"
# define full_line_3 "A 1 0,50,200"

void	test_check_ambient_function(void)
{
	t_ambience 	*ambient;
	char		**splited;

	splited = ft_split(full_line_1, ' ');
	TEST_ASSERT_EQUAL_INT(1, check_ambient(splited, &ambient));
	ft_free_matrix((void *)&splited);
	splited = ft_split(full_line_2, ' ');
	TEST_ASSERT_EQUAL_INT(0, check_ambient(splited, &ambient));
	ft_free_matrix((void *)&splited);
	free(ambient->rgb);
	free(ambient);
	splited = ft_split(full_line_3, ' ');
	TEST_ASSERT_EQUAL_INT(0, check_ambient(splited, &ambient));
	ft_free_matrix((void *)&splited);
	free(ambient->rgb);
	free(ambient);
}

void test_check_ambient(void)
{
	RUN_TEST(test_check_ambient_function);
}
