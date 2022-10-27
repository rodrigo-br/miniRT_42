/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:17:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 11:48:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_cylinder(void)
{
	t_object	*cylinder;

	cylinder = create_shape();
	if (!cylinder)
		return (NULL);
	cylinder->type = ID_CYLINDER;
	cylinder->cylinder.diameter = 1.0;
	cylinder->intersect = intersect_cylinder;
	cylinder->get_normal = get_cylinder_normal;
	return (cylinder);
}

t_vector	*get_cylinder_normal(t_object *cylinder, t_point *point)
{
	(void)cylinder;
	return (create_vector(point->x, 0, point->z));
}
