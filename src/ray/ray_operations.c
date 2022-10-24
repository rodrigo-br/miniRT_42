/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:07:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 14:18:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point	*get_position(t_ray *ray, double time)
{
	t_point	*_position;
	t_point	*aux;

	aux = scalar_multiply_tuple(ray->direction, time);
	_position = sum_tuple(ray->origin, aux);
	free(aux);
	return (_position);
}

t_ray	*transform_ray(t_ray *ray, t_matrix *matrix)
{
	t_point		*new_origin;
	t_vector	*new_direction;

	new_origin = multiply_matrix_tuple(matrix, ray->origin);
	new_direction = multiply_matrix_tuple(matrix, ray->direction);
	return (create_ray(new_origin, new_direction));
}

t_intersect	*get_hit(t_intersect *intersect)
{
	t_intersect	*_hit;

	_hit = NULL;
	while (intersect)
	{
		if ((!_hit || _hit->time > intersect->time) && intersect->time > 0)
			_hit = intersect;
		intersect = intersect->next;
	}
	return (_hit);
}

t_vector	*get_sphere_normal(t_object *sphere, t_point *point)
{
	t_matrix	*transpose_inverse;
	t_point		*object_point;
	t_vector	*object_normal;
	t_vector	*world_normal;
	t_vector	*normalized_world_normal;

	transpose_inverse = transpose_matrix(sphere->inverse_transformation);
	object_point = multiply_matrix_tuple(sphere->inverse_transformation, point);
	object_normal = sub_tuple(object_point, &sphere->sphere.center);
	world_normal = multiply_matrix_tuple(transpose_inverse, object_normal);
	world_normal->w = VECTOR_W;
	normalized_world_normal = normalize(world_normal);
	free(transpose_inverse);
	free(object_point);
	free(object_normal);
	free(world_normal);
	return (normalized_world_normal);
}
