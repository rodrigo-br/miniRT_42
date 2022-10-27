/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:12:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 13:04:44 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
