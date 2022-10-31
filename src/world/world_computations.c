/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_computations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:25:08 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/31 10:30:24 by maolivei         ###   ########.fr       */
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
	comps->normal = comps->object->get_normal(comps->object, comps->point);
	if (dot_product(comps->normal, comps->camera) < 0)
	{
		comps->inside = TRUE;
		aux = comps->normal;
		comps->normal = neg_tuple(comps->normal);
		free(aux);
	}
	else
		comps->inside = FALSE;
	aux = scalar_multiply_tuple(comps->normal, EPSILON);
	comps->over_point = sum_tuple(comps->point, aux);
	free(aux);
	return (comps);
}
