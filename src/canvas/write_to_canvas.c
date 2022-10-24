/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:18:15 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	write_to_canvas(t_canvas *canvas, int x, int y, t_rgb rgb)
{
	char	*pixel;
	int		index;
	int		color;

	color = rgb.merged;
	pixel = canvas->address;
	pixel += (y * canvas->line_length) + (x * (canvas->bits_per_pixel / 8));
	index = canvas->bits_per_pixel - 8;
	while (index >= 0)
	{
		if (canvas->endianness == 0)
			*pixel++ = (color >> (canvas->bits_per_pixel - 8 - index)) & 0xFF;
		else
			*pixel++ = (color >> index) & 0xFF;
		index -= 8;
	}
}
