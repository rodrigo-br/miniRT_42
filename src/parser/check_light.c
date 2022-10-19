/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:08:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 13:13:51 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

int	check_light(char **line_splited)
{
	t_light	light;
	char	**rgb;
	int		errors;

	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_object_coordinates(&light.x, \
									&light.y, \
									&light.z, \
									line_splited[1]);
	errors += set_brightness(&light, line_splited[2]);
	rgb = check_rgb(line_splited[3]);
	if (!rgb)
		errors = 1;
	else
		light.rgb = create_color(ft_atoi(rgb[0]), \
								ft_atoi(rgb[1]), \
								ft_atoi(rgb[2]));
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
