/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 23:57:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Adds a new colliding item to the hashtable node curr_item
* with key and value as the parameters received.
* @param curr_item Node to add the colliding item to.
* @param key New item's key.
* @param value New item's value.
*/
static void	ft_htadd_colliding(t_htnode *curr_item, char *key, char *value)
{
	while (curr_item->next)
	{
		curr_item = curr_item->next;
		if (ft_strcmp(key, curr_item->key) == 0)
		{
			ft_memfree((void *)&curr_item->value);
			curr_item->value = ft_strdup(value);
			return ;
		}
	}
	curr_item->next = ft_htnew(key, value);
}

void	ft_htadd(t_hashtable *table, char *key, char *value)
{
	int			index;
	t_htnode	*curr_item;

	index = ft_hthasher(key);
	curr_item = table->item[index];
	if (!curr_item)
		table->item[index] = ft_htnew(key, value);
	else if (ft_strcmp(key, curr_item->key) == 0)
	{
		if (value)
		{
			ft_memfree((void *)&curr_item->value);
			curr_item->value = ft_strdup(value);
		}
	}
	else
		ft_htadd_colliding(curr_item, key, value);
}
