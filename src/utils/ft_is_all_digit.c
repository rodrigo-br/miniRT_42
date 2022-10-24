/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:15:36 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 12:21:46 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_is_all_digit(char *string)
{
	int		i;

	i = -1;
	if (!string)
		return (0);
	while (string[++i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
	}
	return (1);
}
