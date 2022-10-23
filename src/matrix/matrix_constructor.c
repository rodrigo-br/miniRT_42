/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:10:00 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 16:13:53 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*create_matrix(size_t size, const double m[MAT_MAX][MAT_MAX])
{
	t_matrix	*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->size = size;
	ft_memmove(matrix->matrix, m, (sizeof(double) * MAT_MAX * MAT_MAX));
	return (matrix);
}

t_matrix	*create_identity_matrix(void)
{
	const double	identity[MAT_MAX][MAT_MAX] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	};

	return (create_matrix(MAT_MAX, identity));
}

t_matrix	*create_submatrix(t_matrix *m, size_t delrow, size_t delcol)
{
	size_t	row;
	size_t	col;
	double	aux[MAT_MAX][MAT_MAX];

	if (m->size == 2)
		return (NULL);
	row = 0;
	while (row < (m->size - 1))
	{
		col = 0;
		while (col < (m->size - 1))
		{
			aux[row][col] = \
				m->matrix[row + (row >= delrow)][col + (col >= delcol)];
			++col;
		}
		++row;
	}
	return (create_matrix((m->size - 1), aux));
}
