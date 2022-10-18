/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:04:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 13:04:52 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_coordinates_digits(char **coordinates)
{
	if (!coordinates || !coordinates[0] || !coordinates[1] || !coordinates[2]
		|| coordinates[3] || !ft_is_a_double(coordinates[0])
		|| !ft_is_a_double(coordinates[1]) || !ft_is_a_double(coordinates[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_rgb_digits(char **rgb, int *red, int *green, int *blue)
{
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || !ft_is_all_digit(rgb[0])
		|| rgb[3] || !ft_is_all_digit(rgb[1]) || !ft_is_all_digit(rgb[2]))
		return (EXIT_FAILURE);
	*red = ft_atoi(rgb[0]);
	*green = ft_atoi(rgb[1]);
	*blue = ft_atoi(rgb[2]);
	if (*red < 0 && *red > 255 && *green < 0 && *green > 255
		&& *blue < 0 && *blue > 255)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
