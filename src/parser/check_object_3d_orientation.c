/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_3d_orientation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:44:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/20 15:08:11 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_object_3d_orientation(char *s)
{
	char	**coordinates;
	double	x;
	double	y;
	double	z;

	coordinates = ft_split(s, ',');
	if (!coordinates || check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	x = ft_atod(coordinates[0]);
	y = ft_atod(coordinates[1]);
	z = ft_atod(coordinates[2]);
	ft_free_matrix((void *)&coordinates);
	if (x < -1 || x > 1.0 || y < -1 || y > 1.0 || z < -1 || z > 1.0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
