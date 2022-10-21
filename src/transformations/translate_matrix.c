/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:49:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 11:02:31 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_tuple	*create_copy_tuple(t_tuple *t)
{
	return (create_tuple(t->x, t->y, t->z, t->w));
}

t_tuple	*translate_matrix(t_tuple *point, t_tuple *translation)
{
	double	temp;
	t_tuple	*new_tuple;

	if (is_vector(point))
		return (create_copy_tuple(point));
	temp = point->w;
	new_tuple = sum_tuple(point, translation);
	new_tuple->w = temp;
	return (new_tuple);
}

t_tuple	*translate_inverse_matrix(t_tuple *point, t_tuple *translation)
{
	double	temp;
	t_tuple	*new_tuple;
	t_tuple	*inverse;

	if (is_vector(point))
		return (create_copy_tuple(point));
	temp = point->w;
	inverse = neg_tuple(translation);
	new_tuple = sum_tuple(point, inverse);
	new_tuple->w = temp;
	free(inverse);
	return (new_tuple);
}
