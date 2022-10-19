/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:50:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 11:09:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_sphere(char **line_splited)
{
	t_object	object;
	int			errors;

	object.type = ID_SPHERE;
	if (!line_splited || !line_splited[0] || !line_splited[1]
		|| !line_splited[2] || !line_splited[3] || line_splited[4])
		return (EXIT_FAILURE);
	errors = set_object_coordinates(&object, line_splited[1]);
	errors += set_double_value(&object.sphere, line_splited[2]);
	errors += set_object_rgb(&object, line_splited[3]);
	if (errors)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
