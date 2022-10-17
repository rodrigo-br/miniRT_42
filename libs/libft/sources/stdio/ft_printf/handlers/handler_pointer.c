/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:57:31 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:38:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_pointer_address(size_t number)
{
	char	*hex;
	char	*address;

	if (number == 0)
		address = ft_strdup("(nil)");
	else
	{
		hex = ft_itoa_base(number, HEX_BASE);
		address = ft_strjoin("0x", hex);
		free(hex);
	}
	return (address);
}

static int	handle_pointer_flags(t_flags *flags)
{
	if (flags->str_len < flags->width)
		if (fill_width(flags) < 0)
			return (-1);
	return (flags->str_len);
}

void	handle_pointer(t_flags *flags, va_list ap)
{
	flags->specifier = POINTER;
	flags->str = get_pointer_address(va_arg(ap, size_t));
	flags->str_len = ft_strlen(flags->str);
	if (handle_pointer_flags(flags) < 0)
		flags->has_error = TRUE;
}
