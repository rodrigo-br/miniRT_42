/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/17 14:31:30 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point	*create_point(int x, int y, int z)
{
	return (create_tuple(x, y, z, 1));
}

t_vector	*create_vector(int x, int y, int z)
{
	return (create_tuple(x, y, z, 0));
}

t_tuple	*create_tuple(int x, int y, int z, int w)
{
	t_tuple	*tuple;

	tuple = (t_tuple *)malloc(sizeof(t_tuple));
	if (!tuple)
		return (NULL);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}
