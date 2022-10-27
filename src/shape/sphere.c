/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:18:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 19:12:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_sphere(void)
{
	t_object	*sphere;

	sphere = create_shape();
	if (!sphere)
		return (NULL);
	sphere->type = ID_SPHERE;
	sphere->sphere.diameter = 1.0;
	sphere->sphere.center = (t_point){0, 0, 0, 1};
	sphere->intersect = intersect_sphere;
	sphere->get_normal = get_sphere_normal;
	return (sphere);
}

t_vector	*get_sphere_normal(t_object *sphere, t_point *point)
{
	t_matrix	*transpose_inverse;
	t_point		*object_point;
	t_vector	*object_normal;
	t_vector	*world_normal;
	t_vector	*normalized_world_normal;

	transpose_inverse = transpose_matrix(sphere->inverse_transformation);
	object_point = multiply_matrix_tuple(sphere->inverse_transformation, point);
	object_normal = sub_tuple(object_point, &sphere->sphere.center);
	world_normal = multiply_matrix_tuple(transpose_inverse, object_normal);
	world_normal->w = VECTOR_W;
	normalized_world_normal = normalize(world_normal);
	free(transpose_inverse);
	free(object_point);
	free(object_normal);
	free(world_normal);
	return (normalized_world_normal);
}
