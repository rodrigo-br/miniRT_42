/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:15:19 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 17:04:03 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_camera_fov(char *s)
{
	int	fov;

	if (!s || !s[0] || !ft_is_all_digit(s))
		return (EXIT_FAILURE);
	fov = ft_atoi(s);
	if (fov > 180 || fov < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_camera	*set_camera(char **coordinates, char **line_splited)
{
	t_camera	*camera;
	char		**ori_3d;

	ori_3d = ft_split(line_splited[0], ',');
	if (!ori_3d)
		return (ft_free_matrix((void *)&coordinates), NULL);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (ft_free_matrix((void *)&ori_3d), \
		ft_free_matrix((void *)&coordinates), NULL);
	camera->view_x = ft_atod(coordinates[0]);
	camera->view_y = ft_atod(coordinates[1]);
	camera->view_z = ft_atod(coordinates[2]);
	camera->x_3d = ft_atod(ori_3d[0]);
	camera->y_3d = ft_atod(ori_3d[1]);
	camera->z_3d = ft_atod(ori_3d[2]);
	camera->fov = ft_atoi(line_splited[1]);
	return (ft_free_matrix((void *)&coordinates), \
	ft_free_matrix((void *)&ori_3d), camera);
}

int	check_camera(char **line_splited, t_camera **camera)
{
	int			errors;
	char	**coordinates;

	if (ft_get_matrix_len(line_splited) != 4)
		return (EXIT_FAILURE);
	coordinates = ft_split(line_splited[1], ',');
	if (!coordinates)
		return (EXIT_FAILURE);
	if (check_coordinates_digits(coordinates))
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	errors = check_object_3d_orientation(line_splited[2]);
	errors += check_camera_fov(line_splited[3]);
	if (errors)
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	*camera = set_camera(coordinates, line_splited + 2);
	if (!(*camera))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
