/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:16:40 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 22:26:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_SPH_SCL "Unable to allocate memory for sphere's scaling."
#define ERR_SPH_TRL "Unable to allocate memory for sphere's translation."
#define ERR_SPH_TRF "Unable to allocate memory for sphere's transformation."
#define ERR_SPH_MALLOC_FAIL "Unable to allocate memory for sphere."
#define SPH_LIST "Unable to allocate memory for sphere list node."
#define ERR_SPH_BAD_CONFIGS "Invalid sphere configuration."
#define ERR_SPH_CENTR_SETTN "Invalid sphere center coordinates settings."
#define ERR_SPH_CENTR_VALUE "Invalid sphere center coordinates value."
#define ERR_SPH_DMTER_VALUE "Invalid sphere diameter value."
#define ERR_SPH_DMTER_RANGE "Sphere diameter value must be greater than 0."

static int	set_sphere_transformation(t_object *sphere)
{
	t_matrix	*trans;
	t_matrix	*scale;
	t_matrix	*final;

	trans = translate_matrix(
			sphere->sphere.center.x,
			sphere->sphere.center.y,
			sphere->sphere.center.z);
	if (!trans)
		return (error(ERR_SPH_TRL));
	scale = scale_matrix(
			sphere->sphere.diameter,
			sphere->sphere.diameter,
			sphere->sphere.diameter);
	if (!scale)
		return (free(trans), error(ERR_SPH_SCL));
	final = multiply_matrix(trans, scale);
	if (!final)
		return (free(trans), free(scale), \
		error(ERR_SPH_TRF));
	set_object_transformation(sphere, final);
	free(trans);
	free(scale);
	return (0);
}

static int	set_sphere_diameter(char *token, t_object *sphere)
{
	if (!ft_isfloat(token))
		return (error(ERR_SPH_DMTER_VALUE));
	sphere->sphere.diameter = ft_atof(token);
	if (sphere->sphere.diameter <= 0.0)
		return (error(ERR_SPH_DMTER_RANGE));
	return (0);
}

static int	set_sphere_center_coordinates(char *token, t_object *sphere)
{
	char	**cntr;
	double	aux[3];

	cntr = ft_split(token, ',');
	if (!cntr || ft_splitsize(cntr) != 3)
	{
		ft_free_matrix((void *)&cntr);
		return (error(ERR_SPH_CENTR_SETTN));
	}
	if (!ft_isfloat(cntr[0]) || !ft_isfloat(cntr[1]) || !ft_isfloat(cntr[2]))
	{
		ft_free_matrix((void *)&cntr);
		return (error(ERR_SPH_CENTR_VALUE));
	}
	aux[0] = ft_atof(cntr[0]);
	aux[1] = ft_atof(cntr[1]);
	aux[2] = ft_atof(cntr[2]);
	ft_free_matrix((void *)&cntr);
	sphere->sphere.center = (t_point){aux[0], aux[1], aux[2], 1};
	return (0);
}

int	parse_sphere(char **tokens, t_rt_scene *s)
{
	t_object	*sphere;
	t_list		*node;

	if (ft_splitsize(tokens) != 4)
		return (error(ERR_SPH_BAD_CONFIGS));
	sphere = create_sphere();
	if (!sphere)
		return (error(ERR_SPH_MALLOC_FAIL));
	if (set_sphere_center_coordinates(tokens[1], sphere) != 0)
		return (destroy_shape(sphere), -1);
	if (set_sphere_diameter(tokens[2], sphere) != 0)
		return (destroy_shape(sphere), -1);
	if (set_shape_color(tokens[3], sphere) != 0)
		return (destroy_shape(sphere), -1);
	if (set_sphere_transformation(sphere) != 0)
		return (destroy_shape(sphere), -1);
	node = ft_lstnew(sphere);
	if (!node)
		return (destroy_shape(sphere), error(SPH_LIST));
	ft_lstadd_front(&s->objects, node);
	return (0);
}
