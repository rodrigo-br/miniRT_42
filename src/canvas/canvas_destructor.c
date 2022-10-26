/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:54:12 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 21:56:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_canvas(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->image);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
}
