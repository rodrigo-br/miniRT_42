/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:19:30 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/01 20:17:00 by maolivei         ###   ########.fr       */
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

t_matrix	*full_rotation_matrix(t_vector *vector)
{
	double		x;
	double		z;
	double		ratio;
	t_matrix	*aux[2];
	t_matrix	*rotation;

	ratio = sqrt((vector->x * vector->x) + (vector->y * vector->y));
	if (!ratio)
		z = M_PI_2;
	else
		z = acos(vector->y / ratio);
	x = acos(ratio);
	aux[0] = rotate_matrix_x(x);
	aux[1] = rotate_matrix_z(z);
	rotation = multiply_matrix(aux[0], aux[1]);
	free(aux[0]);
	free(aux[1]);
	return (rotation);
}
