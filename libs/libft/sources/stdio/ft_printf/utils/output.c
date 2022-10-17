/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:24:17 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 00:29:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_width(t_flags *flags)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (flags->width + 1));
	if (!new_str)
		return (-1);
	i = 0;
	if (!flags->minus)
		while (i < ((int)(flags->width - flags->str_len)))
			new_str[i++] = ' ';
	new_str[i] = '\0';
	ft_strlcat(new_str, flags->str, (flags->width + 1));
	i = flags->str_len;
	if (flags->minus)
	{
		while (i < (int)(flags->width))
			new_str[i++] = ' ';
		new_str[i] = '\0';
	}
	free(flags->str);
	flags->str = new_str;
	flags->str_len = flags->width;
	return (1);
}
