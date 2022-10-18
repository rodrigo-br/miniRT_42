/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap_set_chr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:29:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 16:41:30 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	ft_str_swap_set_chr(char *str, char *old, char new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(old, str[i]))
			str[i] = new;
		i++;
	}
}
