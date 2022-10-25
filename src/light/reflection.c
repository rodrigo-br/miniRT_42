/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:34:23 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:21:15 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	*reflect(t_vector *in, t_vector *normal)
{
	t_vector	*scalar;
	t_vector	*reflection;

	scalar = scalar_multiply_tuple(normal, (dot_product(in, normal) * 2));
	reflection = sub_tuple(in, scalar);
	free(scalar);
	return (reflection);
}

t_light_pnt	*create_light_point(t_point *position, t_color *intensity)
{
	t_light_pnt	*light_point;

	light_point = (t_light_pnt *)malloc(sizeof(t_light_pnt));
	if (!light_point)
		return (NULL);
	light_point->position = position;
	light_point->intensity = intensity;
	return (light_point);
}

void	destroy_light_point(t_light_pnt *light_point)
{
	free(light_point->position);
	free(light_point->intensity);
	free(light_point);
}

/*
function lighting(material, light, point, eyev, normalv)

	effective_color ← material.color * light.intensity
	lightv ← normalize(light.position - point)
	ambient ← effective_color * material.ambient
	light_dot_normal ← dot(lightv, normalv)

	if light_dot_normal < 0
		diffuse ← black
		specular ← black
	else
		diffuse ← effective_color * material.diffuse * light_dot_normal
		reflectv ← reflect(-lightv, normalv)
		reflect_dot_eye ← dot(reflectv, eyev)

		if reflect_dot_eye <= 0
			specular ← black
		else
			factor ← pow(reflect_dot_eye, material.shininess)
			specular ← light.intensity * material.specular * factor
		end if
	end if

	return ambient + diffuse + specular
end function
*/
t_color	*lighting(t_lightattr *args, t_material *material)
{
	t_color		*eff_color; // ambient
	t_vector	*path_to_light; // specular
	t_vector	*light_vector; // specular
	t_vector	*reflect_vector; // specular
	double		light_dot_normal; // diffuse, specular
	double		reflect_dot_eye; // specular
	t_color		*ambient;
	t_color		*diffuse;
	t_color		*specular;
	t_color		*auxrgb;
	t_tuple		*auxtup;
	t_color		*final_color;

	eff_color = multiply_color(material->color, args->light_point->intensity);
	light_vector = sub_tuple(args->light_point->position, args->position);
	path_to_light = normalize(light_vector);
	ambient = scalar_multiply_color(eff_color, material->ambient);
	light_dot_normal = dot_product(path_to_light, args->normal);
	if (light_dot_normal < 0)
	{
		diffuse = create_color(0, 0, 0);
		specular = create_color(0, 0, 0);
	}
	else
	{
		auxrgb = scalar_multiply_color(eff_color, material->diffuse);
		diffuse = scalar_multiply_color(auxrgb, light_dot_normal);
		free(auxrgb);
		auxtup = neg_tuple(path_to_light);
		reflect_vector = reflect(auxtup, args->normal);
		free(auxtup);
		reflect_dot_eye = dot_product(reflect_vector, args->camera);
		if (reflect_dot_eye < 0)
			specular = create_color(0, 0, 0);
		else
		{
			auxrgb = scalar_multiply_color(args->light_point->intensity, material->specular);
			specular = scalar_multiply_color(auxrgb, pow(reflect_dot_eye, material->shininess));
		}
	}
	auxrgb = sum_color(ambient, diffuse);
	final_color = sum_color(auxrgb, specular);
	free(auxrgb);
	return (final_color);
}
