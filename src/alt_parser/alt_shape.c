/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 22:25:52 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_SHP_MISS_INFO "Not enough information available."
#define ERR_SHP_OVECT_VALUE "Invalid shape orientation vector value."
#define ERR_SHP_OVECT_RANGE "Shape orientation values must be between -1 and 1."
#define ERR_SHP_COLOR_SETTN "Invalid shape color settings."
#define ERR_SHP_COLOR_VALUE "Invalid shape color value."
#define ERR_SHP_COLOR_RANGE "Shape color channels must be between 0 and 255."

static t_rgb	*create_formatted_color(int r, int g, int b)
{
	return (create_color((r / 255), (g / 255), (b / 255)));
}

int	set_shape_color(char *token, t_object *shape)
{
	char	**rgb;
	int		aux[3];

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
	{
		ft_free_matrix((void *)&rgb);
		return (error(ERR_SHP_COLOR_SETTN));
	}
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
	{
		ft_free_matrix((void *)&rgb);
		return (error(ERR_SHP_COLOR_VALUE));
	}
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (!ft_isinrange(aux[0], 0, 255) \
	|| !ft_isinrange(aux[1], 0, 255) \
	|| !ft_isinrange(aux[2], 0, 255))
		return (error(ERR_SHP_COLOR_RANGE));
	free(shape->material->color);
	shape->material->color = create_formatted_color(aux[0], aux[1], aux[2]);
	return (0);
}

int	set_shape_orientation_vector(char *token, t_object *shape)
{
	char	**vec;
	double	aux[3];

	vec = ft_split(token, ',');
	if (!vec || ft_splitsize(vec) != 3)
	{
		ft_free_matrix((void *)&vec);
		return (-1);
	}
	if (!ft_isfloat(vec[0]) || !ft_isfloat(vec[1]) || !ft_isfloat(vec[2]))
	{
		ft_free_matrix((void *)&vec);
		return (error(ERR_SHP_OVECT_VALUE));
	}
	aux[0] = ft_atof(vec[0]);
	aux[1] = ft_atof(vec[1]);
	aux[2] = ft_atof(vec[2]);
	ft_free_matrix((void *)&vec);
	if (!ft_isinrange(aux[0], -1, 1) \
	|| !ft_isinrange(aux[1], -1, 1) \
	|| !ft_isinrange(aux[2], -1, 1))
		return (error(ERR_SHP_OVECT_RANGE));
	shape->orientation = create_vector(aux[0], aux[1], aux[2]);
	return (0);
}

int	set_shape_material(t_object *shape, t_rt_scene *s)
{
	if (!s->ambient || !s->light)
		return (error(ERR_SHP_MISS_INFO));
	shape->material->ambient = s->ambient->ratio;
	shape->material->diffuse = s->light->brightness;
	shape->material->specular = s->light->brightness;
	return (0);
}
