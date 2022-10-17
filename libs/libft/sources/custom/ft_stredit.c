/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stredit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:50:52 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 15:35:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stredit(char *str, const char *from, const char *to)
{
	size_t	index;
	size_t	malloc_size;
	char	*substring;
	char	*edited;

	if (!str || !from || !to)
		return (ft_memfree((void *)&str), NULL);
	substring = ft_strnstr(str, from, ft_strlen(str));
	if (!substring)
		return (str);
	malloc_size = ft_strlen(str) - ft_strlen(from) + ft_strlen(to) + 1;
	edited = (char *)malloc(sizeof(char) * malloc_size);
	if (!edited)
		return (free(str), NULL);
	ft_strlcpy(edited, str, (substring - str + 1));
	ft_strlcat(edited, to, malloc_size);
	index = substring - str + ft_strlen(from);
	ft_strlcat(edited, &str[index], malloc_size);
	return (free(str), edited);
}
