/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_destructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:22:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/07 01:09:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_shape(void *object)
{
	t_object	*obj;

	obj = (t_object *)object;
	destroy_material(obj->material);
	ft_memfree((void *)&obj->orientation);
	ft_memfree((void *)&obj->transformation);
	ft_memfree((void *)&obj->inverse_transformation);
	ft_memfree((void *)&obj->transposed_inverse);
	ft_memfree((void *)&obj);
}
