/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:37:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 13:53:08 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_world	*create_world(void)
{
	t_world		*world;

	world = (t_world *)malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->light_point = NULL;
	world->objects = NULL;
	return (world);
}

void	destroy_world(t_world *w)
{
	ft_lstclear(&w->objects, &destroy_shape);
	ft_lstclear(&w->light_point, &destroy_light_point);
	free(w);
}
