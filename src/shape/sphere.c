/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:18:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/31 10:48:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_sphere(void)
{
	t_object	*sphere;

	sphere = create_shape();
	if (!sphere)
		return (NULL);
	sphere->type = ID_SPHERE;
	sphere->sphere.diameter = 1.0;
	sphere->sphere.center = (t_point){0, 0, 0, 1};
	sphere->intersect = intersect_sphere;
	sphere->get_normal = get_sphere_normal;
	return (sphere);
}

void	intersect_sphere(t_object *sphere, t_ray *ray, t_intersect **head)
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
	intersection_sorted_insert(head, create_intersection(x1, sphere));
	if (!is_equal_double(x1, x2))
		intersection_sorted_insert(head, create_intersection(x2, sphere));
}

t_vector	*get_sphere_normal(t_object *sphere, t_point *point)
{
	t_vector	*normal;

	normal = sub_tuple(point, &sphere->sphere.center);
	normal->w = VECTOR_W;
	return (normal);
}
