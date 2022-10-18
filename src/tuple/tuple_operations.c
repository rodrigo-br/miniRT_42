/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:18:56 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/18 13:51:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*sum_tuple(t_tuple *a, t_tuple *b)
{
	return (create_tuple(
			(a->x + b->x),
			(a->y + b->y),
			(a->z + b->z),
			(a->w + b->w))
	);
}

t_tuple	*sub_tuple(t_tuple *a, t_tuple *b)
{
	return (create_tuple(
			(a->x - b->x),
			(a->y - b->y),
			(a->z - b->z),
			(a->w - b->w))
	);
}

t_tuple	*neg_tuple(t_tuple *t)
{
	return (create_tuple(
			(-t->x),
			(-t->y),
			(-t->z),
			(-t->w))
	);
}

t_tuple	*scalar_multiply(t_tuple *t, double multiplier)
{
	return (create_tuple(
			(t->x * multiplier),
			(t->y * multiplier),
			(t->z * multiplier),
			(t->w * multiplier))
	);
}

t_tuple	*scalar_divide(t_tuple *t, double divider)
{
	return (create_tuple(
			(t->x / divider),
			(t->y / divider),
			(t->z / divider),
			(t->w / divider))
	);
}
