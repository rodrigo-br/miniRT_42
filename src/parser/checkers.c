/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:04:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/20 08:58:29 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_coordinates_digits(char **coordinates)
{
	if (ft_get_matrix_len(coordinates) != 3 || !ft_is_a_double(coordinates[0])
		|| !ft_is_a_double(coordinates[1]) || !ft_is_a_double(coordinates[2]))
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
