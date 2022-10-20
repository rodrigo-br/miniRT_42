/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:41:13 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/20 20:46:13 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_rgb	*create_color(int r, int g, int b)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->opacity = 255;
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
	rgb->opacity = 0;
	return (rgb);
}
