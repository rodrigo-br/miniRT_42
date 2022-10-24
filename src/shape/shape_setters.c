/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:19:55 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 22:24:03 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_transformation(t_object *object, t_matrix *transformation)
{
	free(object->transformation);
	free(object->inverse_transformation);
	object->transformation = transformation;
	object->inverse_transformation = inverse_matrix(transformation);
}
