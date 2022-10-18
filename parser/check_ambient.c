/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:40:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 15:49:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_ambient_rgb(t_ambience *ambient, char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(s, ',');
	if (check_rgb_digits(rgb, &red, &green, &blue))
		return (EXIT_FAILURE);
	ambient->rgb.opacity = 255;
	ambient->rgb.red = red;
	ambient->rgb.green = green;
	ambient->rgb.blue = blue;
	return (EXIT_SUCCESS);
}

int	set_ambient_light_ratio(t_ambience *ambient, char *s)
{
	double	ratio;

	if (!ft_is_a_double(s))
		return (EXIT_FAILURE);
	ratio = ft_atod(s);
	if (ratio < 0.0 || ratio > 1.0)
		return (EXIT_FAILURE);
	ambient->ratio = ratio;
	return (EXIT_SUCCESS);
}

int	check_ambient(char **line_splited)
{
	t_ambience	ambient;
	int			errors;

	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || line_splited[3])
		return (EXIT_FAILURE);
	errors = set_ambient_light_ratio(&ambient, line_splited[1]);
	errors += set_ambient_rgb(&ambient, line_splited[2]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
