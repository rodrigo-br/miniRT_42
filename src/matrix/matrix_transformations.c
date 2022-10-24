/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:49:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/24 13:59:52 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*translate_matrix(double x, double y, double z)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[0][3] = x;
	matrix->matrix[1][3] = y;
	matrix->matrix[2][3] = z;
	return (matrix);
}

t_matrix	*scale_matrix(double x, double y, double z)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[0][0] = x;
	matrix->matrix[1][1] = y;
	matrix->matrix[2][2] = z;
	return (matrix);
}

t_matrix	*shearing_matrix(t_shearing s)
{
	t_matrix	*matrix;

	matrix = create_identity_matrix();
	matrix->matrix[0][1] = s.xy;
	matrix->matrix[0][2] = s.xz;
	matrix->matrix[1][0] = s.yx;
	matrix->matrix[1][2] = s.yz;
	matrix->matrix[2][0] = s.zx;
	matrix->matrix[2][1] = s.zy;
	return (matrix);
}
