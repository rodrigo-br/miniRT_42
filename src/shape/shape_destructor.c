/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:22:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 16:04:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_shape(void *object)
{
	t_object	*obj;

	obj = (t_object *)object;
	free(obj->transformation);
	free(obj->inverse_transformation);
	destroy_material(obj->material);
	if (obj->saved_ray)
		destroy_ray(obj->saved_ray);
	free(obj);
}
