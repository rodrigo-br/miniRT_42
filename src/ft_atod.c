/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:22:14 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 10:38:46 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	count_n(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
			{
				count++;
				i++;
			}
			break ;
		}
		i++;
	}
	return (count);
}

double	ft_atod(char *s)
{
	double	integer_part;
	double	decimal_fraction;
	int	len;
	char	**splited;

	decimal_fraction = 0;
	len = 0;
	splited = ft_split(s, '.');
	if (splited[1])
		len = count_n(splited[1]);
	integer_part = (double)ft_atoi(splited[0]);
	if (len)
	{
		decimal_fraction = (double)ft_atoi(splited[1]);
		while (len--)
			decimal_fraction /= 10;
	}
	ft_free_matrix((void *)&splited);
	return (integer_part + decimal_fraction);
}
