/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:22:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 11:17:40 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_cylinder(char **line_splited)
{
	t_object	object;
	int			errors;

	object.type = ID_CYLINDER;
	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_object_coordinates(&object, line_splited[1]);
	errors += set_object_3d_orientation(&object.cylinder.x_3d, \
										&object.cylinder.y_3d, \
										&object.cylinder.z_3d, \
										line_splited[2]);
	errors += set_double_value(&object.cylinder.diameter, line_splited[3]);
	errors += set_double_value(&object.cylinder.height, line_splited[4]);
	errors += set_object_rgb(&object, line_splited[5]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
