/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:48:27 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/18 21:02:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_rgb	*sum_color(t_rgb *a, t_rgb *b)
{
	return (create_color(
			(a->red + b->red),
			(a->green + b->green),
			(a->blue + b->blue))
	);
}

t_rgb	*sub_color(t_rgb *a, t_rgb *b)
{
	return (create_color(
			(a->red - b->red),
			(a->green - b->green),
			(a->blue - b->blue))
	);
}

t_rgb	*multiply_color(t_rgb *a, t_rgb *b)
{
	return (create_color(
			(a->red * b->red),
			(a->green * b->green),
			(a->blue * b->blue))
	);
}

t_rgb	*scalar_multiply_color(t_rgb *a, double multiplier)
{
	return (create_color(
			(a->red * multiplier),
			(a->green * multiplier),
			(a->blue * multiplier))
	);
}
