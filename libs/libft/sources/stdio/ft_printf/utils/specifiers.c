/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:26:54 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 00:29:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_str(t_specifier specifier, t_flags *flags, va_list ap)
{
	if (specifier == INTEGER || specifier == DECIMAL)
		handle_integer(specifier, flags, ap);
	else if (specifier == BINARY)
		handle_binary(flags, ap);
	else if (specifier == CHAR)
		handle_char(flags, ap);
	else if (specifier == STRING)
		handle_string(flags, ap);
	else if (specifier == POINTER)
		handle_pointer(flags, ap);
	else if (specifier == UNSIGNED)
		handle_unsigned(flags, ap);
	else if (specifier == HEX_LOWER)
		handle_hex(flags, ap);
	else if (specifier == HEX_UPPER)
		handle_hex_upper(flags, ap);
	else if (specifier == PERCENTAGE)
		handle_percentage(flags);
	else
		flags->str = NULL;
}
