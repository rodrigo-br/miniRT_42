/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:39:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 17:52:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_LGT_LINKED_LIST "Unable to allocate memory for light list node."
#define ERR_LGT_MALLOC_FAIL "Unable to allocate memory for light."
#define ERR_LGT_BAD_CONFIGS "Invalid light configuration."
#define ERR_LGT_POINT_SETTN "Invalid light point settings."
#define ERR_LGT_POINT_VALUE "Invalid light point value."
#define ERR_LGT_BRGHT_VALUE "Invalid light brightness value."
#define ERR_LGT_BRGHT_RANGE "Light brightness must be between 0 and 1."
#define ERR_LGT_COLOR_SETTN "Invalid light color settings."
#define ERR_LGT_COLOR_VALUE "Invalid light color value."
#define ERR_LGT_COLOR_RANGE "Light color channels must be between 0 and 255."

static int	set_light_color(char *token, t_light_pnt *lp, t_rt_scene *s)
{
	char	**rgb;
	double	aux[3];
	t_rgb	*tmp;

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_LGT_COLOR_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_LGT_COLOR_VALUE));
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (!ft_isinrange_f(aux[0], 0, 255) \
	|| !ft_isinrange_f(aux[1], 0, 255) \
	|| !ft_isinrange_f(aux[2], 0, 255))
		return (error(ERR_LGT_COLOR_RANGE));
	tmp = create_formatted_color(aux[0], aux[1], aux[2]);
	lp->intensity = scalar_multiply_color(tmp, s->brightness);
	free(tmp);
	return (0);
}

static int	set_light_brightness(char *token, t_rt_scene *s)
{
	if (!ft_isfloat(token))
		return (error(ERR_LGT_BRGHT_VALUE));
	s->brightness = ft_atof(token);
	if (!ft_isinrange_f(s->brightness, 0.0, 1.0))
		return (error(ERR_LGT_BRGHT_RANGE));
	return (0);
}

static int	set_light_point_coordinates(char *token, t_light_pnt *lp)
{
	char	**coord;

	coord = ft_split(token, ',');
	if (!coord || ft_splitsize(coord) != 3)
		return (ft_free_matrix((void *)&coord), error(ERR_LGT_POINT_SETTN));
	if (!ft_isfloat(coord[0]) || !ft_isfloat(coord[1]) || !ft_isfloat(coord[2]))
		return (ft_free_matrix((void *)&coord), error(ERR_LGT_POINT_VALUE));
	lp->position = \
	create_point(ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	ft_free_matrix((void *)&coord);
	return (0);
}

int	parse_light(char **tokens, t_rt_scene *s)
{
	t_light_pnt	*light_point;
	t_list		*node;

	if (ft_splitsize(tokens) != 4)
		return (error(ERR_LGT_BAD_CONFIGS));
	light_point = create_light_point(NULL, NULL);
	if (!light_point)
		return (error(ERR_LGT_MALLOC_FAIL));
	if (set_light_point_coordinates(tokens[1], light_point) != 0)
		return (destroy_light_point(light_point), -1);
	if (set_light_brightness(tokens[2], s) != 0)
		return (destroy_light_point(light_point), -1);
	if (set_light_color(tokens[3], light_point, s) != 0)
		return (destroy_light_point(light_point), -1);
	node = ft_lstnew(light_point);
	if (!node)
		return (destroy_light_point(light_point), error(ERR_LGT_LINKED_LIST));
	ft_lstadd_front(&s->lights, node);
	return (0);
}
