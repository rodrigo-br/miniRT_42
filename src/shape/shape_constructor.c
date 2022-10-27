/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:04:32 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 19:04:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_shape(void)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->transformation = create_identity_matrix();
	object->inverse_transformation = create_identity_matrix();
	object->material = create_material();
	return (object);
}
