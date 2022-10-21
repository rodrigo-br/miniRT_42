/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:29:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/20 21:26:46 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	parse_line(char **line_splited, t_scene *scene)
{
	int	errors;

	errors = 0;
	if (line_splited[0][0] == LIGHT && !scene->light)
		errors = check_light(line_splited, &scene->light);
	else if (line_splited[0][0] == AMBIENT && !scene->ambience)
		errors = check_ambient(line_splited, &scene->ambience);
	else if (line_splited[0][0] == CAMERA && !scene->camera)
		errors = check_camera(line_splited, &scene->camera);
	else if (!ft_strcmp(line_splited[0], SPHERE))
		errors = check_sphere(line_splited, &scene->objects);
	else if (!ft_strcmp(line_splited[0], CYLINDER))
		errors = check_cylinder(line_splited, &scene->objects);
	else if (!ft_strcmp(line_splited[0], PLANE))
		errors = check_plane(line_splited, &scene->objects);
	else if (line_splited[0][0] != '#')
		errors = 1;
	if (!errors)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	parser_1(int fd, t_scene *scene)
{
	char		*line;
	char		**line_splited;
	int			errors;

	errors = 0;
	line = ft_gnl(fd, FALSE);
	while (line)
	{
		line = ft_strtrim_free(line, " \f\n\r\t\v");
		ft_str_swap_set_chr(line, "\f\r\t\v", ' ');
		line_splited = ft_split(line, ' ');
		free(line);
		if (line_splited)
		{
			if (parse_line(line_splited, scene))
				errors++;
			ft_free_matrix((void *)&line_splited);
		}
		line = ft_gnl(fd, FALSE);
	}
	if (errors)
		return (free_scene(scene), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
