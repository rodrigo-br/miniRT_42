/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_computations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:25:08 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 14:45:55 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_comp	*prepare_computation(t_intersect *i, t_ray *ray)
{
	t_comp		*comps;
	t_vector	*aux;

	comps = (t_comp *)malloc(sizeof(t_comp));
	if (!comps)
		return (NULL);
	comps->time = i->time;
	comps->object = i->object;
	comps->point = get_position(ray, comps->time);
	comps->camera = neg_tuple(ray->direction);
	comps->normal = get_sphere_normal(comps->object, comps->point);
	if (dot_product(comps->normal, comps->camera) < 0)
	{
		comps->inside = TRUE;
		aux = neg_tuple(comps->normal);
		free(comps->normal);
		comps->normal = aux;
	}
	else
		comps->inside = FALSE;
	return (comps);
}
