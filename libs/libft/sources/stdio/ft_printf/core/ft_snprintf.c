/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:46:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 00:34:27 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_vsnprintf(char *buf, size_t n, const char *format, va_list ap)
{
	t_output	*output;
	int			size;

	output = generate_output((char *)format, ap);
	if (!output)
		return (-1);
	if (output->size < 0)
	{
		free(output->str);
		free(output);
		return (-1);
	}
	if (output->size > (int)n)
		size = n;
	else
		size = output->size;
	ft_memmove(buf, output->str, size);
	buf[size] = '\0';
	free(output);
	return (size);
}

int	ft_snprintf(char *buf, size_t n, const char *format, ...)
{
	int		size;
	va_list	ap;

	va_start(ap, format);
	size = ft_vsnprintf(buf, n, format, ap);
	va_end(ap);
	return (size);
}
