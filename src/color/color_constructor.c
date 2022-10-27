/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:41:13 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 12:59:20 by ralves-b         ###   ########.fr       */
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

void	set_color(t_rgb *color, double r, double g, double b)
{
	color->red = r;
	color->green = g;
	color->blue = b;
	color->merged = merge_colors(r, g, b);
}

void	set_color_from_pattern(t_rgb *color, t_rgb *pattern)
{
	color->red = pattern->red;
	color->green = pattern->green;
	color->blue = pattern->blue;
	color->merged = merge_colors(pattern->red, pattern->green, pattern->blue);
}

t_rgb	*create_color(double r, double g, double b)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	set_color(rgb, r, g, b);
	return (rgb);
}
