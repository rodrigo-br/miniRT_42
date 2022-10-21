/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:18:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 12:36:18 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*scale_matrix(t_tuple *tuple, t_tuple *scaling)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[0][0] = tuple->x * scaling->x;
	matrix->matrix[1][1] = tuple->y * scaling->y;
	matrix->matrix[2][2] = tuple->z * scaling->z;
	matrix->matrix[3][3] = tuple->w;
	return (matrix);
}
