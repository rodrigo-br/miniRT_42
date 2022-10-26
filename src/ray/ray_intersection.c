/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:12:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 19:44:56 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	intersect_sphere(t_object *sphere, t_ray *ray, t_intersect **head)
{
	double		x1;
	double		x2;
	t_bhaskara	bhaskara;
	t_vector	*sphere_to_ray;
	t_ray		*transformed;

	transformed = transform_ray(ray, sphere->inverse_transformation);
	sphere_to_ray = sub_tuple(transformed->origin, &sphere->sphere.center);
	bhaskara.a = dot_product(transformed->direction, transformed->direction);
	bhaskara.b = dot_product(transformed->direction, sphere_to_ray) * 2;
	bhaskara.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	free(sphere_to_ray);
	destroy_ray(transformed);
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

	obj_list = world->objects;
	while (obj_list)
	{
		current_obj = (t_object *)obj_list->content;
		current_obj->intersect(current_obj, ray, head);
		obj_list = obj_list->next;
	}
}
