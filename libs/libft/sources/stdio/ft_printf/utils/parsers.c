/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:19:48 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 00:31:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_flag(char c)
{
	return (c == '0' || c == '-' || c == '#' || c == ' ' || c == '+');
}

static int	get_flags(const char *str, t_flags *flags, va_list ap)
{
	int		chars;

	(void) ap;
	if (!*str)
		return (0);
	chars = 0;
	while (is_flag(str[chars]))
	{
		if (str[chars] == '-')
			flags->minus = 1;
		else if (str[chars] == '0')
			flags->zero = 1;
		else if (str[chars] == '#')
			flags->hash = 1;
		else if (str[chars] == ' ')
			flags->space = 1;
		else if (str[chars] == '+')
			flags->plus = 1;
		chars++;
	}
	return (chars);
}

static int	get_width(const char *str, t_flags *flags, va_list ap)
{
	int	width;
	int	offset;

	if (*str == '*')
		width = va_arg(ap, int);
	else
		width = ft_atoi(str);
	if (width < 0)
	{
		width = -width;
		flags->minus = 1;
	}
	flags->width = width;
	offset = 0;
	if (*str == '*')
		return (1);
	else
		while (ft_isdigit(*str++))
			offset++;
	return (offset);
}

static int	get_precision(const char *str, t_flags *flags, va_list ap)
{
	int	offset;

	flags->has_precision = FALSE;
	offset = 0;
	if (*str++ == '.')
	{
		offset = 1;
		flags->has_precision = TRUE;
		if (*str == '*')
		{
			flags->precision = va_arg(ap, int);
			if (flags->precision < 0)
				flags->has_precision = FALSE;
		}
		else
			flags->precision = ft_atoi(str);
		if (*str == '*')
			return (2);
		else
			while (ft_isdigit(*str++))
				offset++;
	}
	return (offset);
}

t_flags	*get_data(const char *str, va_list ap)
{
	t_flags	*flags;
	int		offset;

	flags = ft_calloc(1, sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->placeholder_len = 1;
	offset = get_flags(str, flags, ap);
	offset += get_width(str + offset, flags, ap);
	offset += get_precision(str + offset, flags, ap);
	get_str(str[offset], flags, ap);
	if (!flags->str)
		return (flags);
	if (flags->specifier != 'c')
		flags->str_len = ft_strlen(flags->str);
	flags->placeholder_len += offset;
	return (flags);
}
