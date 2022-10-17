/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:53:02 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:24:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_binary(t_flags *flags, va_list ap)
{
	size_t	number;

	flags->specifier = BINARY;
	if (flags->has_precision)
		flags->zero = 0;
	number = va_arg(ap, size_t);
	if (number == 0)
		flags->hash = 0;
	flags->str = ft_itoa_base(number, BINARY_BASE);
	flags->str_len = ft_strlen(flags->str);
	handle_flags_integer(flags);
}
