/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:00:22 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 13:06:05 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_rgb	*sum_lighting(t_rgb *ambient, t_rgb *diffuse, t_rgb *specular)
{
	t_rgb	*aux;
	t_rgb	*final_color;

	aux = sum_color(ambient, diffuse);
	final_color = sum_color(aux, specular);
	free(aux);
	free(ambient);
	free(diffuse);
	free(specular);
	return (final_color);
}

static t_rgb	*get_specular(
	t_lightattr *args, t_vector *lightv, double light_dot)
{
	t_tuple		*auxtup;
	t_vector	*reflectv;
	t_rgb		*auxrgb;
	t_rgb		*specular;
	double		reflect_dot_eye;

	if (light_dot < 0)
		return (create_color(0, 0, 0));
	auxtup = neg_tuple(lightv);
	reflectv = reflect(auxtup, args->normal);
	free(auxtup);
	reflect_dot_eye = dot_product(reflectv, args->camera);
	if (reflect_dot_eye < 0)
		return (free(reflectv), create_color(0, 0, 0));
	auxrgb = scalar_multiply_color(
			args->light_point->intensity, args->material->specular);
	specular = scalar_multiply_color(
			auxrgb, pow(reflect_dot_eye, args->material->shininess));
	free(auxrgb);
	free(reflectv);
	return (specular);
}

static t_rgb	*get_diffuse(
	t_rgb *eff, double light_dot, double material_diffuse)
{
	t_rgb	*aux;
	t_rgb	*diffuse;

	if (light_dot < 0)
		return (create_color(0, 0, 0));
	aux = scalar_multiply_color(eff, material_diffuse);
	diffuse = scalar_multiply_color(aux, light_dot);
	free(aux);
	return (diffuse);
}

static t_rgb	*get_lighting(
	t_lightattr *args, t_rgb *eff, t_vector *lightv)
{
	t_rgb	*ambient;
	t_rgb	*diffuse;
	t_rgb	*specular;
	double	light_dot;

	light_dot = dot_product(lightv, args->normal);
	ambient = scalar_multiply_color(eff, args->material->ambient);
	diffuse = get_diffuse(eff, light_dot, args->material->diffuse);
	specular = get_specular(args, lightv, light_dot);
	free(eff);
	free(lightv);
	return (sum_lighting(ambient, diffuse, specular));
}

t_rgb	*lighting(t_lightattr *args)
{
	t_vector	*aux;
	t_vector	*light_vector;
	t_rgb		*eff;
	t_rgb		*case_in_shadow;
	t_rgb		*color;

	if (args->material->pattern)
		color = pattern_at(args->material->pattern, args->position);
	else
		color = args->material->color;
	eff = multiply_color(color, args->light_point->intensity);
	if (args->in_shadow)
	{
		case_in_shadow = scalar_multiply_color(eff, args->material->ambient);
		free(eff);
		return (case_in_shadow);
	}
	aux = sub_tuple(args->light_point->position, args->position);
	light_vector = normalize(aux);
	free(aux);
	return (get_lighting(args, eff, light_vector));
}
