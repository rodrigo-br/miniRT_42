/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:49:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 12:00:03 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*create_copy_tuple(t_tuple *t)
{
	return (create_tuple(t->x, t->y, t->z, t->w));
}

t_matrix	*translate_matrix(t_tuple *point, t_tuple *translation)
{
	t_tuple		*new_tuple;
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	if (is_vector(point))
		new_tuple = point;
	else
		new_tuple = sum_tuple(point, translation);
	matrix->matrix[0][3] = new_tuple->x;
	matrix->matrix[1][3] = new_tuple->y;
	matrix->matrix[2][3] = new_tuple->z;
	if (point->w == POINT_W)
		free(new_tuple);
	matrix->matrix[3][3] = point->w;
	return (matrix);
}

// t_tuple	*translate_inverse_matrix(t_tuple *point, t_tuple *translation)
// {
// 	double	temp;
// 	t_tuple	*new_tuple;
// 	t_tuple	*inverse;

// 	if (is_vector(point))
// 		return (create_copy_tuple(point));
// 	temp = point->w;
// 	inverse = neg_tuple(translation);
// 	new_tuple = sum_tuple(point, inverse);
// 	new_tuple->w = temp;
// 	free(inverse);
// 	return (new_tuple);
// }
