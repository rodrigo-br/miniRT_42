/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:49:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 14:32:43 by ralves-b         ###   ########.fr       */
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
