/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:08:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 14:18:01 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_light_rgb(t_light *light, char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(s, ',');
	if (check_rgb_digits(rgb, &red, &green, &blue))
		return (EXIT_FAILURE);
	light->rgb.opacity = 255;
	light->rgb.red = red;
	light->rgb.green = green;
	light->rgb.blue = blue;
	return (EXIT_SUCCESS);
}

int	set_brightness(t_light *light, char *s)
{
	double	brightness;

	if (!ft_is_a_double(s))
		return (EXIT_FAILURE);
	brightness = ft_atod(s);
	if (brightness < 0.0 || brightness > 1.0)
		return (EXIT_FAILURE);
	light->brightness = brightness;
	return (EXIT_SUCCESS);
}

int	set_light_coordinates(t_light *light, char *s)
{
	char	**coordinates;

	coordinates = ft_split(s, ',');
	if (check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	light->x = ft_atod(coordinates[0]);
	light->y = ft_atod(coordinates[1]);
	light->z = ft_atod(coordinates[2]);
	return (EXIT_SUCCESS);
}

int	check_light(char **line_splited)
{
	t_light	light;
	int		errors;

	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_light_coordinates(&light, line_splited[1]);
	errors += set_brightness(&light, line_splited[2]);
	errors += set_light_rgb(&light, line_splited[3]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
