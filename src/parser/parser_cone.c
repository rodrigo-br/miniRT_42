/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:01:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 10:50:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_CON_SCL "Unable to allocate memory for cone's scaling."
#define ERR_CON_RTT "Unable to allocate memory for cone's rotation."
#define ERR_CON_TRL "Unable to allocate memory for cone's translation."
#define ERR_CON_TRF "Unable to allocate memory for cone's transformation."
#define ERR_CON_MALLOC_FAIL "Unable to allocate memory for cone."
#define ERR_CON_BAD_CONFIGS "Invalid cone configuration."
#define ERR_CON_COORD_SETTN "Invalid cone coordinates settings."
#define ERR_CON_COORD_VALUE "Invalid cone coordinates value."
#define ERR_CON_DMTER_VALUE "Invalid cone diameter value."
#define ERR_CON_DMTER_RANGE "Cone diameter value must be greater than 0."
#define ERR_CON_HEIGHT_VALUE "Invalid cone height value."
#define ERR_CON_HEIGHT_RANGE "cone height value must be greater than 0."

static int	set_cone_transformation(t_object *cone)
{
	t_matrix	*trans;
	t_matrix	*rotat;
	t_matrix	*scale;
	t_matrix	*final;

	trans = translate_matrix(
			cone->cone.position.x,
			cone->cone.position.y,
			cone->cone.position.z);
	if (!trans)
		return (error(ERR_CON_TRL));
	rotat = full_rotation_matrix(cone->orientation);
	if (!rotat)
		return (free(trans), error(ERR_CON_RTT));
	scale = scale_matrix(cone->cone.diameter, 1, cone->cone.diameter);
	if (!scale)
		return (free(trans), free(rotat), error(ERR_CON_RTT));
	final = multiply_matrix_triple(trans, rotat, scale);
	if (!final)
		return (free(trans), free(rotat), free(scale), error(ERR_CON_TRF));
	set_object_transformation(cone, final);
	free(trans);
	free(rotat);
	free(scale);
	return (0);
}

static int	set_cone_height(char *token, t_object *cone)
{
	double	height;
	double	half;

	if (!ft_isfloat(token))
		return (error(ERR_CON_HEIGHT_VALUE));
	height = ft_atof(token);
	if (height <= 0.0)
		return (error(ERR_CON_HEIGHT_RANGE));
	half = height / 2.0;
	cone->cone.min = -half;
	cone->cone.max = half;
	return (0);
}

static int	set_cone_diameter(char *token, t_object *cone)
{
	if (!ft_isfloat(token))
		return (error(ERR_CON_DMTER_VALUE));
	cone->cone.diameter = ft_atof(token);
	if (cone->cone.diameter <= 0.0)
		return (error(ERR_CON_DMTER_RANGE));
	return (0);
}

static int	set_cone_coordinates(char *token, t_object *cone)
{
	char	**coord;
	double	aux[3];

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_CON_COORD_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_CON_COORD_VALUE));
	aux[0] = ft_atof(coord[0]);
	aux[1] = ft_atof(coord[1]);
	aux[2] = ft_atof(coord[2]);
	ft_free_matrix((void *)&coord);
	cone->cone.position = (t_point){aux[0], aux[1], aux[2], 1};
	return (0);
}

int	parse_cone(char **tokens, t_rt_scene *s)
{
	const size_t	splitsize = ft_splitsize(tokens);
	t_object		*cone;

	if (splitsize < 6 || splitsize > 8)
		return (error(ERR_CON_BAD_CONFIGS));
	cone = create_cone();
	if (!cone)
		return (error(ERR_CON_MALLOC_FAIL));
	if (set_cone_coordinates(tokens[1], cone) != 0)
		return (destroy_shape(cone), -1);
	if (set_shape_orientation_vector(tokens[2], cone) != 0)
		return (destroy_shape(cone), -1);
	if (set_cone_diameter(tokens[3], cone) != 0)
		return (destroy_shape(cone), -1);
	if (set_cone_height(tokens[4], cone) != 0)
		return (destroy_shape(cone), -1);
	if (set_shape_color(tokens[5], cone) != 0)
		return (destroy_shape(cone), -1);
	if (set_shape_checkerboard(tokens, cone, 6) != 0)
		return (destroy_shape(cone), -1);
	if (set_cone_transformation(cone) != 0)
		return (destroy_shape(cone), -1);
	if (set_shape_linked_list_node(cone, s) != 0)
		return (destroy_shape(cone), -1);
	return (0);
}
