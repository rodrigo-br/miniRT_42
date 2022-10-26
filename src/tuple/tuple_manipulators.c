/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_manipulators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:40:52 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 09:55:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	dot_product(t_tuple *a, t_tuple *b)
{
	return (
		(a->x * b->x) + \
		(a->y * b->y) + \
		(a->z * b->z) + \
		(a->w * b->w)
	);
}

double	magnitude(t_tuple *t)
{
	return (sqrt(dot_product(t, t)));
}

t_tuple	*normalize(t_tuple *t)
{
	const double	_magnitude = magnitude(t);

	return (create_tuple(
			(t->x / _magnitude),
			(t->y / _magnitude),
			(t->z / _magnitude),
			(t->w / _magnitude))
	);
}

t_tuple	*cross_product(t_tuple *a, t_tuple *b)
{
	return (create_vector(
			((a->y * b->z) - (a->z * b->y)),
			((a->z * b->x) - (a->x * b->z)),
			((a->x * b->y) - (a->y * b->x)))
	);
}
