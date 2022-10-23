/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:55:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 14:48:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	*create_ray(t_point *origin, t_vector *direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_object	*create_sphere(void)
{
	t_object	*object;

	object = (t_object *)ft_calloc(1, sizeof(t_object));
	object->type = ID_SPHERE;
	object->sphere.diameter = 1.0;
	object->sphere.center = (t_point){0, 0, 0, 1};
	return (object);
}
