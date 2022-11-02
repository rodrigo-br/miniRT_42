/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:11:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 21:00:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_AMB_MALLOC_FAIL "Unable to allocate memory for ambient."
#define ERR_AMB_ALREADY_SET "Ambient lighting must be set only once."
#define ERR_AMB_BAD_CONFIGS "Invalid ambient configuration."
#define ERR_AMB_RATIO_VALUE "Invalid ambient lighting ratio value."
#define ERR_AMB_RATIO_RANGE "Ambient lighting ratio must be between 0 and 1."
#define ERR_AMB_COLOR_SETTN "Invalid ambient color settings."
#define ERR_AMB_COLOR_VALUE "Invalid ambient color value."
#define ERR_AMB_COLOR_RANGE "Ambient color channels must be between 0 and 255."

static int	set_ambient_ratio(char *token, t_rt_scene *s)
{
	if (!ft_isfloat(token))
		return (ft_putendl_fd(ERR_AMB_RATIO_VALUE, STDERR), -1);
	s->ambient->ratio = ft_atof(token);
	if (!ft_isinrange(s->ambient->ratio, 0.0, 1.0))
		return (ft_putendl_fd(ERR_AMB_RATIO_RANGE, STDERR), -1);
	return (0);
}

static int	set_ambient_color(char *token, t_rt_scene *s)
{
	char	**rgb;

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
	{
		ft_free_matrix((void *)&rgb);
		return (ft_putendl_fd(ERR_AMB_COLOR_SETTN, STDERR), -1);
	}
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
	{
		ft_free_matrix((void *)&rgb);
		return (ft_putendl_fd(ERR_AMB_COLOR_VALUE, STDERR), -1);
	}
	s->ambient->red = ft_atoi(rgb[0]);
	s->ambient->green = ft_atoi(rgb[1]);
	s->ambient->blue = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (!ft_isinrange(s->ambient->red, 0, 255) \
	|| !ft_isinrange(s->ambient->green, 0, 255) \
	|| !ft_isinrange(s->ambient->blue, 0, 255))
		return (ft_putendl_fd(ERR_AMB_COLOR_RANGE, STDERR), -1);
	return (0);
}

int	parse_ambient(char **tokens, t_rt_scene *s)
{
	if (s->ambient)
		return (ft_putendl_fd(ERR_AMB_ALREADY_SET, STDERR), -1);
	if (ft_splitsize(tokens) != 3)
		return (ft_putendl_fd(ERR_AMB_BAD_CONFIGS, STDERR), -1);
	s->ambient = (t_rt_ambient *)malloc(sizeof(t_rt_ambient));
	if (!s->ambient)
		return (ft_putendl_fd(ERR_AMB_MALLOC_FAIL, STDERR), -1);
	if (set_ambient_ratio(tokens[1], s) != 0)
		return (-1);
	if (set_ambient_color(tokens[2], s) != 0)
		return (-1);
	return (0);
}
