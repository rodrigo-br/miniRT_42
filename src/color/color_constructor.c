/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:41:13 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 21:50:01 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	to_rgb(double color)
{
	int	_color;

	_color = (int)round(color * 255);
	if (_color > 255)
		return (255);
	if (_color < 0)
		return (0);
	return (_color);
}

static int	merge_colors(double r, double g, double b)
{
	return (to_rgb(r) << 16 | to_rgb(g) << 8 | to_rgb(b));
}

t_rgb	*create_color(double r, double g, double b)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
	rgb->merged = merge_colors(r, g, b);
	return (rgb);
}
