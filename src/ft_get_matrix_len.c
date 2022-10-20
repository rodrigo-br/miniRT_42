/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:51:17 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 15:55:27 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

size_t	ft_get_matrix_len(char **matrix)
{
	size_t	i;

	if (!matrix || !(*matrix))
		return (0);
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
