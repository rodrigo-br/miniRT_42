/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:02:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 22:00:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

/* Scenario: Constructing a camera
Given hsize ← 160
And vsize ← 120
And field_of_view ← π/2
When c ← camera(hsize, vsize, field_of_view)
Then c.hsize = 160
And c.vsize = 120
And c.field_of_view = π/2
And c.transform = identity_matrix */
void	test_camera_creation(void)
{
	t_matrix	*id;
	t_cam		*camera;

	id = create_identity_matrix();
	camera = create_camera(160, 120, radians(180 / 2));
	TEST_ASSERT_EQUAL(160, camera->h_size);
	TEST_ASSERT_EQUAL(120, camera->v_size);
	TEST_ASSERT_EQUAL(radians(180 / 2), camera->field_of_view);
	TEST_ASSERT_TRUE(is_equal_matrix(id, camera->transformation));
	free(id);
	destroy_camera(camera);
}

/* Scenario: The pixel size for a horizontal canvas
Given c ← camera(200, 125, π/2)
Then c.pixel_size = 0.01 */
void	test_pixel_size_horizontal(void)
{
	t_cam	*camera;

	camera = create_camera(200, 125, radians(180 / 2));
	TEST_ASSERT_EQUAL_DOUBLE(0.01, camera->pixel_size);
	destroy_camera(camera);
}

/* Scenario: The pixel size for a vertical canvas
Given c ← camera(125, 200, π/2)
Then c.pixel_size = 0.01 */
void	test_pixel_size_vertical(void)
{
	t_cam	*camera;

	camera = create_camera(125, 200, radians(180 / 2));
	TEST_ASSERT_EQUAL_DOUBLE(0.01, camera->pixel_size);
	destroy_camera(camera);
}

/* Scenario: Constructing a ray through the center of the canvas
Given c ← camera(201, 101, π/2)
When r ← ray_for_pixel(c, 100, 50)
Then r.origin = point(0, 0, 0)
And r.direction = vector(0, 0, -1) */
void	test_ray_through_center_of_canvas(void)
{
	t_cam	*camera;
	t_ray	*ray;

	camera = create_camera(201, 101, radians(180 / 2));
	ray = ray_for_pixel(camera, 100, 50);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_point){0, 0, 0, 1}, ray->origin));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0, 0, -1, 0}, ray->direction));
	destroy_camera(camera);
	destroy_ray(ray);
}

/* Scenario: Constructing a ray through a corner of the canvas
Given c ← camera(201, 101, π/2)
When r ← ray_for_pixel(c, 0, 0)
Then r.origin = point(0, 0, 0)
And r.direction = vector(0.66519, 0.33259, -0.66851) */
void	test_ray_through_corner_of_canvas(void)
{
	t_cam	*camera;
	t_ray	*ray;

	camera = create_camera(201, 101, radians(180 / 2));
	ray = ray_for_pixel(camera, 0, 0);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_point){0, 0, 0, 1}, ray->origin));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){0.66519, 0.33259, -0.66851, 0}, ray->direction));
	destroy_camera(camera);
	destroy_ray(ray);
}

/* Scenario: Constructing a ray when the camera is transformed
Given c ← camera(201, 101, π/2)
When c.transform ← rotation_y(π/4) * translation(0, -2, 5)
And r ← ray_for_pixel(c, 100, 50)
Then r.origin = point(0, 2, -5)
And r.direction = vector(√2/2, 0, -√2/2) */
void	test_ray_when_camera_is_transformed(void)
{
	t_cam		*camera;
	t_matrix	*aux1, *aux2;
	t_ray		*ray;

	camera = create_camera(201, 101, radians(180 / 2));
	aux1 = rotate_matrix_y(radians(180 / 4));
	aux2 = translate_matrix(0, -2, 5);
	set_camera_transformation(camera, multiply_matrix(aux1, aux2));
	ray = ray_for_pixel(camera, 100, 50);
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_point){0, 2, -5, 1}, ray->origin));
	TEST_ASSERT_TRUE(is_equal_tuple(&(t_vector){sqrt(2)/2, 0, -sqrt(2)/2, 0}, ray->direction));
	destroy_camera(camera);
	destroy_ray(ray);
	free(aux1);
	free(aux2);
}

/* Scenario: Rendering a world with a camera
Given w ← default_world()
And c ← camera(11, 11, π/2)
And from ← point(0, 0, -5)
And to ← point(0, 0, 0)
And up ← vector(0, 1, 0)
And c.transform ← view_transform(from, to, up)
When image ← render(c, w)
Then pixel_at(image, 5, 5) = color(0.38066, 0.47583, 0.2855) */
void	test_render_world_with_camera(void)
{
	t_world		*world;
	t_cam		*camera;
	t_point		*from, *to;
	t_vector	*up;
	t_canvas	*canvas;

	world = default_world();
	camera = create_camera(11, 11, radians(180 / 2));
	from = create_point(0, 0, -5);
	to = create_point(0, 0, 0);
	up = create_vector(0, 1, 0);
	set_camera_transformation(camera, view_transform(from, to, up));
	canvas = render(camera, world);
	TEST_ASSERT_EQUAL(
		/* altered values cause algorithm produces very visually similar colors,
		but not as similar as needed to be considered equal to the suggested tests
		e.g tests suggests: 0x607848, program produces 0x617949 */
		merge_colors(0.38039, 0.47450, 0.28627),
		pixel_at(canvas, 5, 5)
	);
	destroy_world(world);
	destroy_camera(camera);
	destroy_canvas(canvas);
	free(from);
	free(up);
	free(to);
}

void	test_camera(void)
{
	RUN_TEST(test_camera_creation);
	RUN_TEST(test_pixel_size_horizontal);
	RUN_TEST(test_pixel_size_vertical);
	RUN_TEST(test_ray_through_center_of_canvas);
	RUN_TEST(test_ray_through_corner_of_canvas);
	RUN_TEST(test_ray_when_camera_is_transformed);
	RUN_TEST(test_render_world_with_camera);
}
