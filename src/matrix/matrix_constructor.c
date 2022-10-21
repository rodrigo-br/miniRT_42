/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:10:00 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/21 08:56:26 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*create_matrix(size_t size, const double m[MATRIX_MAX][MATRIX_MAX])
{
	t_matrix	*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->size = size;
	ft_memmove(matrix->matrix, m, (sizeof(double) * MATRIX_MAX * MATRIX_MAX));
	return (matrix);
}

t_matrix	*create_identity_matrix(void)
{
	const double	identity[MATRIX_MAX][MATRIX_MAX] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MATRIX_MAX, identity));
}
