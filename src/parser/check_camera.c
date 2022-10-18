/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:15:19 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 18:39:00 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_camera_fov(t_camera *camera, char *s)
{
	int	fov;

	if (!s || !s[0] || s[1] || !ft_is_all_digit(s))
		return (EXIT_FAILURE);
	fov = ft_atoi(s);
	if (fov > 180 || fov < 0)
		return (EXIT_FAILURE);
	camera->fov = fov;
	return (EXIT_SUCCESS);
}

int	set_camera_3d_orientation(t_camera *camera, char *s)
{
	char	**coordinates;
	double	x;
	double	y;
	double	z;

	coordinates = ft_split(s, ',');
	if (check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	x = ft_atod(coordinates[0]);
	y = ft_atod(coordinates[1]);
	z = ft_atod(coordinates[2]);
	if (x < -1 || x > 1.0 || y < -1 || y > 1.0 || z < -1 || z > 1.0)
		return (EXIT_FAILURE);
	camera->x_3d = x;
	camera->y_3d = y;
	camera->z_3d = z;
	return (EXIT_SUCCESS);
}

int	set_camera_coordinates(t_camera *camera, char *s)
{
	char	**coordinates;

	coordinates = ft_split(s, ',');
	if (check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	camera->view_x = ft_atod(coordinates[0]);
	camera->view_y = ft_atod(coordinates[1]);
	camera->view_z = ft_atod(coordinates[2]);
	return (EXIT_SUCCESS);
}

int	check_camera(char **line_splited)
{
	t_camera	camera;
	int			errors;

	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_camera_coordinates(&camera, line_splited[1]);
	errors += set_camera_3d_orientation(&camera, line_splited[2]);
	errors += set_camera_fov(&camera, line_splited[3]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
