#include <tests.h>

#define DEFAULT_AMBIENT 0.1
#define DEFAULT_DIFFUSE 0.9
#define DEFAULT_SPECULAR 0.9
#define DEFAULT_SHININESS 200.0

/*
Scenario: The default transformation
Given s ← test_shape()
Then s.transform = identity_matrix
*/
void test_shape_default_transform(void)
{
	t_object	*s;
	t_matrix	*identity;

	s = create_sphere();
	identity = create_identity_matrix();
	TEST_ASSERT_TRUE(is_equal_matrix(s->transformation, identity));
	destroy_shape(s);
	free(identity);
}

/*
Scenario: Assigning a transformation
Given s ← test_shape()
When set_transform(s, translation(2, 3, 4))
Then s.transform = translation(2, 3, 4)
*/
void	test_shape_assign_transform(void)
{
	t_object	*s;
	t_matrix	*translated;

	s = create_sphere();
	translated = translate_matrix(2, 3, 4);
	set_object_transformation(s, translated);
	TEST_ASSERT_TRUE(is_equal_matrix(s->transformation, translated));
	destroy_shape(s);
}

/*
Scenario: The default material
Given s ← test_shape()
When m ← s.material
Then m = material()
*/
void	test_shape_default_material(void)
{
	t_object	*s;
	t_material	*m;

	s = create_sphere();
	m = s->material;
	TEST_ASSERT_TRUE(m->ambient == DEFAULT_AMBIENT);
	TEST_ASSERT_TRUE(m->diffuse == DEFAULT_DIFFUSE);
	TEST_ASSERT_TRUE(m->specular == DEFAULT_SPECULAR);
	TEST_ASSERT_TRUE(m->shininess == DEFAULT_SHININESS);
	destroy_shape(s);
}

/*
Scenario: Assigning a material
Given s ← test_shape()
And m ← material()
And m.ambient ← 1
When s.material ← m
Then s.material = m
*/
void test_shape_assign_material(void)
{
	t_object	*s;
	t_material	*m;

	s = create_sphere();
	m = create_material();
	m->ambient = 1;
	destroy_material(s->material);
	s->material = m;
	TEST_ASSERT_TRUE(s->material->ambient == 1);
	TEST_ASSERT_TRUE(s->material->diffuse == DEFAULT_DIFFUSE);
	TEST_ASSERT_TRUE(s->material->specular == DEFAULT_SPECULAR);
	TEST_ASSERT_TRUE(s->material->shininess == DEFAULT_SHININESS);
	destroy_shape(s);
}

/*
Scenario: Intersecting a scaled shape with a ray
Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
And s ← test_shape()
When set_transform(s, scaling(2, 2, 2))
And xs ← intersect(s, r)
Then s.saved_ray.origin = point(0, 0, -2.5)
And s.saved_ray.direction = vector(0, 0, 0.5)
*/
void	test_shape_intersect_with_ray(void)
{
	t_ray		*r;
	t_object	*s;
	t_intersect	*xs;

	xs = (t_intersect *)ft_calloc(1, sizeof(t_intersect));
	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	s = create_sphere();
	set_object_transformation(s, scale_matrix(2, 2, 2));
	intersect_sphere(s, r, &xs);
	TEST_ASSERT_TRUE(is_equal_tuple(s->saved_ray->origin, &(t_tuple){0, 0, -2.5, 1}));
	TEST_ASSERT_TRUE(is_equal_tuple(s->saved_ray->direction, &(t_tuple){0, 0, 0.5, 0}));
	intersection_list_clear(&xs);
	destroy_ray(r);
	destroy_shape(s);
}

void test_shape(void)
{
	RUN_TEST(test_shape_default_transform);
	RUN_TEST(test_shape_assign_transform);
	RUN_TEST(test_shape_default_material);
	RUN_TEST(test_shape_assign_material);
	RUN_TEST(test_shape_intersect_with_ray);
}