/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_computations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:25:08 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/31 11:35:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	*normal_at(t_object *shape, t_point *point)
{
	t_vector	*world_normal;
	t_vector	*object_normal;
	t_point		*object_point;
	t_tuple		*aux;
	t_matrix	*transposed_inverse;

	object_point = multiply_matrix_tuple(shape->inverse_transformation, point);
	object_normal = shape->get_normal(shape, object_point);
	transposed_inverse = transpose_matrix(shape->inverse_transformation);
	world_normal = multiply_matrix_tuple(transposed_inverse, object_normal);
	world_normal->w = VECTOR_W;
	free(transposed_inverse);
	free(object_normal);
	free(object_point);
	aux = world_normal;
	world_normal = normalize(world_normal);
	free(aux);
	return (world_normal);
}

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
	comps->normal = normal_at(comps->object, comps->point);
	if (dot_product(comps->normal, comps->camera) < 0)
	{
		aux = comps->normal;
		comps->normal = neg_tuple(comps->normal);
		free(aux);
	}
	aux = scalar_multiply_tuple(comps->normal, EPSILON);
	comps->over_point = sum_tuple(comps->point, aux);
	free(aux);
	return (comps);
}
