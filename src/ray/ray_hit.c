/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:17:47 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/23 19:20:28 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intersect	*hit(t_intersect *intersect)
{
	t_intersect	*_hit;

	_hit = NULL;
	while (intersect)
	{
		if ((!_hit || _hit->time > intersect->time) && intersect->time > 0)
			_hit = intersect;
		intersect = intersect->next;
	}
	return (_hit);
}
