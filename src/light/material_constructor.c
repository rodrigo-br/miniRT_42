/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_constructor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:05:27 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:33:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_material	*create_material(void)
{
	t_material	*material;

	material = (t_material *)malloc(sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = create_color(1, 1, 1);
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	return (material);
}
