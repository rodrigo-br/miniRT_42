/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:04:32 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 01:08:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_shape(void)
{
	t_object	*object;

	object = (t_object *)malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->orientation = NULL;
	object->transformation = create_identity_matrix();
	object->inverse_transformation = create_identity_matrix();
	object->transposed_inverse = create_identity_matrix();
	object->material = create_material();
	return (object);
}
