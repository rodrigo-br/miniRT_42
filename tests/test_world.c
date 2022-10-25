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

void	test_world(void)
{
	RUN_TEST(test_create_world);
	RUN_TEST(test_intersect_world);
}