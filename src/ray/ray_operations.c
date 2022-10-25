/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:07:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:14 by maolivei         ###   ########.fr       */
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

t_rgb	*shade_hit(t_world *world, t_comp *comps)
{
	t_pos_attr	*pos_attr;
	t_lightattr	*light_attr;
	t_light_pnt	*lp;
	t_rgb		*color;

	lp = (t_light_pnt *)world->light_point->content;
	pos_attr = create_pos_attr(comps->camera, comps->normal, comps->point);
	light_attr = create_lightattr(lp, pos_attr, comps->object->material);
	color = lighting(light_attr);
	free(light_attr);
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
		return (create_color(0, 0, 0));
	comps = prepare_computation(hit, ray);
	color = shade_hit(world, comps);
	destroy_computation(comps);
	intersection_list_clear(&xs);
	return (color);
}
