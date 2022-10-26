#include <tests.h>

#define DEFAULT_AMBIENT 0.1
#define DEFAULT_DIFFUSE 0.9
#define DEFAULT_SPECULAR 0.9
#define DEFAULT_SHININESS 200.0


t_object	*create_shape(void)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	object->transformation = create_identity_matrix();
	object->inverse_transformation = create_identity_matrix();
	object->material = create_material();
	return (object);
}

/*
Scenario: The default transformation
Given s ← test_shape()
Then s.transform = identity_matrix
*/
void test_shape_default_transform(void)
{
	t_object	*s;
	t_matrix	*identity;

	s = create_shape();
	identity = create_identity_matrix();
	TEST_ASSERT_TRUE(is_equal_matrix(s->transformation, identity));
	destroy_shape(s);
	free(identity);
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

	s = create_shape();
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

	s = create_shape();
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

void test_shape(void)
{
	RUN_TEST(test_shape_default_transform);
	RUN_TEST(test_shape_default_material);
	RUN_TEST(test_shape_assign_material);
}