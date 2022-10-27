/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/27 14:39:16 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_pattern	*create_pattern(t_rgb *a, t_rgb *b)
{
	t_pattern	*pattern;

	pattern = (t_pattern *)malloc(sizeof(t_pattern));
	if (!pattern)
		return (NULL);
	pattern->color_a = a;
	pattern->color_b = b;
	pattern->transformation = create_identity_matrix();
	return (pattern);
}

t_rgb	*pattern_at(t_pattern *pattern, t_point	*point)
{
	if (((int)floor(point->x) + (int)floor(point->y) + (int)floor(point->z)) \
		% 2)
		return (pattern->color_b);
	return (pattern->color_a);
}

void	destroy_pattern(t_pattern *pattern)
{
	free(pattern->color_a);
	free(pattern->color_b);
	free(pattern->transformation);
	free(pattern);
}

t_rgb	*pattern_at_obj(t_pattern *pattern, t_point	*point, t_object *obj)
{
	t_point		*obj_point;
	t_point		*pattern_point;
	t_matrix	*obj_inversed;
	t_matrix	*pat_inversed;
	t_rgb		*result;

	obj_inversed = inverse_matrix(obj->transformation);
	obj_point = multiply_matrix_tuple(obj_inversed, point);
	free(obj_inversed);
	pat_inversed = inverse_matrix(pattern->transformation);
	pattern_point = multiply_matrix_tuple(pat_inversed, obj_point);
	free(pat_inversed);
	result = pattern_at(pattern, pattern_point);
	free(pattern_point);
	free(obj_point);
	return (result);
}

void	set_pattern_transformation(t_pattern *pattern, t_matrix *transform)
{
	free(pattern->transformation);
	pattern->transformation = transform;
}
