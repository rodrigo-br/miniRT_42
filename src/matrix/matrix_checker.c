/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:00:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/21 09:25:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
