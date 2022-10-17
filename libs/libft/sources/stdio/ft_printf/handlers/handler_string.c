/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:36:21 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:38:21 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_string_flags(t_flags *flags)
{
	if (flags->str_len < flags->width)
		if (fill_width(flags) < 0)
			return (-1);
	return (flags->str_len);
}

void	handle_string(t_flags *flags, va_list ap)
{
	char	*str_param;

	flags->specifier = STRING;
	str_param = va_arg(ap, char *);
	if (!str_param)
		str_param = "(null)";
	if (flags->has_precision)
		flags->str = ft_substr(str_param, 0, flags->precision);
	else
		flags->str = ft_strdup(str_param);
	flags->str_len = ft_strlen(flags->str);
	handle_string_flags(flags);
}
