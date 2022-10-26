/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:00:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 09:44:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	_2x2_determinant(t_matrix *m)
{
	return (
		(m->matrix[0][0] * m->matrix[1][1]) - \
		(m->matrix[0][1] * m->matrix[1][0])
	);
}

double	determinant(t_matrix *m)
{
	size_t	col;
	double	_determinant;

	if (m->size == 2)
		return (_2x2_determinant(m));
	_determinant = 0;
	col = 0;
	while (col < m->size)
	{
		_determinant += m->matrix[0][col] * cofactor(m, 0, col);
		++col;
	}
	return (_determinant);
}

double	minor(t_matrix *m, size_t row, size_t col)
{
	double		_minor;
	t_matrix	*submatrix;

	submatrix = create_submatrix(m, row, col);
	_minor = determinant(submatrix);
	free(submatrix);
	return (_minor);
}

double	cofactor(t_matrix *m, size_t row, size_t col)
{
	double	_cofactor;

	_cofactor = minor(m, row, col);
	if ((row + col) % 2 != 0)
		return (-_cofactor);
	return (_cofactor);
}

t_bool	is_equal_matrix(t_matrix *a, t_matrix *b)
{
	size_t	row;
	size_t	col;

	if (a->size != b->size)
		return (FALSE);
	row = 0;
	while (row < a->size)
	{
		col = 0;
		while (col < a->size)
		{
			if (!is_equal_double(a->matrix[row][col], b->matrix[row][col]))
				return (FALSE);
			++col;
		}
		++row;
	}
	return (TRUE);
}
