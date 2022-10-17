/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:27:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:28:08 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_precision(t_flags *flags)
{
	int		i;
	int		str_len;
	char	*new_str;

	if (flags->precision == 0)
		return (handle_zero(flags));
	str_len = ft_strlen(flags->str);
	if (str_len >= flags->precision)
		return (str_len);
	new_str = (char *)malloc(sizeof(char) * (flags->precision + 1));
	if (!new_str)
		return (-1);
	i = 0;
	new_str[flags->precision] = '\0';
	while (i < (flags->precision - str_len))
		new_str[i++] = '0';
	new_str[i] = '\0';
	ft_strlcat(new_str, flags->str, (flags->precision + 1));
	free(flags->str);
	flags->str = new_str;
	flags->str_len = flags->precision;
	return (flags->precision);
}
