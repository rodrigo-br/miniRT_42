#include <tests.h>

/*
Scenario: The default world
Given light ← point_light(point(-10, 10, -10), color(1, 1, 1))
And s1 ← sphere() with:
| material.color | (0.8, 1.0, 0.6) |
| material.diffuse | 0.7 |
| material.specular | 0.2 |
And s2 ← sphere() with:
| transform | scaling(0.5, 0.5, 0.5) |
When w ← default_world()
Then w.light = light
And w contains s1
And w contains s2
*/
void	test_create_world(void)
{
	t_world *w;
	t_light_pnt *lp;
	t_object	*sphere_1;
	t_object	*sphere_2;
	t_object	*object_1;
	t_object	*object_2;

	w = create_world();
	w->light_point = ft_lstnew(create_light_point(create_point(-10, 10, -10), create_color(1, 1, 1)));
	object_1 = create_sphere();
	free(object_1->material->color);
	object_1->material->color = create_color(0.8, 1.0, 0.6);
	object_1->material->diffuse = 0.7;
	object_1->material->specular = 0.2;
	w->objects = ft_lstnew(object_1);
	object_2 = create_sphere();
	set_transformation(object_2, scale_matrix(0.5, 0.5, 0.5));
	ft_lstadd_front(&w->objects, ft_lstnew(object_2));
	lp = (t_light_pnt *)w->light_point->content;
	sphere_1 = (t_object *)w->objects->content;
	sphere_2 = (t_object *)w->objects->next->content;
	TEST_ASSERT_TRUE(lp);
	TEST_ASSERT_TRUE(sphere_1);
	TEST_ASSERT_TRUE(sphere_2);
	destroy_world(w);
}

/*
Scenario: Intersect a world with a ray
Given w ← default_world()
And r ← ray(point(0, 0, -5), vector(0, 0, 1))
When xs ← intersect_world(w, r)
Then xs.count = 4
And xs[0].t = 4
And xs[1].t = 4.5
And xs[2].t = 5.5
And xs[3].t = 6
*/
void	test_intersect_world(void)
{
	t_world *w;
	t_light_pnt *lp;
	t_ray		*ray;
	t_object	*sphere_1;
	t_object	*sphere_2;
	t_object	*object_1;
	t_object	*object_2;
	t_intersect	*xs;

	xs = NULL;
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	w = create_world();
	w->light_point = ft_lstnew(create_light_point(create_point(-10, 10, -10), create_color(1, 1, 1)));
	object_1 = create_sphere();
	free(object_1->material->color);
	object_1->material->color = create_color(0.8, 1.0, 0.6);
	object_1->material->diffuse = 0.7;
	object_1->material->specular = 0.2;
	w->objects = ft_lstnew(object_1);
	object_2 = create_sphere();
	set_transformation(object_2, scale_matrix(0.5, 0.5, 0.5));
	ft_lstadd_front(&w->objects, ft_lstnew(object_2));
	lp = (t_light_pnt *)w->light_point->content;
	sphere_1 = (t_object *)w->objects->content;
	sphere_2 = (t_object *)w->objects->next->content;
	intersect_world(w, ray, &xs);
	TEST_ASSERT_EQUAL(4, intersection_list_size(xs));
	TEST_ASSERT_EQUAL_DOUBLE(4, xs->time);
	TEST_ASSERT_EQUAL_DOUBLE(4.5, xs->next->time);
	TEST_ASSERT_EQUAL_DOUBLE(5.5, xs->next->next->time);
	TEST_ASSERT_EQUAL_DOUBLE(6, xs->next->next->next->time);
	intersection_list_clear(&xs);
	destroy_ray(ray);
	destroy_world(w);
}

/*
Scenario: Precomputing the state of an intersection
Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
And shape ← sphere()
And i ← intersection(4, shape)
When comps ← prepare_computations(i, r)
Then comps.t = i.t
And comps.object = i.object
And comps.point = point(0, 0, -1)
And comps.eyev = vector(0, 0, -1)
And comps.normalv = vector(0, 0, -1)
*/
void test_prepare_computation(void)
{
	t_ray		*ray;
	t_object	*obj;
	t_intersect	*i;
	t_comp		*comps;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	obj = create_sphere();
	i = create_intersection(4, obj);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_EQUAL_DOUBLE(i->time, comps->time);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_tuple){0, 0, -1, 1}, comps->point));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_tuple){0, 0, -1, 0}, comps->camera));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_tuple){0, 0, -1, 0}, comps->normal));
	destroy_computation(comps);
	destroy_ray(ray);
	destroy_shape(obj);
	intersection_list_clear(&i);
}

/*
Scenario: The hit, when an intersection occurs on the outside
Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
And shape ← sphere()
And i ← intersection(4, shape)
When comps ← prepare_computations(i, r)
Then comps.inside = false
*/
void	test_hit_when_intersection_outside(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*i;
	t_comp		*comps;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	sphere = create_sphere();
	i = create_intersection(4, sphere);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_FALSE(comps->inside);
	destroy_computation(comps);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&i);
}

/*
Scenario: The hit, when an intersection occurs on the inside
Given r ← ray(point(0, 0, 0), vector(0, 0, 1))
And shape ← sphere()
And i ← intersection(1, shape)
When comps ← prepare_computations(i, r)
Then comps.point = point(0, 0, 1)
And comps.eyev = vector(0, 0, -1)
And comps.inside = true
And comps.normalv = vector(0, 0, -1)
*/
void	test_hit_when_intersection_inside(void)
{
	t_ray		*ray;
	t_object	*sphere;
	t_intersect	*i;
	t_comp		*comps;

	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	sphere = create_sphere();
	i = create_intersection(1, sphere);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_tuple){0, 0, 1, 1}, comps->point));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_tuple){0, 0, -1, 0}, comps->camera));
	TEST_ASSERT_TRUE(comps->inside);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_tuple){0, 0, -1, 0}, comps->normal));
	destroy_computation(comps);
	destroy_ray(ray);
	destroy_shape(sphere);
	intersection_list_clear(&i);
}

/*
Scenario: Shading an intersection
Given w ← default_world()
And r ← ray(point(0, 0, -5), vector(0, 0, 1))
And shape ← the first object in w
And i ← intersection(4, shape)
When comps ← prepare_computations(i, r)
And c ← shade_hit(w, comps)
Then c = color(0.38066, 0.47583, 0.2855)
*/
void	test_shading_an_intersection(void)
{
	t_world		*w;
	t_object	*shape;
	t_ray		*ray;
	t_intersect	*i;
	t_comp		*comps;
	t_rgb		*rgb;

	w = create_world();
	w->light_point = ft_lstnew(create_light_point(create_point(-10, 10, -10), create_color(1, 1, 1)));
	shape = create_sphere();
	free(shape->material->color);
	shape->material->color = create_color(0.8, 1.0, 0.6);
	shape->material->diffuse = 0.7;
	shape->material->specular = 0.2;
	w->objects = ft_lstnew(shape);
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	i = create_intersection(4, shape);
	comps = prepare_computation(i, ray);
	rgb = shade_hit(w, comps);
	TEST_ASSERT_TRUE(is_equal_double(0.38066, rgb->red));
	TEST_ASSERT_TRUE(is_equal_double(0.47583, rgb->green));
	TEST_ASSERT_TRUE(is_equal_double(0.2855, rgb->blue));
	destroy_world(w);
	destroy_computation(comps);
	free(rgb);
	destroy_ray(ray);
	intersection_list_clear(&i);
}

void	test_world(void)
{
	RUN_TEST(test_create_world);
	RUN_TEST(test_intersect_world);
	RUN_TEST(test_prepare_computation);
	RUN_TEST(test_hit_when_intersection_outside);
	RUN_TEST(test_hit_when_intersection_inside);
	RUN_TEST(test_shading_an_intersection);
}