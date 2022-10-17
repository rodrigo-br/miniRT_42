/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:42:26 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/25 22:27:07 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_zero(t_flags *flags)
{
	if (flags->str[0] == '0')
	{
		free(flags->str);
		flags->str = ft_strdup("");
		flags->str_len = 0;
	}
	return (flags->precision);
}

int	fill_int_precision(t_flags *flags)
{
	int		i;
	int		str_len;
	char	*new_str;
	int		is_neg;

	if (flags->precision == 0)
		return (handle_zero(flags));
	is_neg = flags->str[0] == '-';
	str_len = ft_strlen(flags->str);
	if (str_len >= (flags->precision + is_neg))
		return (str_len);
	new_str = (char *)malloc(sizeof(char) * (flags->precision + is_neg + 1));
	if (!new_str)
		return (-1);
	i = 0;
	if (is_neg)
		new_str[i] = '-';
	while (i < (flags->precision - str_len + is_neg))
		new_str[i++ + is_neg] = '0';
	new_str[i + is_neg] = '\0';
	ft_strlcat(new_str, (flags->str + is_neg), (flags->precision + 1 + is_neg));
	free(flags->str);
	flags->str = new_str;
	flags->str_len = (flags->precision + is_neg);
	return (flags->precision);
}

int	fill_int_width(t_flags *flags)
{
	size_t	i;
	char	*new_str;
	int		prefix;
	t_bool	has_prefix;

	if (flags->minus || !flags->zero)
		return (fill_width(flags));
	new_str = (char *)malloc(sizeof(char) * (flags->width + 1));
	if (!new_str)
		return (-1);
	has_prefix = !ft_isdigit(flags->str[0]);
	prefix = flags->str[0];
	i = 0;
	if (has_prefix)
		new_str[0] = prefix;
	while (i < (flags->width - flags->str_len))
		new_str[i++ + has_prefix] = '0';
	new_str[i + has_prefix] = '\0';
	ft_strlcat(new_str, (flags->str + has_prefix), (flags->width + 1));
	free(flags->str);
	flags->str = new_str;
	flags->str_len = flags->width;
	return (1);
}

void	prefix_positive(t_flags *flags)
{
	char	*tmp;

	tmp = flags->str;
	if (flags->plus)
		flags->str = ft_strjoin("+", tmp);
	else if (flags->space)
		flags->str = ft_strjoin(" ", tmp);
	flags->str_len++;
	free(tmp);
}

int	handle_flags_integer(t_flags *flags)
{
	if (flags->has_precision)
		if (fill_int_precision(flags) < 0)
			return (-1);
	if ((flags->plus || flags->space) && flags->str[0] != '-')
		prefix_positive(flags);
	if (flags->width > flags->str_len)
		if (fill_int_width(flags) < 0)
			return (-1);
	return (flags->str_len);
}
