/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdelone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 23:57:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Deletes and frees the colliding item correspondent to the given key
* from the hashtable node.
* @param item Node to delete the colliding item from.
* @param key Key to the item to be deleted.
*/
static void	ft_htdelone_colliding(t_htnode *item, char *key)
{
	t_htnode	*previous;

	previous = NULL;
	while (item && ft_strcmp(key, item->key))
	{
		previous = item;
		item = item->next;
	}
	if (!item)
		return ;
	else if (!item->next)
	{
		previous->next = NULL;
		ft_htfree(item);
	}
	else
	{
		previous->next = item->next;
		item->next = NULL;
		ft_htfree(item);
	}
}

void	ft_htdelone(t_hashtable *table, char *key)
{
	int			index;
	t_htnode	*item;

	index = ft_hthasher(key);
	item = table->item[index];
	if (item)
	{
		if (ft_strcmp(key, item->key) == 0)
		{
			table->item[index] = item->next;
			item->next = NULL;
			ft_htfree(item);
		}
		else
			ft_htdelone_colliding(item, key);
	}
}
