/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:08:37 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 20:00:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	ft_atof(const char *nptr)
{
	int		is_neg;
	double	result;
	double	power;

	while (ft_isspace(*nptr))
		nptr++;
	is_neg = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			is_neg = -1;
	result = 0.0;
	while (ft_isdigit(*nptr))
		result = (result * 10.0) + (*nptr++ - '0');
	if (*nptr++ != '.')
		return (is_neg * result);
	power = 1.0;
	while (ft_isdigit(*nptr))
	{
		result = (result * 10.0) + (*nptr++ - '0');
		power *= 10.0;
	}
	return (is_neg * result / power);
}

size_t	ft_splitsize(char **split)
{
	size_t	size;

	size = 0;
	while (split[size])
		++size;
	return (size);
}

t_bool	ft_isfloat(const char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	if (!*str)
		return (FALSE);
	while (*str && ft_isdigit(*str))
		++str;
	if (*str != '.' && *str != '\0')
		return (FALSE);
	if (*str == '.')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (*str && !ft_isdigit(*str))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_isnumber(const char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	return (TRUE);
}

t_bool	ft_isinrange(double value, double min, double max)
{
	return (value >= min && value <= max);
}
