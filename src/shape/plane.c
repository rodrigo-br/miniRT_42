/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:28:00 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 20:04:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_plane(void)
{
	t_object	*plane;

	plane = create_shape();
	if (!plane)
		return (NULL);
	plane->type = ID_PLANE;
	plane->plane.orientation = (t_vector){0, 1, 0, 0};
	plane->intersect = intersect_plane;
	plane->get_normal = get_plane_normal;
	return (plane);
}

t_vector	*get_plane_normal(t_object *plane, t_point *point)
{
	(void)plane;
	(void)point;
	return (create_vector(0, 1, 0));
}
