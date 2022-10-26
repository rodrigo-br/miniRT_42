/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_destructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:18:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 13:46:57 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_material(t_material *material)
{
	free(material->color);
	free(material);
}

void	destroy_light_point(void *light_point)
{
	t_light_pnt	*lp;

	lp = (t_light_pnt *)light_point;
	free(lp->position);
	free(lp->intensity);
	free(lp);
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
