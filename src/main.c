/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/24 20:35:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	sub_main(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;

	if (errors(argc, argv, &fd))
		return (EXIT_FAILURE);
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (parser_1(fd, scene))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_material	*material;
	t_lightattr	args;
	t_rgb		*result;

	material = create_material();
	args.light_point = create_light_point(create_point(0, 0, -10), create_color(1, 1, 1));
	args.position = create_point(0, 0, 0);
	args.camera = create_vector(0, 0, -1);
	args.normal = create_vector(0, 0, -1);
	result = lighting(&args, material);
	destroy_material(material);
	destroy_light_point(args.light_point);
	free(result);
	if (sub_main(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
