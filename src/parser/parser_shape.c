/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 15:13:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_SHP_MISS_INFO "Not enough information available."
#define ERR_SHP_OVECT_SETTN "Invalid shape orientation vector settings."
#define ERR_SHP_OVECT_VALUE "Invalid shape orientation vector value."
#define ERR_SHP_OVECT_RANGE "Shape orientation values must be between -1 and 1."
#define ERR_SHP_COLOR_SETTN "Invalid shape color settings."
#define ERR_SHP_COLOR_VALUE "Invalid shape color value."
#define ERR_SHP_COLOR_RANGE "Shape color channels must be between 0 and 255."
#define ERR_SHP_NOT_NORMALIZED "Shape orientation vector is not normalized."

int	set_shape_color(char *token, t_object *shape)
{
	char	**rgb;
	int		aux[3];

	rgb = ft_split(token, ',');
	if (!rgb || ft_splitsize(rgb) != 3)
		return (ft_free_matrix((void *)&rgb), error(ERR_SHP_COLOR_SETTN));
	if (!ft_isnumber(rgb[0]) || !ft_isnumber(rgb[1]) || !ft_isnumber(rgb[2]))
		return (ft_free_matrix((void *)&rgb), error(ERR_SHP_COLOR_VALUE));
	aux[0] = ft_atoi(rgb[0]);
	aux[1] = ft_atoi(rgb[1]);
	aux[2] = ft_atoi(rgb[2]);
	ft_free_matrix((void *)&rgb);
	if (!ft_isinrange_f(aux[0], 0, 255) \
	|| !ft_isinrange_f(aux[1], 0, 255) \
	|| !ft_isinrange_f(aux[2], 0, 255))
		return (error(ERR_SHP_COLOR_RANGE));
	free(shape->material->color);
	shape->material->color = create_formatted_color(aux[0], aux[1], aux[2]);
	return (0);
}

int	set_shape_orientation_vector(char *token, t_object *shape)
{
	char		**vect;
	double		aux[3];

	vect = ft_split(token, ',');
	if (!vect || ft_splitsize(vect) != 3)
		return (ft_free_matrix((void *)&vect), error(ERR_SHP_OVECT_SETTN));
	if (!ft_isfloat(vect[0]) || !ft_isfloat(vect[1]) || !ft_isfloat(vect[2]))
		return (ft_free_matrix((void *)&vect), error(ERR_SHP_OVECT_VALUE));
	aux[0] = ft_atof(vect[0]);
	aux[1] = ft_atof(vect[1]);
	aux[2] = ft_atof(vect[2]);
	ft_free_matrix((void *)&vect);
	if (!ft_isinrange_f(aux[0], -1, 1) \
	|| !ft_isinrange_f(aux[1], -1, 1) \
	|| !ft_isinrange_f(aux[2], -1, 1))
		return (error(ERR_SHP_OVECT_RANGE));
	if (check_vector_normalization(aux[0], aux[1], aux[2]) != 0)
		return (error(ERR_SHP_NOT_NORMALIZED));
	shape->orientation = create_vector(aux[0], aux[1], aux[2]);
	return (0);
}

int	set_shape_material(t_object *shape, t_rt_scene *s)
{
	if (!s->ambient || !s->lights)
		return (error(ERR_SHP_MISS_INFO));
	free(shape->material->ambient);
	shape->material->ambient = \
	scalar_multiply_color(s->ambient->color, s->ambient->ratio);
	shape->material->diffuse = s->brightness;
	shape->material->specular = s->brightness;
	return (0);
}
