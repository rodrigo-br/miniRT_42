/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:41 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 14:45:58 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_world(t_world *w)
{
	ft_lstclear(&w->objects, &destroy_shape);
	ft_lstclear(&w->light_point, &destroy_light_point);
	free(w);
}

void	destroy_computation(t_comp *comps)
{
	free(comps->point);
	free(comps->camera);
	free(comps->normal);
	free(comps);
}