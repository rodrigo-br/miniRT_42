/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:32:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 10:52:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isfloat(const char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (*str == '.')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (*str && !ft_isdigit(*str))
		return (FALSE);
	return (TRUE);
}
