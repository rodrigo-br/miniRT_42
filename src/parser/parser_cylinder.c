/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:01:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 10:45:04 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_CYL_SCL "Unable to allocate memory for cylinder's scaling."
#define ERR_CYL_RTT "Unable to allocate memory for cylinder's rotation."
#define ERR_CYL_TRL "Unable to allocate memory for cylinder's translation."
#define ERR_CYL_TRF "Unable to allocate memory for cylinder's transformation."
#define ERR_CYL_MALLOC_FAIL "Unable to allocate memory for cylinder."
#define ERR_CYL_BAD_CONFIGS "Invalid cylinder configuration."
#define ERR_CYL_COORD_SETTN "Invalid cylinder coordinates settings."
#define ERR_CYL_COORD_VALUE "Invalid cylinder coordinates value."
#define ERR_CYL_DMTER_VALUE "Invalid cylinder diameter value."
#define ERR_CYL_DMTER_RANGE "Cylinder diameter value must be greater than 0."
#define ERR_CYL_HEIGHT_VALUE "Invalid cylinder height value."
#define ERR_CYL_HEIGHT_RANGE "Cylinder height value must be greater than 0."

static int	set_cylinder_transformation(t_object *cyl)
{
	t_matrix	*trans;
	t_matrix	*rotat;
	t_matrix	*scale;
	t_matrix	*final;

	trans = translate_matrix(
			cyl->cylinder.position.x,
			cyl->cylinder.position.y,
			cyl->cylinder.position.z);
	if (!trans)
		return (error(ERR_CYL_TRL));
	rotat = full_rotation_matrix(cyl->orientation);
	if (!rotat)
		return (free(trans), error(ERR_CYL_RTT));
	scale = scale_matrix(cyl->cylinder.diameter, 1, cyl->cylinder.diameter);
	if (!scale)
		return (free(trans), free(rotat), error(ERR_CYL_RTT));
	final = multiply_matrix_triple(trans, rotat, scale);
	if (!final)
		return (free(trans), free(rotat), free(scale), error(ERR_CYL_TRF));
	set_object_transformation(cyl, final);
	free(trans);
	free(rotat);
	free(scale);
	return (0);
}

static int	set_cylinder_height(char *token, t_object *cyl)
{
	double	height;
	double	half;

	if (!ft_isfloat(token))
		return (error(ERR_CYL_HEIGHT_VALUE));
	height = ft_atof(token);
	if (height <= 0.0)
		return (error(ERR_CYL_HEIGHT_RANGE));
	half = height / 2.0;
	cyl->cylinder.min = -half;
	cyl->cylinder.max = half;
	return (0);
}

static int	set_cylinder_diameter(char *token, t_object *cyl)
{
	if (!ft_isfloat(token))
		return (error(ERR_CYL_DMTER_VALUE));
	cyl->cylinder.diameter = ft_atof(token);
	if (cyl->cylinder.diameter <= 0.0)
		return (error(ERR_CYL_DMTER_RANGE));
	cyl->cylinder.diameter /= 2.0;
	return (0);
}

static int	set_cylinder_coordinates(char *token, t_object *cyl)
{
	char	**coord;
	double	aux[3];

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_CYL_COORD_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_CYL_COORD_VALUE));
	aux[0] = ft_atof(coord[0]);
	aux[1] = ft_atof(coord[1]);
	aux[2] = ft_atof(coord[2]);
	ft_free_matrix((void *)&coord);
	cyl->cylinder.position = (t_point){aux[0], aux[1], aux[2], 1};
	return (0);
}

int	parse_cylinder(char **tokens, t_rt_scene *s)
{
	const size_t	splitsize = ft_splitsize(tokens);
	t_object		*cylinder;

	if (splitsize < 6 || splitsize > 8)
		return (error(ERR_CYL_BAD_CONFIGS));
	cylinder = create_cylinder();
	if (!cylinder)
		return (error(ERR_CYL_MALLOC_FAIL));
	if (set_cylinder_coordinates(tokens[1], cylinder) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_shape_orientation_vector(tokens[2], cylinder) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_cylinder_diameter(tokens[3], cylinder) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_cylinder_height(tokens[4], cylinder) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_shape_color(tokens[5], cylinder) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_shape_checkerboard(tokens, cylinder, 6) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_cylinder_transformation(cylinder) != 0)
		return (destroy_shape(cylinder), -1);
	if (set_shape_linked_list_node(cylinder, s) != 0)
		return (destroy_shape(cylinder), -1);
	return (0);
}
