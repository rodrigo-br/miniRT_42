/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:36:04 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_htnode	*ft_htnew(char *key, char *value)
{
	t_htnode	*item;

	item = (t_htnode *)ft_calloc(1, sizeof(t_htnode));
	if (key)
		item->key = ft_strdup(key);
	if (value)
		item->value = ft_strdup(value);
	return (item);
}
