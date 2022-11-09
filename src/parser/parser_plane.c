/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:23:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 10:49:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_PLN_RTT "Unable to allocate memory for plane's rotation."
#define ERR_PLN_TRL "Unable to allocate memory for plane's translation."
#define ERR_PLN_TRF "Unable to allocate memory for plane's transformation."
#define ERR_PLN_MALLOC_FAIL "Unable to allocate memory for plane."
#define ERR_PLN_BAD_CONFIGS "Invalid plane configuration."
#define ERR_PLN_COORD_SETTN "Invalid plane coordinates settings."
#define ERR_PLN_COORD_VALUE "Invalid plane coordinates value."

static int	set_plane_transformation(t_object *plane)
{
	t_matrix	*trans;
	t_matrix	*rotat;
	t_matrix	*final;

	trans = translate_matrix(
			plane->plane.position.x,
			plane->plane.position.y,
			plane->plane.position.z);
	if (!trans)
		return (error(ERR_PLN_TRL));
	rotat = full_rotation_matrix(plane->orientation);
	if (!rotat)
		return (free(trans), error(ERR_PLN_RTT));
	final = multiply_matrix(trans, rotat);
	if (!final)
		return (free(trans), free(rotat), error(ERR_PLN_TRF));
	set_object_transformation(plane, final);
	free(trans);
	free(rotat);
	return (0);
}

static int	set_plane_coordinates(char *token, t_object *plane)
{
	char	**coord;
	double	aux[3];

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_PLN_COORD_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_PLN_COORD_VALUE));
	aux[0] = ft_atof(coord[0]);
	aux[1] = ft_atof(coord[1]);
	aux[2] = ft_atof(coord[2]);
	ft_free_matrix((void *)&coord);
	plane->plane.position = (t_point){aux[0], aux[1], aux[2], 1};
	return (0);
}

int	parse_plane(char **tokens, t_rt_scene *s)
{
	const size_t	splitsize = ft_splitsize(tokens);
	t_object		*plane;

	if (splitsize < 4 || splitsize > 6)
		return (error(ERR_PLN_BAD_CONFIGS));
	plane = create_plane();
	if (!plane)
		return (error(ERR_PLN_MALLOC_FAIL));
	if (set_plane_coordinates(tokens[1], plane) != 0)
		return (destroy_shape(plane), -1);
	if (set_shape_orientation_vector(tokens[2], plane) != 0)
		return (destroy_shape(plane), -1);
	if (set_shape_color(tokens[3], plane) != 0)
		return (destroy_shape(plane), -1);
	if (set_shape_checkerboard(tokens, plane, 4) != 0)
		return (destroy_shape(plane), -1);
	if (set_plane_transformation(plane) != 0)
		return (destroy_shape(plane), -1);
	if (set_shape_linked_list_node(plane, s) != 0)
		return (destroy_shape(plane), -1);
	return (0);
}
