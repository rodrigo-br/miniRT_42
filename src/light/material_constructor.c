/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_constructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:05:27 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 10:21:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material	*create_material(void)
{
	t_material	*material;

	material = (t_material *)malloc(sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = create_color(1, 1, 1);
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	return (material);
}

t_pos_attr	*create_pos_attr(t_vector *camera, t_vector *normal, t_point *pos)
{
	t_pos_attr	*attributes;

	attributes = (t_pos_attr *)malloc(sizeof(t_pos_attr));
	if (!attributes)
		return (NULL);
	attributes->camera = camera;
	attributes->normal = normal;
	attributes->position = pos;
	return (attributes);
}

t_light_pnt	*create_light_point(t_point *position, t_rgb *intensity)
{
	t_light_pnt	*light_point;

	light_point = (t_light_pnt *)malloc(sizeof(t_light_pnt));
	if (!light_point)
		return (NULL);
	light_point->position = position;
	light_point->intensity = intensity;
	return (light_point);
}

t_lightattr	*create_lightattr(t_light_pnt *lp, t_pos_attr *pos, t_material *m)
{
	t_lightattr	*attributes;

	attributes = (t_lightattr *)malloc(sizeof(t_lightattr));
	if (!attributes)
		return (NULL);
	attributes->light_point = lp;
	attributes->camera = pos->camera;
	attributes->normal = pos->normal;
	attributes->position = pos->position;
	attributes->material = m;
	attributes->in_shadow = FALSE;
	free(pos);
	return (attributes);
}
