/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 22:08:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	destroy_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

t_canvas	*create_canvas(double height, double width)
{
	t_canvas	*canvas;

	canvas = (t_canvas *)malloc(sizeof(t_canvas));
	if (!canvas)
		return (NULL);
	canvas->mlx = mlx_init();
	if (!canvas->mlx)
		return (free(canvas), NULL);
	canvas->image = \
	mlx_new_image(canvas->mlx, (int)round(width), (int)round(height));
	if (!canvas->image)
	{
		destroy_mlx(canvas->mlx);
		return (free(canvas), NULL);
	}
	canvas->address = mlx_get_data_addr(canvas->image, &canvas->bits_per_pixel,
			&canvas->line_length, &canvas->endianness);
	if (!canvas->address)
	{
		mlx_destroy_image(canvas->mlx, canvas->image);
		destroy_mlx(canvas->mlx);
		return (free(canvas), NULL);
	}
	return (canvas);
}
