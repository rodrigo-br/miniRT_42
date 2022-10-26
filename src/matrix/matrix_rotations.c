/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:19:30 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/26 09:50:06 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*rotate_matrix_x(double r)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[1][1] = cos(r);
	matrix->matrix[1][2] = -sin(r);
	matrix->matrix[2][1] = sin(r);
	matrix->matrix[2][2] = cos(r);
	return (matrix);
}

t_matrix	*rotate_matrix_y(double r)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[0][0] = cos(r);
	matrix->matrix[0][2] = sin(r);
	matrix->matrix[2][0] = -sin(r);
	matrix->matrix[2][2] = cos(r);
	return (matrix);
}

t_matrix	*rotate_matrix_z(double r)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[0][0] = cos(r);
	matrix->matrix[0][1] = -sin(r);
	matrix->matrix[1][0] = sin(r);
	matrix->matrix[1][1] = cos(r);
	return (matrix);
}
