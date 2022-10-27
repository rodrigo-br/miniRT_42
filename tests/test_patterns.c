#include <tests.h>

/*
Scenario: Creating a stripe pattern
Given pattern ← stripe_pattern(white, black)
Then pattern.a = white
And pattern.b = black
*/
void test_create_pattern(void)
{
	t_pattern	*pattern;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	TEST_ASSERT_EQUAL_DOUBLE(1, pattern->color_a->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, pattern->color_a->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, pattern->color_a->blue);
	TEST_ASSERT_EQUAL_DOUBLE(0, pattern->color_b->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, pattern->color_b->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, pattern->color_b->blue);
	destroy_pattern(pattern);
}

/*
Scenario: A stripe pattern is constant in y
Given pattern ← stripe_pattern(white, black)
Then stripe_at(pattern, point(0, 0, 0)) = white
And stripe_at(pattern, point(0, 1, 0)) = white
And stripe_at(pattern, point(0, 2, 0)) = white
*/
void test_pattern_constant_y(void)
{
	t_pattern	*pattern;
	t_rgb		*color;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at(pattern, &(t_point){0, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 1, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 2, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_pattern(pattern);
}

/*
Scenario: A stripe pattern is constant in z
Given pattern ← stripe_pattern(white, black)
Then stripe_at(pattern, point(0, 0, 0)) = white
And stripe_at(pattern, point(0, 0, 1)) = white
And stripe_at(pattern, point(0, 0, 2)) = white
*/
void test_pattern_constant_z(void)
{
	t_pattern	*pattern;
	t_rgb		*color;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at(pattern, &(t_point){0, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 0, 1, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 0, 2, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_pattern(pattern);
}

/*
Scenario: A stripe pattern alternates in x
Given pattern ← stripe_pattern(white, black)
Then stripe_at(pattern, point(0, 0, 0)) = white
And stripe_at(pattern, point(0.9, 0, 0)) = white
And stripe_at(pattern, point(1, 0, 0)) = black
And stripe_at(pattern, point(-0.1, 0, 0)) = black
And stripe_at(pattern, point(-1, 0, 0)) = black
And stripe_at(pattern, point(-1.1, 0, 0)) = white
*/
void	test_pattern_alternate_x(void)
{
	t_pattern	*pattern;
	t_rgb		*color;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at(pattern, &(t_point){0, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0.9, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){1, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(0, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->blue);
	color = pattern_at(pattern, &(t_point){-0.1, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(0, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->blue);
	color = pattern_at(pattern, &(t_point){-1, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(0, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->blue);
	color = pattern_at(pattern, &(t_point){-1.1, 0, 0, 1});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_pattern(pattern);
}

/*
Scenario: Lighting with a pattern applied
Given m.pattern ← stripe_pattern(color(1, 1, 1), color(0, 0, 0))
And m.ambient ← 1
And m.diffuse ← 0
And m.specular ← 0
And eyev ← vector(0, 0, -1)
And normalv ← vector(0, 0, -1)
And light ← point_light(point(0, 0, -10), color(1, 1, 1))
When c1 ← lighting(m, light, point(0.9, 0, 0), eyev, normalv, false)
And c2 ← lighting(m, light, point(1.1, 0, 0), eyev, normalv, false)
Then c1 = color(1, 1, 1)
And c2 = color(0, 0, 0)
*/
void	test_pattern_lightning_with_pattern(void)
{
	t_material	*material;
	t_lightattr	*args;
	t_light_pnt	*lp;
	t_pos_attr	*pos;
	t_rgb		*color;

	pos = create_pos_attr(create_vector(0, 0, -1), create_vector(0, 0, -1), create_point(0.9, 0, 0));
	lp = create_light_point(create_point(0, 0, -10), create_color(1, 1, 1));
	material = create_material();
	material->pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	material->ambient = 1;
	material->diffuse = 0;
	material->specular = 0;
	args = create_lightattr(lp, pos, material);
	color = lighting(args);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_lightattr(args);
	free(color);
}

void test_patterns(void)
{
	RUN_TEST(test_create_pattern);
	RUN_TEST(test_pattern_constant_y);
	RUN_TEST(test_pattern_constant_z);
	RUN_TEST(test_pattern_alternate_x);
	RUN_TEST(test_pattern_lightning_with_pattern);
}