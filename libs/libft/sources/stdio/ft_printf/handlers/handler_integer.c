/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:18:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:24:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_integer(t_specifier specifier, t_flags *flags, va_list ap)
{
	flags->specifier = specifier;
	if (flags->has_precision)
		flags->zero = 0;
	flags->str = ft_itoa(va_arg(ap, int));
	flags->str_len = ft_strlen(flags->str);
	if (handle_flags_integer(flags) < 0)
		flags->has_error = TRUE;
}
