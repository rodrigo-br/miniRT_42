/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:18:56 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/17 16:51:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	is_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

t_bool	is_equal_tuple(t_tuple *a, t_tuple *b)
{
	return (
		is_equal(a->x, b->x) && \
		is_equal(a->y, b->y) && \
		is_equal(a->z, b->z) && \
		is_equal(a->w, b->w)
	);
}

t_tuple	*sum_tuple(t_tuple *a, t_tuple *b)
{
	return (create_tuple(
			(a->x + b->x),
			(a->y + b->y),
			(a->z + b->z),
			(a->w + b->w)));
}

t_tuple	*sub_tuple(t_tuple *a, t_tuple *b)
{
	return (create_tuple(
			(a->x - b->x),
			(a->y - b->y),
			(a->z - b->z),
			(a->w - b->w)));
}

t_tuple	*neg_tuple(t_tuple *a)
{
	return (create_tuple(
			(-a->x),
			(-a->y),
			(-a->z),
			(-a->w)));
}
