/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:37:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 14:45:40 by ralves-b         ###   ########.fr       */
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
