/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:38:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 19:38:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	setup_visual_environment(t_minirt *rt)
{
	mlx_put_image_to_window(
		rt->canvas->mlx,
		rt->window,
		rt->canvas->image,
		0, 0);
	mlx_hook(rt->window, KeyPress, KeyPressMask, keypress_handler, rt);
	mlx_hook(rt->window, DestroyNotify, NoEventMask, end_program, rt);
	mlx_loop(rt->canvas->mlx);
}
