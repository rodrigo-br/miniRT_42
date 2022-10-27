/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:12:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 12:43:44 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

void	intersect_plane(t_object *plane, t_ray *ray, t_intersect **head)
{
	double	time;

	if (fabs(ray->direction->y) < EPSILON)
		return ;
	time = -ray->origin->y / ray->direction->y;
	intersection_sorted_insert(head, create_intersection(time, plane));
}

void	intersect_world(t_world *world, t_ray *ray, t_intersect **head)
{
	t_object	*current_obj;
	t_list		*obj_list;
	t_ray		*transformed;

	obj_list = world->objects;
	while (obj_list)
	{
		current_obj = (t_object *)obj_list->content;
		transformed = transform_ray(ray, current_obj->inverse_transformation);
		current_obj->intersect(current_obj, transformed, head);
		destroy_ray(transformed);
		obj_list = obj_list->next;
	}
}
