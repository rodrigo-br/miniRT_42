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
	t_object	*obj;

	obj = create_sphere();
	pos = create_pos_attr(create_vector(0, 0, -1), create_vector(0, 0, -1), create_point(0.9, 0, 0));
	lp = create_light_point(create_point(0, 0, -10), create_color(1, 1, 1));
	material = create_material();
	material->pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	material->ambient = 1;
	material->diffuse = 0;
	material->specular = 0;
	args = create_lightattr(lp, pos, material);
	args->object = obj;
	color = lighting(args);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_lightattr(args);
	free(color);
}

/*
Scenario: Stripes with an object transformation
Given object ← sphere()
And set_transform(object, scaling(2, 2, 2))
And pattern ← stripe_pattern(white, black)
When c ← stripe_at_object(pattern, object, point(1.5, 0, 0))
Then c = white
*/
void test_pattern_with_object_transformation(void)
{
	t_object	*object;
	t_pattern	*pattern;
	t_rgb		*color;

	object = create_sphere();
	set_object_transformation(object, scale_matrix(2, 2, 2));
	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at_obj(pattern, &(t_point){1.5, 0, 0, 1}, object);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_pattern(pattern);
	destroy_shape(object);
}

/*
Scenario: Stripes with a pattern transformation
Given object ← sphere()
And pattern ← stripe_pattern(white, black)
And set_pattern_transform(pattern, scaling(2, 2, 2))
When c ← stripe_at_object(pattern, object, point(1.5, 0, 0))
Then c = white
*/
void	test_pattern_with_pattern_transformation(void)
{
	t_object	*object;
	t_pattern	*pattern;
	t_rgb		*color;

	object = create_sphere();
	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	set_pattern_transformation(pattern, scale_matrix(2, 2, 2));
	color = pattern_at_obj(pattern, &(t_point){1.5, 0, 0, 1}, object);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_pattern(pattern);
	destroy_shape(object);
}

/*
Scenario: Stripes with both an object and a pattern transformation
Given object ← sphere()
And set_transform(object, scaling(2, 2, 2))
And pattern ← stripe_pattern(white, black)
And set_pattern_transform(pattern, translation(0.5, 0, 0))
When c ← stripe_at_object(pattern, object, point(2.5, 0, 0))
Then c = white
*/
void	test_pattern_with_pattern_n_obj_transformation(void)
{
	t_object	*object;
	t_pattern	*pattern;
	t_rgb		*color;

	object = create_sphere();
	set_object_transformation(object, scale_matrix(2, 2, 2));
	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	set_pattern_transformation(pattern, translate_matrix(0.5, 0, 0));
	color = pattern_at_obj(pattern, &(t_point){2.5, 0, 0, 1}, object);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	destroy_pattern(pattern);
	destroy_shape(object);
}

/*
Scenario: Checkers should repeat in x
Given pattern ← checkers_pattern(white, black)
Then pattern_at(pattern, point(0, 0, 0)) = white
And pattern_at(pattern, point(0.99, 0, 0)) = white
And pattern_at(pattern, point(1.01, 0, 0)) = black
*/
void	checkers_should_repeat_in_x(void)
{
	t_pattern	*pattern;
	t_rgb		*color;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at(pattern, &(t_point){0, 0, 0});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0.99, 0, 0});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){1.01, 0, 0});
	TEST_ASSERT_EQUAL_DOUBLE(0, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->blue);
	destroy_pattern(pattern);
}

/*
Scenario: Checkers should repeat in y
Given pattern ← checkers_pattern(white, black)
Then pattern_at(pattern, point(0, 0, 0)) = white
And pattern_at(pattern, point(0, 0.99, 0)) = white
And pattern_at(pattern, point(0, 1.01, 0)) = black
*/
void	checkers_should_repeat_in_y(void)
{
	t_pattern	*pattern;
	t_rgb		*color;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at(pattern, &(t_point){0, 0, 0});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 0.99, 0});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 1.01, 0});
	TEST_ASSERT_EQUAL_DOUBLE(0, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->blue);
	destroy_pattern(pattern);
}

/*
Scenario: Checkers should repeat in z
Given pattern ← checkers_pattern(white, black)
Then pattern_at(pattern, point(0, 0, 0)) = white
And pattern_at(pattern, point(0, 0, 0.99)) = white
And pattern_at(pattern, point(0, 0, 1.01)) = black
*/
void	checkers_should_repeat_in_z(void)
{
	t_pattern	*pattern;
	t_rgb		*color;

	pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	color = pattern_at(pattern, &(t_point){0, 0, 0});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 0, 0.99});
	TEST_ASSERT_EQUAL_DOUBLE(1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(1, color->blue);
	color = pattern_at(pattern, &(t_point){0, 0, 1.01});
	TEST_ASSERT_EQUAL_DOUBLE(0, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0, color->blue);
	destroy_pattern(pattern);
}

void test_patterns(void)
{
	// RUN_TEST(test_create_pattern);
	// RUN_TEST(test_pattern_constant_y);
	// RUN_TEST(test_pattern_constant_z);
	// RUN_TEST(test_pattern_alternate_x);
	// RUN_TEST(test_pattern_lightning_with_pattern);
	// RUN_TEST(test_pattern_with_object_transformation);
	// RUN_TEST(test_pattern_with_pattern_transformation);
	// RUN_TEST(test_pattern_with_pattern_n_obj_transformation);
	RUN_TEST(checkers_should_repeat_in_x);
	RUN_TEST(checkers_should_repeat_in_y);
	RUN_TEST(checkers_should_repeat_in_z);
}