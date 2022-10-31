/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:50:15 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/31 18:42:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*set_sphere(char **coordinates, char **rgb, char *s)
{
	t_object	*object;

	object = create_sphere();
	if (!object)
	{
		ft_free_matrix((void *)&coordinates);
		ft_free_matrix((void *)&rgb);
		return (NULL);
	}
	object->sphere.center.x = ft_atod(coordinates[0]);
	object->sphere.center.y = ft_atod(coordinates[1]);
	object->sphere.center.z = ft_atod(coordinates[2]);
	set_color(object->material->color, (ft_atod(rgb[0]) / 255), \
							(ft_atod(rgb[1]) / 255), (ft_atod(rgb[2]) / 255));
	object->sphere.diameter = ft_atod(s);
	set_object_transformation(object, scale_matrix(
		object->sphere.diameter, object->sphere.diameter, object->sphere.diameter));
	ft_free_matrix((void *)&coordinates);
	ft_free_matrix((void *)&rgb);
	return (object);
}

int	check_sphere(char **line_splited, t_list **object)
{
	char		**rgb;
	char		**coordinates;
	t_object	*new_obj;

	if (ft_get_matrix_len(line_splited) != 4)
		return (EXIT_FAILURE);
	coordinates = ft_split(line_splited[1], ',');
	if (!coordinates || check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	if (!ft_is_a_double(line_splited[2]))
	{
		ft_free_matrix((void *)&coordinates);
		return (EXIT_FAILURE);
	}
	rgb = check_rgb(line_splited[3]);
	if (!rgb)
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	new_obj = set_sphere(coordinates, rgb, line_splited[2]);
	if (!(new_obj))
		return (EXIT_FAILURE);
	ft_lstadd_back(object, ft_lstnew(new_obj));
	return (EXIT_SUCCESS);
}
