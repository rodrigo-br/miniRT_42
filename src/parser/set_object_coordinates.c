/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:25:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 11:45:41 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_object_coordinates(double *ob_x, double *ob_y, double *ob_z, char *s)
{
	char	**coordinates;

	coordinates = ft_split(s, ',');
	if (check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	*ob_x = ft_atod(coordinates[0]);
	*ob_y = ft_atod(coordinates[1]);
	*ob_z = ft_atod(coordinates[2]);
	return (EXIT_SUCCESS);
}
