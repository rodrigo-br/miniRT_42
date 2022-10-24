/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 19:19:20 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	encode_big_endian_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	write_to_canvas(t_canvas *canvas, int x, int y, t_rgb rgb)
{
	char	*pixel;
	int		color;
	int		index;

	rgb.red *= 255;
	rgb.green *= 255;
	rgb.blue *= 255;
	pixel = canvas->address;
	pixel += (y * canvas->line_length) + (x * (canvas->bits_per_pixel / 8));
	color = encode_big_endian_rgb((int)rgb.red, (int)rgb.green, (int)rgb.blue);
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
