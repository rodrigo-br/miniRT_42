/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:54:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 20:19:35 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_CAM_MALLOC_FAIL "Unable to allocate memory for camera."
#define ERR_CAM_ALREADY_SET "Camera must be set only once."
#define ERR_CAM_BAD_CONFIGS "Invalid camera configuration."
#define ERR_CAM_VIEWP_SETTN "Invalid camera view point settings."
#define ERR_CAM_VIEWP_VALUE "Invalid camera view point value."
#define ERR_CAM_OVECT_SETTN "Invalid camera orientation vector settings."
#define ERR_CAM_OVECT_VALUE "Invalid camera orientation vector value."
#define ERR_CAM_OVECT_RANGE "Camera orietation values must be between -1 and 1."
#define ERR_CAM_FIELD_VALUE "Invalid camera field of view value."
#define ERR_CAM_FIELD_RANGE "Camera field of view must be between 0 and 180."

static int	set_camera_field_of_view(char *token, t_rt_scene *s)
{
	if (!ft_isnumber(token))
		return (ft_putendl_fd(ERR_CAM_FIELD_VALUE, STDERR), -1);
	s->camera->fov = ft_atoi(token);
	if (!ft_isinrange(s->camera->fov, 0, 180))
		return (ft_putendl_fd(ERR_CAM_FIELD_RANGE, STDERR), -1);
	return (0);
}

static int	set_camera_orientation_vector(char *token, t_rt_scene *s)
{
	char	**vect;

	vect = ft_split(token, ',');
	if (!vect || ft_splitsize(vect) != 3)
	{
		ft_free_matrix((void *)&vect);
		return (ft_putendl_fd(ERR_CAM_OVECT_SETTN, STDERR), -1);
	}
	if (!ft_isfloat(vect[0]) || !ft_isfloat(vect[1]) || !ft_isfloat(vect[2]))
	{
		ft_free_matrix((void *)&vect);
		return (ft_putendl_fd(ERR_CAM_OVECT_VALUE, STDERR), -1);
	}
	s->camera->x_3d = ft_atof(vect[0]);
	s->camera->y_3d = ft_atof(vect[1]);
	s->camera->z_3d = ft_atof(vect[2]);
	ft_free_matrix((void *)&vect);
	if (!ft_isinrange(s->camera->x_3d, -1, 1) \
	|| !ft_isinrange(s->camera->y_3d, -1, 1) \
	|| !ft_isinrange(s->camera->z_3d, -1, 1))
		return (ft_putendl_fd(ERR_CAM_OVECT_RANGE, STDERR), -1);
	return (0);
}

static int	set_camera_view_point(char *token, t_rt_scene *s)
{
	char	**vp;

	vp = ft_split(token, ',');
	if (!vp || ft_splitsize(vp) != 3)
	{
		ft_free_matrix((void *)&vp);
		return (ft_putendl_fd(ERR_CAM_VIEWP_SETTN, STDERR), -1);
	}
	if (!ft_isfloat(vp[0]) || !ft_isfloat(vp[1]) || !ft_isfloat(vp[2]))
	{
		ft_free_matrix((void *)&vp);
		return (ft_putendl_fd(ERR_CAM_VIEWP_VALUE, STDERR), -1);
	}
	s->camera->view_x = ft_atof(vp[0]);
	s->camera->view_y = ft_atof(vp[1]);
	s->camera->view_z = ft_atof(vp[2]);
	ft_free_matrix((void *)&vp);
	return (0);
}

int	parse_camera(char **tokens, t_rt_scene *s)
{
	if (s->camera)
		return (ft_putendl_fd(ERR_CAM_ALREADY_SET, STDERR), -1);
	if (ft_splitsize(tokens) != 4)
		return (ft_putendl_fd(ERR_CAM_BAD_CONFIGS, STDERR), -1);
	s->camera = (t_rt_camera *)malloc(sizeof(t_rt_camera));
	if (!s->camera)
		return (ft_putendl_fd(ERR_CAM_MALLOC_FAIL, STDERR), -1);
	if (set_camera_view_point(tokens[1], s) != 0)
		return (-1);
	if (set_camera_orientation_vector(tokens[2], s) != 0)
		return (-1);
	if (set_camera_field_of_view(tokens[3], s) != 0)
		return (-1);
	return (0);
}
