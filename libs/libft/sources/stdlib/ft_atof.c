/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:32:25 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 10:52:42 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
