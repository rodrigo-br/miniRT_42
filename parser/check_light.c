/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:08:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 09:33:12 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_coordinates(t_light *light, char *s)
{
	(void)light;
	(void)s;
	return ;
}

void	check_light(char **line_splited)
{
	t_light	light;
	set_coordinates(&light, line_splited[1]);
	return ;
}
