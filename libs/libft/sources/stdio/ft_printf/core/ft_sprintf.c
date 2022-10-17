/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:06:56 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/22 16:49:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_vsprintf(char *buf, const char *format, va_list ap)
{
	t_output	*output;
	int			size;

	output = generate_output((char *)format, ap);
	if (!output)
		return (-1);
	ft_memmove(buf, output->str, output->size);
	size = output->size;
	buf[output->size] = '\0';
	free(output);
	return (size);
}

int	ft_sprintf(char *buf, const char *format, ...)
{
	int		chars_printed;
	va_list	ap;

	va_start(ap, format);
	chars_printed = ft_vsprintf(buf, format, ap);
	va_end(ap);
	return (chars_printed);
}
