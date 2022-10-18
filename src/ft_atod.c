/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:22:14 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 09:32:27 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	ft_atod(char *s)
{
	double	integer_part;
	double	decimal_fraction;
	size_t	len;
	char	**splited;

	splited = ft_split(s, '.');
	len = ft_strlen(splited[1]);
	integer_part = (double)ft_atoi(splited[0]);
	decimal_fraction = (double)ft_atoi(splited[1]);
	while (len--)
		decimal_fraction /= 10;
	return (integer_part + decimal_fraction);
}
