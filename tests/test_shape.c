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

/* Note to self:
	this leaks                              a lot.
	only run this if you have a display available.
*/
void	test_print_three_spheres_and_plane(void)
{
	t_object	*floor, *backdrop, *middle, *right, *left;
	t_matrix	*aux;
	t_world		*world;
	t_cam		*camera;
	t_canvas	*canvas;
	void		*win;

	floor = create_plane();
	floor->material->pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));

	backdrop = create_plane();
	backdrop->material->pattern = create_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	aux = translate_matrix(0, 0, 10);
	set_object_transformation(backdrop, multiply_matrix(aux, rotate_matrix_x(M_PI / 2)));
	free(aux);
	set_color(backdrop->material->color, 1, 0, 0);

	middle = create_sphere();
	middle->material->pattern = create_pattern(create_color(1, 0, 1), create_color(0, 0, 0));
	set_object_transformation(middle, translate_matrix(-0.5, 1, 0.5));
	set_color(middle->material->color, 0.1, 1, 0.5);
	middle->material->diffuse = 0.7;
	middle->material->specular = 0.3;

	right = create_sphere();
	right->material->pattern = create_pattern(create_color(0, 0, 1), create_color(0, 0, 0));
	aux = translate_matrix(1.5, 0.5, -0.5);
	set_object_transformation(right, multiply_matrix(aux, scale_matrix(0.5, 0.5, 0.5)));
	free(aux);
	set_color(right->material->color, 0.5, 1, 0.1);
	right->material->diffuse = 0.7;
	right->material->specular = 0.3;

	left = create_sphere();
	aux = translate_matrix(-1.5, 0.33, -0.75);
	set_object_transformation(left, multiply_matrix(aux, scale_matrix(0.33, 0.33, 0.33)));
	free(aux);
	set_color(left->material->color, 1, 0.8, 0.1);
	left->material->diffuse = 0.7;
	left->material->specular = 0.3;

	world = create_world();
	world->light_point = ft_lstnew(create_light_point(
			create_point(-10, 10, -10),
			create_color(1, 1, 1)
		));
	ft_lstadd_front(&world->objects, ft_lstnew(floor));
	// ft_lstadd_front(&world->objects, ft_lstnew(backdrop));
	ft_lstadd_front(&world->objects, ft_lstnew(middle));
	ft_lstadd_front(&world->objects, ft_lstnew(right));
	ft_lstadd_front(&world->objects, ft_lstnew(left));

	camera = create_camera(1000, 500, radians(180 / 2));
	set_camera_transformation(camera, view_transform(
		create_point(0, 1.5, -5),
		create_point(0, 1, 0),
		create_vector(0, 1, 0)
	));

	canvas = render(camera, world);
	win = mlx_new_window(
		canvas->mlx,
		(int)round(camera->h_size),
		(int)round(camera->v_size),
		"uwu"
	);
	mlx_put_image_to_window(canvas->mlx, win, canvas->image, 0, 0);
	mlx_loop(canvas->mlx);
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
	// uncomment at your own risk
	// RUN_TEST(test_print_three_spheres_and_plane);
}
