/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_a_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 13:28:37 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_is_a_double(char *string)
{
	int		i;
	t_bool	already_pointed;

	if (!string)
		return (0);
	i = 0;
	already_pointed = FALSE;
	while (string[i])
	{
		if (ft_isdigit(string[i]))
			i++;
		else if (string[i] == '.' && !already_pointed)
		{
			already_pointed = TRUE;
			i++;
		}
		else if (i == 0 && string[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}
