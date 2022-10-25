/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:07:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 15:30:11 by maolivei         ###   ########.fr       */
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

