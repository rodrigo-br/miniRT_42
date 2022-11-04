/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:54:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 10:34:43 by maolivei         ###   ########.fr       */
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
#define ERR_CAM_NOT_NORMALIZED "Camera orientation vector is not normalized."

static int	set_camera_field_of_view(char *token, t_rt_scene *s)
{
	if (!ft_isnumber(token))
		return (error(ERR_CAM_FIELD_VALUE));
	s->camera->fov = ft_atoi(token);
	if (!ft_isinrange_f(s->camera->fov, 0, 180))
		return (error(ERR_CAM_FIELD_RANGE));
	return (0);
}

static int	set_camera_orientation_vector(char *token, t_rt_scene *s)
{
	char		**vect;
	double		aux[3];

	vect = ft_split(token, ',');
	if (!vect || ft_splitsize(vect) != 3)
		return (ft_free_matrix((void *)&vect), error(ERR_CAM_OVECT_SETTN));
	if (!ft_isfloat(vect[0]) || !ft_isfloat(vect[1]) || !ft_isfloat(vect[2]))
		return (ft_free_matrix((void *)&vect), error(ERR_CAM_OVECT_VALUE));
	aux[0] = ft_atof(vect[0]);
	aux[1] = ft_atof(vect[1]);
	aux[2] = ft_atof(vect[2]);
	ft_free_matrix((void *)&vect);
	if (!ft_isinrange_f(aux[0], -1, 1) \
	|| !ft_isinrange_f(aux[1], -1, 1) \
	|| !ft_isinrange_f(aux[2], -1, 1))
		return (error(ERR_CAM_OVECT_RANGE));
	if (check_vector_normalization(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_CAM_NOT_NORMALIZED));
	s->camera->orientation = create_vector(aux[0], aux[1], aux[2]);
	return (0);
}

static int	set_camera_view_point(char *token, t_rt_scene *s)
{
	char	**vp;

	vp = ft_split(token, ',');
	if (!vp || ft_splitsize(vp) != 3)
		return (ft_free_matrix((void *)&vp), error(ERR_CAM_VIEWP_SETTN));
	if (!ft_isfloat(vp[0]) || !ft_isfloat(vp[1]) || !ft_isfloat(vp[2]))
		return (ft_free_matrix((void *)&vp), error(ERR_CAM_VIEWP_VALUE));
	s->camera->view_point = \
	create_point(ft_atof(vp[0]), ft_atof(vp[1]), ft_atof(vp[2]));
	ft_free_matrix((void *)&vp);
	return (0);
}

int	parse_camera(char **tokens, t_rt_scene *s)
{
	if (s->camera)
		return (error(ERR_CAM_ALREADY_SET));
	if (ft_splitsize(tokens) != 4)
		return (error(ERR_CAM_BAD_CONFIGS));
	s->camera = (t_rt_camera *)ft_calloc(1, sizeof(t_rt_camera));
	if (!s->camera)
		return (error(ERR_CAM_MALLOC_FAIL));
	if (set_camera_view_point(tokens[1], s) != 0)
		return (-1);
	if (set_camera_orientation_vector(tokens[2], s) != 0)
		return (-1);
	if (set_camera_field_of_view(tokens[3], s) != 0)
		return (-1);
	return (0);
}
