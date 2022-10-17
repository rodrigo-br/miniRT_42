/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hthasher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:36:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hthasher(char *key)
{
	t_uint	tmp;
	t_uint	hash;

	hash = 0;
	while (*key)
	{
		hash = (hash << HASH_LEFT_OFFSET) + *key;
		tmp = hash & HASH_LIMITER;
		if (tmp)
		{
			hash ^= tmp >> HASH_RIGHT_OFFSET;
			hash ^= tmp;
		}
		key++;
	}
	return ((int)(hash % HASH_TABLE_SIZE));
}
