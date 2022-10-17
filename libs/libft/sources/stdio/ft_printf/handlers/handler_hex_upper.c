/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:30:59 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 00:29:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_hex_upper(t_flags *flags, va_list ap)
{
	int	index;

	handle_hex(flags, ap);
	flags->specifier = HEX_UPPER;
	index = -1;
	while (flags->str[++index])
		flags->str[index] = ft_toupper(flags->str[index]);
}
