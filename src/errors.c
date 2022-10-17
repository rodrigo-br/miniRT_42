/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:44:10 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/17 20:39:51 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	errors(int argc, char **argv)
{
	int		fd;
	char	*file;

	file = argv[1];
	if (argc != 2)
	{
		ft_putstr_fd("wrong number of args\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(file + (ft_strlen(file) - 3), ".rt")
		|| ft_strlen(file) <= 3)
	{
		ft_putstr_fd("wronge file extension\n", 2);
		return (EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
