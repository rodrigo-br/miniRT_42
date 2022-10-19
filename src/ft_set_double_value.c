/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_double_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:03:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 11:03:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_double_value(double *variable, char *value)
{
	double	double_value;

	if (!ft_is_a_double(value))
		return (EXIT_FAILURE);
	double_value = ft_atod(value);
	*variable = double_value;
	return (EXIT_SUCCESS);
}
