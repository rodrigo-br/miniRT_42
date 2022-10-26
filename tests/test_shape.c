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

/* Scenario: The normal of a plane is constant everywhere
Given p ← plane()
When n1 ← local_normal_at(p, point(0, 0, 0))
And n2 ← local_normal_at(p, point(10, 0, -10))
And n3 ← local_normal_at(p, point(-5, 0, 150))
Then n1 = vector(0, 1, 0)
And n2 = vector(0, 1, 0)
And n3 = vector(0, 1, 0) */
void	test_check_normal_of_a_plane(void)
{
	t_object	*plane;
	t_vector	*n1, *n2, *n3;

	plane = create_plane();
	n1 = plane->get_normal(plane, &(t_point){0, 0, 0, 1});
	n2 = plane->get_normal(plane, &(t_point){10, 0, -10, 1});
	n3 = plane->get_normal(plane, &(t_point){-5, 0, 150, 1});
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, n1));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, n2));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 1, 0, 0}, n3));
	free(n1); free(n2); free(n3);
	destroy_shape(plane);
}

/* Scenario: Intersect with a ray parallel to the plane
Given p ← plane()
And r ← ray(point(0, 10, 0), vector(0, 0, 1))
When xs ← local_intersect(p, r)
Then xs is empty */
void	test_intersect_ray_parallel_to_plane(void)
{
	t_object	*plane;
	t_ray		*ray;
	t_intersect	*xs;

	plane = create_plane();
	ray = create_ray(create_point(0, 10, 0), create_vector(0, 0, 1));
	xs = NULL;
	plane->intersect(plane, ray, &xs);
	TEST_ASSERT_NULL(xs);
	destroy_shape(plane);
	destroy_ray(ray);
	intersection_list_clear(&xs);
}

/* Scenario: Intersect with a coplanar ray
Given p ← plane()
And r ← ray(point(0, 0, 0), vector(0, 0, 1))
When xs ← local_intersect(p, r)
Then xs is empty */
void	test_intersect_plane_coplanar_ray(void)
{
	t_object	*plane;
	t_ray		*ray;
	t_intersect	*xs;

	plane = create_plane();
	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	xs = NULL;
	plane->intersect(plane, ray, &xs);
	TEST_ASSERT_NULL(xs);
	destroy_shape(plane);
	destroy_ray(ray);
	intersection_list_clear(&xs);
}

/* Scenario: A ray intersecting a plane from above
Given p ← plane()
And r ← ray(point(0, 1, 0), vector(0, -1, 0))
When xs ← local_intersect(p, r)
Then xs.count = 1
And xs[0].t = 1
And xs[0].object = p */
void	test_ray_intersect_plane_from_above(void)
{
	t_object	*plane;
	t_ray		*ray;
	t_intersect	*xs;

	plane = create_plane();
	ray = create_ray(create_point(0, 1, 0), create_vector(0, -1, 0));
	xs = NULL;
	plane->intersect(plane, ray, &xs);
	TEST_ASSERT_EQUAL(1, intersection_list_size(xs));
	TEST_ASSERT_EQUAL_DOUBLE(1, xs->time);
	TEST_ASSERT_EQUAL_PTR(plane, xs->object);
	destroy_shape(plane);
	destroy_ray(ray);
	intersection_list_clear(&xs);
}

/* Scenario: A ray intersecting a plane from below
Given p ← plane()
And r ← ray(point(0, -1, 0), vector(0, 1, 0))
When xs ← local_intersect(p, r)
Then xs.count = 1
And xs[0].t = 1
And xs[0].object = p */
void	test_ray_intersect_plane_from_below(void)
{
	t_object	*plane;
	t_ray		*ray;
	t_intersect	*xs;

	plane = create_plane();
	ray = create_ray(create_point(0, -1, 0), create_vector(0, 1, 0));
	xs = NULL;
	plane->intersect(plane, ray, &xs);
	TEST_ASSERT_EQUAL(1, intersection_list_size(xs));
	TEST_ASSERT_EQUAL_DOUBLE(1, xs->time);
	TEST_ASSERT_EQUAL_PTR(plane, xs->object);
	destroy_shape(plane);
	destroy_ray(ray);
	intersection_list_clear(&xs);
}

void test_shape(void)
{
	RUN_TEST(test_shape_default_transform);
	RUN_TEST(test_shape_assign_transform);
	RUN_TEST(test_shape_default_material);
	RUN_TEST(test_shape_assign_material);
	RUN_TEST(test_check_normal_of_a_plane);
	RUN_TEST(test_intersect_ray_parallel_to_plane);
	RUN_TEST(test_intersect_plane_coplanar_ray);
	RUN_TEST(test_ray_intersect_plane_from_above);
	RUN_TEST(test_ray_intersect_plane_from_below);
}
