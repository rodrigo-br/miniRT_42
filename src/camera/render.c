/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 09:33:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_canvas	*render(t_cam *camera, t_world *world)
{
	size_t		x;
	size_t		y;
	t_canvas	*canvas;
	t_ray		*ray;
	t_rgb		*color;

	canvas = create_canvas(camera->v_size, camera->h_size);
	y = 0;
	while (y < (camera->v_size - 1))
	{
		x = 0;
		while (x < (camera->h_size - 1))
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray);
			destroy_ray(ray);
			write_to_canvas(canvas, x, y, color->merged);
			free(color);
			++x;
		}
		++y;
	}
	return (canvas);
}
