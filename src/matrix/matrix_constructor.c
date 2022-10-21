/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:10:00 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/20 14:49:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*create_matrix(size_t size, double m[MATRIX_MAX][MATRIX_MAX])
{
	t_matrix	*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->size = size;
	ft_memmove(matrix->matrix, m, (sizeof(double) * MATRIX_MAX * MATRIX_MAX));
	return (matrix);
}
