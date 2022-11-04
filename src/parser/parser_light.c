/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:39:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 10:34:43 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_LGT_MALLOC_FAIL "Unable to allocate memory for light."
#define ERR_LGT_ALREADY_SET "Light must be set only once."
#define ERR_LGT_BAD_CONFIGS "Invalid light configuration."
#define ERR_LGT_POINT_SETTN "Invalid light point settings."
#define ERR_LGT_POINT_VALUE "Invalid light point value."
#define ERR_LGT_BRGHT_VALUE "Invalid light brightness value."
#define ERR_LGT_BRGHT_RANGE "Light brightness must be between 0 and 1."
#define ERR_LGT_COLOR_SETTN "Invalid light color settings."
#define ERR_LGT_COLOR_VALUE "Invalid light color value."
#define ERR_LGT_COLOR_RANGE "Light color channels must be between 0 and 255."

static int	set_light_color(char *token, t_rt_scene *s)
{
	char	**rgb;

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_LGT_COLOR_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_LGT_COLOR_VALUE));
	s->light->red = ft_atoi(rgb[0]);
	s->light->green = ft_atoi(rgb[1]);
	s->light->blue = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (!ft_isinrange_f(s->light->red, 0, 255) \
	|| !ft_isinrange_f(s->light->green, 0, 255) \
	|| !ft_isinrange_f(s->light->blue, 0, 255))
		return (error(ERR_LGT_COLOR_RANGE));
	return (0);
}

static int	set_light_brightness(char *token, t_rt_scene *s)
{
	if (!ft_isfloat(token))
		return (error(ERR_LGT_BRGHT_VALUE));
	s->light->brightness = ft_atof(token);
	if (!ft_isinrange_f(s->light->brightness, 0.0, 1.0))
		return (error(ERR_LGT_BRGHT_RANGE));
	return (0);
}

static int	set_light_point(char *token, t_rt_scene *s)
{
	char	**lp;

	lp = ft_split(token, ',');
	if (!lp || ft_splitsize(lp) != 3)
		return (ft_free_matrix((void *)&lp), error(ERR_LGT_POINT_SETTN));
	if (!ft_isfloat(lp[0]) || !ft_isfloat(lp[1]) || !ft_isfloat(lp[2]))
		return (ft_free_matrix((void *)&lp), error(ERR_LGT_POINT_VALUE));
	s->light->x = ft_atof(lp[0]);
	s->light->y = ft_atof(lp[1]);
	s->light->z = ft_atof(lp[2]);
	ft_free_matrix((void *)&lp);
	return (0);
}

int	parse_light(char **tokens, t_rt_scene *s)
{
	if (s->light)
		return (error(ERR_LGT_ALREADY_SET));
	if (ft_splitsize(tokens) != 4)
		return (error(ERR_LGT_BAD_CONFIGS));
	s->light = (t_rt_light *)ft_calloc(1, sizeof(t_rt_light));
	if (!s->light)
		return (error(ERR_LGT_MALLOC_FAIL));
	if (set_light_point(tokens[1], s) != 0)
		return (-1);
	if (set_light_brightness(tokens[2], s) != 0)
		return (-1);
	if (set_light_color(tokens[3], s) != 0)
		return (-1);
	return (0);
}
