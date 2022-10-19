/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:50:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 16:41:51 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_sphere(char **line_splited)
{
	(void)line_splited;
	/* t_object	object;
	char		**rgb;
	int			errors;

	object.type = ID_SPHERE;
	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_object_coordinates(&object.x, \
								&object.y, \
								&object.z, line_splited[1]);
	errors += set_double_value(&object.sphere, line_splited[2]);
	rgb = check_rgb(line_splited[3]);
	if (!rgb)
		errors = 1;
	else
		object.rgb = create_color(ft_atoi(rgb[0]), \
									ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	if (errors)
		return (EXIT_FAILURE); */
	return (EXIT_SUCCESS);
}
