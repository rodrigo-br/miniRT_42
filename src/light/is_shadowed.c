/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:37:47 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 14:09:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	_is_shadowed(t_world *world, t_ray *ray, double distance)
{
	t_intersect	*xs;
	t_intersect	*hit;
	t_bool		in_shadow;

	xs = NULL;
	intersect_world(world, ray, &xs);
	hit = get_hit(xs);
	in_shadow = (hit && hit->time < distance);
	free(ray->direction);
	free(ray);
	intersection_list_clear(&xs);
	return (in_shadow);
}

t_bool	is_shadowed(t_world *world, t_point *point, t_light_pnt *lp)
{
	t_tuple		*aux;
	double		distance;
	t_vector	*direction;
	t_ray		*ray;

	aux = sub_tuple(lp->position, point);
	distance = magnitude(aux);
	direction = normalize(aux);
	free(aux);
	ray = create_ray(point, direction);
	return (_is_shadowed(world, ray, distance));
}
