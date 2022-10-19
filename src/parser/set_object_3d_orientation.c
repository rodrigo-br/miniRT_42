/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_3d_orientation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:10:10 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 11:18:15 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_object_3d_orientation(double *ob_x, double *ob_y, double *ob_z, char *s)
{
	char	**coordinates;
	double	x;
	double	y;
	double	z;

	coordinates = ft_split(s, ',');
	if (check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	x = ft_atod(coordinates[0]);
	y = ft_atod(coordinates[1]);
	z = ft_atod(coordinates[2]);
	if (x < -1 || x > 1.0 || y < -1 || y > 1.0 || z < -1 || z > 1.0)
		return (EXIT_FAILURE);
	*ob_x = x;
	*ob_y = y;
	*ob_z = z;
	return (EXIT_SUCCESS);
}
