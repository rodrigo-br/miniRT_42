/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:38:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 19:38:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	end_program(t_minirt *rt)
{
	mlx_destroy_window(rt->canvas->mlx, rt->window);
	destroy_canvas(rt->canvas);
	ft_memfree((void *)&rt);
	return (exit(0), 0);
}

int	keypress_handler(int keysym, t_minirt *rt)
{
	if (keysym == XK_Escape || keysym == XK_q)
		end_program(rt);
	return (0);
}
