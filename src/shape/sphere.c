/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:18:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 22:20:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_sphere(void)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	object->type = ID_SPHERE;
	object->sphere.diameter = 1.0;
	object->sphere.center = (t_point){0, 0, 0, 1};
	object->transformation = create_identity_matrix();
	object->inverse_transformation = create_identity_matrix();
	return (object);
}
