/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 23:57:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_htsearch(t_hashtable *table, char *key)
{
	int			index;
	t_htnode	*curr_item;

	index = ft_hthasher(key);
	curr_item = table->item[index];
	while (curr_item)
	{
		if (ft_strcmp(key, curr_item->key) == 0)
			return (curr_item->value);
		curr_item = curr_item->next;
	}
	return (NULL);
}
