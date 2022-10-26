/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:29:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 21:50:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

double double_rand()
{
	return ((double)rand() / RAND_MAX * 40.0 - 20.0);
}

double color_rand()
{
	return ((double)rand() / RAND_MAX);
}

int	decode_rgba(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_world	*default_world(void)
{
	t_world		*world;
	t_object	*sphere_1;
	t_object	*sphere_2;

	world = create_world();
	world->light_point = ft_lstnew(create_light_point(create_point(-10, 10, -10), create_color(1, 1, 1)));
	sphere_1 = create_sphere();
	free(sphere_1->material->color);
	sphere_1->material->color = create_color(0.8, 1.0, 0.6);
	sphere_1->material->diffuse = 0.7;
	sphere_1->material->specular = 0.2;
	ft_lstadd_back(&world->objects, ft_lstnew(sphere_1));
	sphere_2 = create_sphere();
	set_transformation(sphere_2, scale_matrix(0.5, 0.5, 0.5));
	ft_lstadd_back(&world->objects, ft_lstnew(sphere_2));
	return (world);
}

int	pixel_at(t_canvas *canvas, int x, int y)
{
	char	*pixel;

	pixel = canvas->address;
	pixel += (y * canvas->line_length) + (x * (canvas->bits_per_pixel / 8));
	return (*(int *)pixel);
}

int	to_rgb(double color)
{
	int	_color;

	_color = (int)round(color * 255);
	if (_color > 255)
		return (255);
	if (_color < 0)
		return (0);
	return (_color);
}

int	merge_colors(double r, double g, double b)
{
	return (to_rgb(r) << 16 | to_rgb(g) << 8 | to_rgb(b));
}
