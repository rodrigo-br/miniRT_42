/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:08:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/20 09:59:08 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_brightness(char *s)
{
	double	brightness;

	if (!ft_is_a_double(s))
		return (EXIT_FAILURE);
	brightness = ft_atod(s);
	if (brightness < 0.0 || brightness > 1.0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_light	*set_light(char **coordinates, char **rgb, double brightness)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
	{
		ft_free_matrix((void *)&rgb);
		ft_free_matrix((void *)&coordinates);
		return (NULL);
	}
	light->x = ft_atod(coordinates[0]);
	light->y = ft_atod(coordinates[1]);
	light->z = ft_atod(coordinates[2]);
	light->rgb = create_color(ft_atoi(rgb[0]), \
							ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	light->brightness = brightness;
	ft_free_matrix((void *)&coordinates);
	ft_free_matrix((void *)&rgb);
	return (light);
}

int	check_light(char **line_splited, t_light **light)
{
	char	**coordinates;
	char	**rgb;

	if (ft_get_matrix_len(line_splited) != 4)
		return (EXIT_FAILURE);
	coordinates = ft_split(line_splited[1], ',');
	if (!coordinates || check_coordinates_digits(coordinates)
		|| check_brightness(line_splited[2]))
		return (EXIT_FAILURE);
	rgb = check_rgb(line_splited[3]);
	if (!rgb)
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	*light = set_light(coordinates, rgb, ft_atod(line_splited[2]));
	if (!(*light))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
