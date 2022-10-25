/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:34:23 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 10:21:48 by maolivei         ###   ########.fr       */
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
