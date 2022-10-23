/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:07:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 16:12:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point	*position(t_ray *ray, double time)
{
	t_point	*_position;
	t_point	*aux;

	aux = scalar_multiply_tuple(ray->direction, time);
	_position = sum_tuple(ray->origin, aux);
	free(aux);
	return (_position);
}
