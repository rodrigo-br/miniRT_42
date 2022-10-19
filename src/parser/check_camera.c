/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:15:19 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 11:56:51 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_camera_fov(t_camera *camera, char *s)
{
	int	fov;

	if (!s || !s[0] || !ft_is_all_digit(s))
		return (EXIT_FAILURE);
	fov = ft_atoi(s);
	if (fov > 180 || fov < 0)
		return (EXIT_FAILURE);
	camera->fov = fov;
	return (EXIT_SUCCESS);
}

int	check_camera(char **line_splited)
{
	t_camera	camera;
	int			errors;

	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_object_coordinates(&camera.view_x, \
									&camera.view_y, \
									&camera.view_z, \
									line_splited[1]);
	errors += set_object_3d_orientation(&camera.x_3d, \
										&camera.y_3d, \
										&camera.z_3d, \
										line_splited[2]);
	errors += set_camera_fov(&camera, line_splited[3]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
