/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:56:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/09 10:18:14 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_cone(void)
{
	t_object	*cone;

	cone = create_shape();
	if (!cone)
		return (NULL);
	cone->type = ID_CONE;
	cone->cone.diameter = 1.0;
	cone->cone.min = -INFINITY;
	cone->cone.max = INFINITY;
	cone->cone.capped = TRUE;
	cone->intersect = intersect_cone;
	cone->get_normal = get_cone_normal;
	return (cone);
}

t_vector	*get_cone_normal(t_object *cone, t_point *point)
{
	double	distance;
	double	radius;
	double	y;

	distance = (point->x * point->x) + (point->z * point->z);
	radius = cone->cone.max * cone->cone.max;
	if (distance < radius && point->y >= (cone->cone.max - EPSILON))
		return (create_vector(0, 1, 0));
	radius = cone->cone.min * cone->cone.min;
	if (distance < radius && point->y <= (cone->cone.min + EPSILON))
		return (create_vector(0, -1, 0));
	y = sqrt((point->x * point->x) + (point->z * point->z));
	if (point->y > 0.0)
		y = -y;
	return (create_vector(point->x, y, point->z));
}
