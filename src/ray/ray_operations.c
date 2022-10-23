/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:07:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 14:49:56 by maolivei         ###   ########.fr       */
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

t_intersect	*intersect_sphere(t_object *sphere, t_ray *ray)
{
	t_bhaskara	bhaskara;
	t_vector	*sphere_to_ray;
	t_intersect	*intersect;

	intersect = (t_intersect *)ft_calloc(1, sizeof(t_intersect));
	if (!intersect)
		return (NULL);
	sphere_to_ray = sub_tuple(ray->origin, &sphere->sphere.center);
	bhaskara.a = dot_product(ray->direction, ray->direction);
	bhaskara.b = dot_product(ray->direction, sphere_to_ray) * 2;
	bhaskara.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	bhaskara.delta = (bhaskara.b * bhaskara.b) - (4 * bhaskara.a * bhaskara.c);
	if (bhaskara.delta < 0)
		return (intersect);
	intersect->count = 2;
	intersect->hit = (double *)malloc(sizeof(double) * 2);
	intersect->hit[0] = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	intersect->hit[1] = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	return (intersect);
}
