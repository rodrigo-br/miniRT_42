/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:15:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us = (unsigned char *)s;
	const unsigned char	uc = (unsigned char)c;

	while (n--)
		if (*us++ == uc)
			return ((void *)(us - 1));
	return (NULL);
}
