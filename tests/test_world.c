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
	t_world		*w;
	t_light_pnt	*lp;
	t_object	*sphere_1;
	t_object	*sphere_2;

	w = default_world();
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
	t_world 	*w;
	t_ray		*ray;
	t_intersect	*xs;

	w = default_world();
	xs = NULL;
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
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

	w = default_world();
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	shape = (t_object *)w->objects->content;
	i = create_intersection(4, shape);
	comps = prepare_computation(i, ray);
	rgb = shade_hit(w, comps);
	// TEST_ASSERT_EQUAL_DOUBLE(0.38066, rgb->red);
	// TEST_ASSERT_EQUAL_DOUBLE(0.47583, rgb->green);
	// TEST_ASSERT_EQUAL_DOUBLE(0.2855, rgb->blue);
	TEST_ASSERT_TRUE(is_equal_double(0.38066, rgb->red));
	TEST_ASSERT_TRUE(is_equal_double(0.47583, rgb->green));
	TEST_ASSERT_TRUE(is_equal_double(0.2855, rgb->blue));
	destroy_world(w);
	destroy_computation(comps);
	free(rgb);
	destroy_ray(ray);
	intersection_list_clear(&i);
}

/*
Scenario: Shading an intersection from the inside
Given w ← default_world()
And w.light ← point_light(point(0, 0.25, 0), color(1, 1, 1))
And r ← ray(point(0, 0, 0), vector(0, 0, 1))
And shape ← the second object in w
And i ← intersection(0.5, shape)
When comps ← prepare_computations(i, r)
And c ← shade_hit(w, comps)
Then c = color(0.90498, 0.90498, 0.90498)
*/
void	test_shading_an_intersection_from_inside(void)
{
	t_world		*w;
	t_object	*shape;
	t_ray		*ray;
	t_intersect	*i;
	t_comp		*comps;
	t_rgb		*rgb;

	w = default_world();
	ft_lstclear(&w->light_point, destroy_light_point);
	w->light_point = ft_lstnew(create_light_point(create_point(0, 0.25, 0), create_color(1, 1, 1)));
	ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	shape = (t_object *)w->objects->next->content;
	i = create_intersection(0.5, shape);
	comps = prepare_computation(i, ray);
	rgb = shade_hit(w, comps);
	TEST_ASSERT_TRUE(is_equal_double(0.90498, rgb->red));
	TEST_ASSERT_TRUE(is_equal_double(0.90498, rgb->green));
	TEST_ASSERT_TRUE(is_equal_double(0.90498, rgb->blue));
	destroy_world(w);
	destroy_computation(comps);
	free(rgb);
	destroy_ray(ray);
	intersection_list_clear(&i);
}

/*
Scenario: The color when a ray misses
Given w ← default_world()
And r ← ray(point(0, 0, -5), vector(0, 1, 0))
When c ← color_at(w, r)
Then c = color(0, 0, 0)
*/
void	test_color_when_ray_misses(void)
{
	t_world		*w;
	t_ray		*ray;
	t_rgb		*rgb;

	w = default_world();
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 1, 0));
	rgb = color_at(w, ray);
	TEST_ASSERT_TRUE(is_equal_double(0, rgb->red));
	TEST_ASSERT_TRUE(is_equal_double(0, rgb->green));
	TEST_ASSERT_TRUE(is_equal_double(0, rgb->blue));
	destroy_world(w);
	destroy_ray(ray);
	free(rgb);
}

/*
Scenario: The color when a ray hits
Given w ← default_world()
And r ← ray(point(0, 0, -5), vector(0, 0, 1))
When c ← color_at(w, r)
Then c = color(0.38066, 0.47583, 0.2855)
*/
void	test_color_when_ray_hits(void)
{
	t_world		*w;
	t_ray		*ray;
	t_rgb		*rgb;

	w = default_world();
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	rgb = color_at(w, ray);
	TEST_ASSERT_TRUE(is_equal_double(0.38066, rgb->red));
	TEST_ASSERT_TRUE(is_equal_double(0.47583, rgb->green));
	TEST_ASSERT_TRUE(is_equal_double(0.2855, rgb->blue));
	destroy_world(w);
	destroy_ray(ray);
	free(rgb);
}

/*
Scenario: The color with an intersection behind the ray
Given w ← default_world()
And outer ← the first object in w
And outer.material.ambient ← 1
And inner ← the second object in w
And inner.material.ambient ← 1
And r ← ray(point(0, 0, 0.75), vector(0, 0, -1))
When c ← color_at(w, r)
Then c = inner.material.color
*/
void	test_color_when_intersect_behind_ray(void)
{
	t_world		*w;
	t_ray		*ray;
	t_rgb		*rgb;
	t_object	*outer, *inner;

	w = default_world();
	outer = (t_object *)w->objects->content;
	outer->material->ambient = 1.0;
	inner = (t_object *)w->objects->next->content;
	inner->material->ambient = 1.0;
	ray = create_ray(create_point(0, 0, 0.75), create_vector(0, 0, -1));
	rgb = color_at(w, ray);
	TEST_ASSERT_TRUE(is_equal_double(inner->material->color->red, rgb->red));
	TEST_ASSERT_TRUE(is_equal_double(inner->material->color->green, rgb->green));
	TEST_ASSERT_TRUE(is_equal_double(inner->material->color->blue, rgb->blue));
	destroy_world(w);
	destroy_ray(ray);
	free(rgb);
}

/* Scenario: shade_hit() is given an intersection in shadow
Given w ← world()
And w.light ← point_light(point(0, 0, -10), color(1, 1, 1))
And s1 ← sphere()
And s1 is added to w
And s2 ← sphere() with:
| transform | translation(0, 0, 10) |
And s2 is added to w
And r ← ray(point(0, 0, 5), vector(0, 0, 1))
And i ← intersection(4, s2)
When comps ← prepare_computations(i, r)
And c ← shade_hit(w, comps)
Then c = color(0.1, 0.1, 0.1) */
void	test_shade_hit_shadow_intersection(void)
{
	t_world		*world;
	t_object	*s1, *s2;
	t_ray		*ray;
	t_intersect	*i;
	t_comp		*comps;
	t_rgb		*color;

	world = create_world();
	world->light_point = ft_lstnew(create_light_point(create_point(0, 0, -10), create_color(1, 1, 1)));
	s1 = create_sphere();
	s2 = create_sphere();
	set_object_transformation(s2, translate_matrix(0, 0, 10));
	ft_lstadd_front(&world->objects, ft_lstnew(s1));
	ft_lstadd_front(&world->objects, ft_lstnew(s2));
	ray = create_ray(create_point(0, 0, 5), create_vector(0, 0, 1));
	i = create_intersection(4, s2);
	comps = prepare_computation(i, ray);
	color = shade_hit(world, comps);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, color->red);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, color->green);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, color->blue);
	destroy_world(world);
	destroy_ray(ray);
	destroy_computation(comps);
	free(color);
	intersection_list_clear(&i);
}

/* Scenario: The hit should offset the point
Given r ← ray(point(0, 0, -5), vector(0, 0, 1))
And shape ← sphere() with:
| transform | translation(0, 0, 1) |
And i ← intersection(5, shape)
When comps ← prepare_computations(i, r)
Then comps.over_point.z < -EPSILON/2
And comps.point.z > comps.over_point.z */
void	test_hit_should_offset_point(void)
{
	t_ray		*ray;
	t_object	*shape;
	t_intersect	*i;
	t_comp		*comps;

	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	shape = create_sphere();
	set_object_transformation(shape, translate_matrix(0, 0, 1));
	i = create_intersection(5, shape);
	comps = prepare_computation(i, ray);
	TEST_ASSERT_TRUE(comps->over_point->z < -EPSILON / 2);
	TEST_ASSERT_TRUE(comps->point->z > comps->over_point->z);
	destroy_ray(ray);
	destroy_shape(shape);
	destroy_computation(comps);
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
	RUN_TEST(test_shading_an_intersection_from_inside);
	RUN_TEST(test_color_when_ray_misses);
	RUN_TEST(test_color_when_ray_hits);
	RUN_TEST(test_color_when_intersect_behind_ray);
	RUN_TEST(test_shade_hit_shadow_intersection);
	RUN_TEST(test_hit_should_offset_point);
}
