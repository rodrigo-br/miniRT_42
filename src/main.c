/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/03 19:43:05 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	t_rt_scene	scene;
	t_minirt	*rt;

	if (check_user_input(argc) != 0)
		return (1);
	ft_bzero(&scene, sizeof(t_rt_scene));
	if (read_rt_file(argv[1], &scene) != 0)
		return (destroy_scene(&scene), 1);
	rt = scene_to_world(&scene);
	destroy_minirt(&scene, rt);
	setup_visual_environment(rt);
	return (0);
}
