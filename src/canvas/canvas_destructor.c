/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:54:12 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/31 16:25:13 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_canvas(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->image);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
}
