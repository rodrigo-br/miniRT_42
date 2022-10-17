/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:52:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:37:01 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*char_to_str(int c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	return (str);
}

static int	fill_char_width(t_flags *flags)
{
	char	*new_str;
	size_t	i;

	new_str = (char *)malloc(sizeof(char) * (flags->width + 1));
	if (!new_str)
		return (-1);
	i = 0;
	if (!flags->minus)
		while (i < (flags->width - 1))
			new_str[i++] = ' ';
	new_str[i] = flags->str[0];
	if (flags->minus)
	{
		while (++i < flags->width)
			new_str[i] = ' ';
		new_str[i] = '\0';
	}
	free(flags->str);
	flags->str = new_str;
	flags->str_len = flags->width;
	return (1);
}

static int	handle_char_flags(t_flags *flags)
{
	flags->str_len = 1;
	if (flags->width > 1)
		if (fill_char_width(flags) < 0)
			return (-1);
	return (flags->str_len);
}

void	handle_char(t_flags *flags, va_list ap)
{
	flags->specifier = CHAR;
	flags->str = char_to_str(va_arg(ap, int));
	if (handle_char_flags(flags) < 0)
		flags->has_error = TRUE;
}
