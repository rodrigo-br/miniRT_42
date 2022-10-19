/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_canvas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:08:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/19 18:41:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	encode_big_endian_rgb(int r, int g, int b)
{
	return (
		((r & 0xFF) << 24) + \
		((g & 0xFF) << 16) + \
		((b & 0xFF) << 8) + OPACITY_MAX
	);
}

void	write_to_canvas(t_canvas *canvas, int x, int y, t_rgb *rgb)
{
	char	*pixel;
	int		color;
	int		index;

	pixel = canvas->addr + (y * canvas->line_len) + (x * (canvas->bpp / 8));
	if (canvas->endianness == 0)
		color = rgb->color;
	else
		color = encode_big_endian_rgb(rgb->red, rgb->green, rgb->blue);
	index = canvas->bpp - 8;
	while (index >= 0)
	{
		if (canvas->endianness == 0)
			*pixel++ = (color >> (canvas->bpp - 8 - index)) & 0xFF;
		else
			*pixel++ = (color >> index) & 0xFF;
		index -= 8;
	}
}
