/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:12:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 16:33:48 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intersection	*create_intersection(double time, t_object *object)
{
	t_intersection	*intersection;

	intersection = (t_intersection *)malloc(sizeof(t_intersection));
	if (!intersection)
		return (NULL);
	intersection->time = time;
	intersection->object = object;
	return (intersection);
}

void	intersect_sphere(t_object *sphere, t_ray *ray, t_list **xs)
{
	double		x1;
	double		x2;
	t_bhaskara	bhaskara;
	t_vector	*sphere_to_ray;

	sphere_to_ray = sub_tuple(ray->origin, &sphere->sphere.center);
	bhaskara.a = dot_product(ray->direction, ray->direction);
	bhaskara.b = dot_product(ray->direction, sphere_to_ray) * 2;
	bhaskara.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	free(sphere_to_ray);
	bhaskara.delta = (bhaskara.b * bhaskara.b) - (4 * bhaskara.a * bhaskara.c);
	if (bhaskara.delta < 0)
		return ;
	x1 = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	x2 = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	ft_lstadd_back(xs, ft_lstnew(create_intersection(x1, sphere)));
	if (!is_equal_double(x1, x2))
		ft_lstadd_back(xs, ft_lstnew(create_intersection(x2, sphere)));
}
