/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:18:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 20:33:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*multiply_matrix(t_matrix *a, t_matrix *b)
{
	size_t	row;
	size_t	col;
	size_t	aux;
	double	m[MAT_MAX][MAT_MAX];

	if (a->size != b->size)
		return (NULL);
	ft_bzero(m, (sizeof(double) * MAT_MAX * MAT_MAX));
	row = 0;
	while (row < a->size)
	{
		col = 0;
		while (col < a->size)
		{
			aux = 0;
			while (aux < a->size)
			{
				m[row][col] += a->matrix[row][aux] * b->matrix[aux][col];
				++aux;
			}
			++col;
		}
		++row;
	}
	return (create_matrix(a->size, m));
}

t_matrix	*multiply_matrix_triple(t_matrix *a, t_matrix *b, t_matrix *c)
{
	t_matrix	*aux;
	t_matrix	*multiply;

	if (a->size != b->size || b->size != c->size || c->size != a->size)
		return (NULL);
	aux = multiply_matrix(a, b);
	multiply = multiply_matrix(aux, c);
	free(aux);
	return (multiply);
}

t_tuple	*multiply_matrix_tuple(t_matrix *m, t_tuple *t)
{
	size_t	row;
	double	aux[MAT_MAX];

	if (m->size != MAT_MAX)
		return (NULL);
	row = 0;
	while (row < MAT_MAX)
	{
		aux[row] = \
			m->matrix[row][0] * t->x + \
			m->matrix[row][1] * t->y + \
			m->matrix[row][2] * t->z + \
			m->matrix[row][3] * t->w;
		++row;
	}
	return (create_tuple(aux[0], aux[1], aux[2], aux[3]));
}

t_matrix	*transpose_matrix(t_matrix *m)
{
	size_t	row;
	size_t	col;
	double	transpose[MAT_MAX][MAT_MAX];

	row = 0;
	while (row < m->size)
	{
		col = 0;
		while (col < m->size)
		{
			transpose[col][row] = m->matrix[row][col];
			++col;
		}
		++row;
	}
	return (create_matrix(m->size, transpose));
}

t_matrix	*inverse_matrix(t_matrix *m)
{
	const double	_determinant = determinant(m);
	size_t			row;
	size_t			col;
	double			inverse[MAT_MAX][MAT_MAX];

	if (!_determinant)
		return (NULL);
	row = 0;
	while (row < m->size)
	{
		col = 0;
		while (col < m->size)
		{
			inverse[col][row] = cofactor(m, row, col) / _determinant;
			++col;
		}
		++row;
	}
	return (create_matrix(m->size, inverse));
}
