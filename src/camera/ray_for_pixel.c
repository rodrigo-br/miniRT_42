/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:56:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 19:56:38 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_ray	*_ray_for_pixel(t_cam *camera, double x_world, double y_world)
{
	t_point		*pixel;
	t_tuple		*aux;
	t_point		*origin;
	t_point		*direction;

	aux = create_point(x_world, y_world, -1);
	pixel = multiply_matrix_tuple(camera->inverse_transformation, aux);
	free(aux);
	aux = create_point(0, 0, 0);
	origin = multiply_matrix_tuple(camera->inverse_transformation, aux);
	free(aux);
	aux = sub_tuple(pixel, origin);
	free(pixel);
	direction = normalize(aux);
	free(aux);
	return (create_ray(origin, direction));
}

t_ray	*ray_for_pixel(t_cam *camera, double x, double y)
{
	double		x_offset;
	double		y_offset;
	double		x_world;
	double		y_world;

	x_offset = (x + 0.5) * camera->pixel_size;
	y_offset = (y + 0.5) * camera->pixel_size;
	x_world = camera->half_width - x_offset;
	y_world = camera->half_height - y_offset;
	return (_ray_for_pixel(camera, x_world, y_world));
}
