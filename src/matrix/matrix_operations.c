/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:18:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/21 08:33:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_matrix	*multiply_matrix(t_matrix *a, t_matrix *b)
{
	size_t	i;
	size_t	j;
	size_t	k;
	double	m[MATRIX_MAX][MATRIX_MAX];

	if (a->size != b->size)
		return (NULL);
	ft_bzero(m, (sizeof(double) * MATRIX_MAX * MATRIX_MAX));
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			k = 0;
			while (k < a->size)
			{
				m[i][j] += a->matrix[i][k] * b->matrix[k][j];
				++k;
			}
			++j;
		}
		++i;
	}
	return (create_matrix(a->size, m));
}

t_tuple	*multiply_matrix_tuple(t_matrix *m, t_tuple *t)
{
	size_t	index;
	double	tmp[MATRIX_MAX];

	if (m->size != MATRIX_MAX)
		return (NULL);
	index = 0;
	while (index < MATRIX_MAX)
	{
		tmp[index] = \
			m->matrix[index][0] * t->x + \
			m->matrix[index][1] * t->y + \
			m->matrix[index][2] * t->z + \
			m->matrix[index][3] * t->w;
		++index;
	}
	return (create_tuple(tmp[0], tmp[1], tmp[2], tmp[3]));
}
