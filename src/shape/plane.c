/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:28:00 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 13:12:08 by maolivei         ###   ########.fr       */
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
	plane->plane.position = (t_vector){0, 1, 0, 0};
	plane->intersect = intersect_plane;
	plane->get_normal = get_plane_normal;
	return (plane);
}

void	intersect_plane(t_object *plane, t_ray *ray, t_intersect **head)
{
	double	time;

	if (is_equal_double(0.0, ray->direction->y))
		return ;
	time = -ray->origin->y / ray->direction->y;
	intersection_sorted_insert(head, create_intersection(time, plane));
}

t_vector	*get_plane_normal(t_object *plane, t_point *point)
{
	(void)plane;
	(void)point;
	return (create_vector(0, 1, 0));
}
