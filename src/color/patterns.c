/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:36:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/31 11:45:06 by maolivei         ###   ########.fr       */
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
	pattern->inverse_transformation = create_identity_matrix();
	return (pattern);
}

t_rgb	*pattern_at(t_pattern *pattern, t_point	*point)
{
	if ((int)(floor(point->x) + floor(point->y) + floor(point->z)) % 2)
		return (pattern->color_b);
	return (pattern->color_a);
}

void	destroy_pattern(t_pattern *pattern)
{
	free(pattern->color_a);
	free(pattern->color_b);
	free(pattern->transformation);
	free(pattern->inverse_transformation);
	free(pattern);
}

t_rgb	*pattern_at_obj(t_pattern *pat, t_point *point, t_object *obj)
{
	t_point	*obj_point;
	t_point	*pat_point;
	t_rgb	*result;

	obj_point = multiply_matrix_tuple(obj->inverse_transformation, point);
	pat_point = multiply_matrix_tuple(pat->inverse_transformation, obj_point);
	result = pattern_at(pat, pat_point);
	free(pat_point);
	free(obj_point);
	return (result);
}

void	set_pattern_transformation(t_pattern *pattern, t_matrix *transform)
{
	free(pattern->transformation);
	free(pattern->inverse_transformation);
	pattern->transformation = transform;
	pattern->inverse_transformation = inverse_matrix(transform);
}
