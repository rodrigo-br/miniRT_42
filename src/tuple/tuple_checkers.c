/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:48:10 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/18 13:51:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	is_point(t_tuple *t)
{
	return (t->w == POINT_W);
}

t_bool	is_vector(t_tuple *t)
{
	return (t->w == VECTOR_W);
}

t_bool	is_tuple(t_tuple *t)
{
	return (!is_vector(t) && !is_point(t));
}

t_bool	is_equal_double(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

t_bool	is_equal_tuple(t_tuple *a, t_tuple *b)
{
	return (
		is_equal_double(a->x, b->x) && \
		is_equal_double(a->y, b->y) && \
		is_equal_double(a->z, b->z) && \
		is_equal_double(a->w, b->w)
	);
}
