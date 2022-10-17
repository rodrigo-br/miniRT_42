/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:18:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:27:46 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_flags_unsigned(t_flags *flags)
{
	if (flags->has_precision)
		fill_precision(flags);
	if (flags->width > flags->str_len)
		if (fill_int_width(flags) < 0)
			return (-1);
	return (flags->str_len);
}

void	handle_unsigned(t_flags *flags, va_list ap)
{
	flags->specifier = UNSIGNED;
	if (flags->has_precision)
		flags->zero = 0;
	flags->str = ft_utoa(va_arg(ap, int));
	flags->str_len = ft_strlen(flags->str);
	handle_flags_unsigned(flags);
}
