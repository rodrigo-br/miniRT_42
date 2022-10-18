/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:29:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/17 22:00:15 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	parser_1(int fd)
{
	char		*line;
	char		**line_splited;
	short int	liamca;

	(void)fd;
	liamca = 0;
	int _fd = open("../rt_files/many_obj.rt", O_RDONLY);
	while (1)
	{
		line = ft_gnl(_fd, FALSE);
		if (!line)
			break ;
		line = ft_strtrim_free(line, " ");
		line_splited = ft_split(line, ' ');
		free(line);
		if (line_splited)
		{
			if (line_splited[0][0] == LIGHT)
				liamca += 1;
			else if (line_splited[0][0] == AMBIENT)
				liamca += 100;
			else if (line_splited[0][0] == CAMERA)
				liamca += 10000;
			ft_free_matrix((void *)&line_splited);
		}
	}
	if (liamca != 10101)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
