/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_view_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:50:50 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/03 17:36:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_matrix	*create_orientation(
		t_vector *left, t_vector *true_up, t_vector *forward)
{
	const double	orientation[MAT_MAX][MAT_MAX] = {
	{left->x, left->y, left->z, 0},
	{true_up->x, true_up->y, true_up->z, 0},
	{-forward->x, -forward->y, -forward->z, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, orientation));
}

static t_matrix	*create_transformation(
		t_vector *left, t_vector *true_up, t_vector *forward, t_point *from)
{
	t_matrix	*orientation;
	t_matrix	*view_transformation;
	t_matrix	*translated;

	orientation = create_orientation(left, true_up, forward);
	translated = translate_matrix(-from->x, -from->y, -from->z);
	view_transformation = multiply_matrix(orientation, translated);
	free(orientation);
	free(translated);
	free(left);
	free(true_up);
	return (view_transformation);
}

t_matrix	*view_transform(t_point *from, t_point *to, t_vector *up)
{
	t_vector	*left;
	t_vector	*normalized_up;
	t_vector	*true_up;

	normalized_up = normalize(up);
	left = cross_product(to, normalized_up);
	free(normalized_up);
	true_up = cross_product(left, to);
	return (create_transformation(left, true_up, to, from));
}
