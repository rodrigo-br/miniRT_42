/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_constructors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/18 13:51:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_point	*create_point(double x, double y, double z)
{
	return (create_tuple(x, y, z, POINT_W));
}

t_vector	*create_vector(double x, double y, double z)
{
	return (create_tuple(x, y, z, VECTOR_W));
}

t_tuple	*create_tuple(double x, double y, double z, double w)
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
