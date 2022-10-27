/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/27 11:51:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_pattern	*create_pattern(t_rgb *a, t_rgb *b)
{
	t_pattern	*pattern;

	pattern = (t_pattern *)malloc(sizeof(t_pattern));
	if (!pattern)
		return (NULL);
	pattern->color_a = a;
	pattern->color_b = b;
	return (pattern);
}

t_rgb	*pattern_at(t_pattern *pattern, t_point	*point)
{
	if ((int)floor(point->x) % 2)
		return (pattern->color_b);
	return (pattern->color_a);
}

void	destroy_pattern(t_pattern *pattern)
{
	free(pattern->color_a);
	free(pattern->color_b);
	free(pattern);
}
