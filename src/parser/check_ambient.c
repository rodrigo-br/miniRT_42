/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:40:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 12:12:41 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
	ambient.rgb.opacity = 255;
	errors += set_object_rgb(&ambient.rgb.red, \
							&ambient.rgb.green, \
							&ambient.rgb.blue, \
							line_splited[2]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
