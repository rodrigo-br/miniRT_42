/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:18:41 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/21 08:19:29 by maolivei         ###   ########.fr       */
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
