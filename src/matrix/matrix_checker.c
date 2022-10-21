/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:00:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/20 18:37:33 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	is_equal_matrix(t_matrix *a, t_matrix *b)
{
	size_t	i;
	size_t	j;

	if (a->size != b->size)
		return (FALSE);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (!is_equal_double(a->matrix[i][j], b->matrix[i][j]))
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}
