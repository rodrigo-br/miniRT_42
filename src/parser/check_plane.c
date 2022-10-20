/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:46:16 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/20 18:13:39 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	fail_mallocs(char **ori_3d, t_object *object)
{
	if (object && ori_3d)
		return (EXIT_SUCCESS);
	if (!object)
		ft_free_matrix((void *)&ori_3d);
	else if (!ori_3d)
		free(object);
	return (EXIT_FAILURE);
}

t_object	*set_plane(char **coordinates, char **rgb, char *s)
{
	t_object	*object;
	char		**ori_3d;

	ori_3d = ft_split(s, ',');
	object = (t_object *)malloc(sizeof(t_object));
	if (fail_mallocs(ori_3d, object))
	{
		ft_free_matrix((void *)&coordinates);
		ft_free_matrix((void *)&rgb);
		return (NULL);
	}
	object->type = ID_PLANE;
	object->x = ft_atod(coordinates[0]);
	object->y = ft_atod(coordinates[1]);
	object->z = ft_atod(coordinates[2]);
	object->rgb = create_color(ft_atoi(rgb[0]), \
								ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	object->plane.x_3d = ft_atod(ori_3d[0]);
	object->plane.y_3d = ft_atod(ori_3d[1]);
	object->plane.z_3d = ft_atod(ori_3d[2]);
	ft_free_matrix((void *)&ori_3d);
	return (object);
}

int	check_plane(char **line_splited, t_list **object)
{
	char		**rgb;
	char		**coordinates;
	t_object	*new_obj;

	if (ft_get_matrix_len(line_splited) != 4)
		return (EXIT_FAILURE);
	coordinates = ft_split(line_splited[1], ',');
	if (!coordinates || check_coordinates_digits(coordinates))
		return (EXIT_FAILURE);
	if (check_object_3d_orientation(line_splited[2]))
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	rgb = check_rgb(line_splited[3]);
	if (!rgb)
		return (ft_free_matrix((void *)&coordinates), EXIT_FAILURE);
	new_obj = set_plane(coordinates, rgb, line_splited[2]);
	ft_free_matrix((void *)&coordinates);
	ft_free_matrix((void *)&rgb);
	if (!(new_obj))
		return (EXIT_FAILURE);
	ft_lstadd_back(object, ft_lstnew(new_obj));
	return (EXIT_SUCCESS);
}
