/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:46:16 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 12:04:29 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_plane(char **line_splited)
{
	t_object	object;
	int			errors;

	object.type = ID_PLANE;
	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_object_coordinates(&object.x, \
									&object.y, \
									&object.z, \
									line_splited[1]);
	errors += set_object_3d_orientation(&object.plane.x_3d, \
										&object.plane.y_3d, \
										&object.plane.z_3d, \
										line_splited[2]);
	object.rgb = (t_rgb *)malloc(sizeof(t_rgb));
	object.rgb->opacity = 255;
	errors += set_object_rgb(&object.rgb->red, \
							&object.rgb->green, \
							&object.rgb->blue, \
							line_splited[3]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
