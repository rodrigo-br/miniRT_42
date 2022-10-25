/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_destructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:18:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 10:35:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_material(t_material *material)
{
	free(material->color);
	free(material);
}

void	destroy_light_point(t_light_pnt *light_point)
{
	free(light_point->position);
	free(light_point->intensity);
	free(light_point);
}

void	destroy_lightattr(t_lightattr *attributes)
{
	destroy_material(attributes->material);
	destroy_light_point(attributes->light_point);
	free(attributes->camera);
	free(attributes->normal);
	free(attributes->position);
	free(attributes);
}
