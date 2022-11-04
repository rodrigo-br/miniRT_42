/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:07:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 19:59:31 by maolivei         ###   ########.fr       */
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
	while (intersect)
	{
		if (intersect->time - EPSILON > 0.0)
			return (intersect);
		intersect = intersect->next;
	}
	return (NULL);
}

t_rgb	*shade_hit(t_world *world, t_comp *comps, t_list *light_list)
{
	t_pos_attr	*pos_attr;
	t_lightattr	*light_attr;
	t_rgb		*aux[2];
	t_rgb		*color;

	color = create_color(0, 0, 0);
	pos_attr = create_pos_attr(comps->camera, comps->normal, comps->over_point);
	while (light_list)
	{
		aux[0] = color;
		light_attr = create_lightattr(
				light_list->content, pos_attr, comps->object->material);
		light_attr->in_shadow = is_shadowed(
				world, comps->over_point, light_list->content);
		light_attr->object = comps->object;
		aux[1] = lighting(light_attr);
		color = sum_color(aux[0], aux[1]);
		free(light_attr);
		free(aux[0]);
		free(aux[1]);
		light_list = light_list->next;
	}
	free(pos_attr);
	return (color);
}

t_rgb	*color_at(t_world *world, t_ray *ray)
{
	t_intersect	*xs;
	t_intersect	*hit;
	t_comp		*comps;
	t_rgb		*color;

	xs = NULL;
	intersect_world(world, ray, &xs);
	hit = get_hit(xs);
	if (!hit)
	{
		intersection_list_clear(&xs);
		return (create_color(0, 0, 0));
	}
	comps = prepare_computation(hit, ray);
	color = shade_hit(world, comps, world->light_point);
	destroy_computation(comps);
	intersection_list_clear(&xs);
	return (color);
}
