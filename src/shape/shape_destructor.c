/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:22:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 16:20:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_shape(t_object *object)
{
	free(object->transformation);
	free(object->inverse_transformation);
	destroy_material(object->material);
	free(object);
}
