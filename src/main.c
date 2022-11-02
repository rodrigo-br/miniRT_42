/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/01 21:30:58 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_scene(t_rt_scene *s)
{
	printf("=== Ambient ===\n");
	printf("	- Ratio: %f\n", s->ambient->ratio);
	printf("	- Color: %d, %d, %d\n", s->ambient->red, s->ambient->green, s->ambient->blue);
	printf("\n");
	printf("=== Camera ===\n");
	printf("	- View point: %f, %f, %f\n", s->camera->view_x, s->camera->view_y, s->camera->view_z);
	printf("	- Orientation: %f, %f, %f\n", s->camera->x_3d, s->camera->y_3d, s->camera->z_3d);
	printf("	- Field of view: %d\n", s->camera->fov);
	printf("\n");
	printf("=== Light ===\n");
	printf("	- Coordinates: %f, %f, %f\n", s->light->x, s->light->y, s->light->z);
	printf("	- Brightness: %f\n", s->light->brightness);
	printf("	- Color: %d, %d, %d\n", s->light->red, s->light->green, s->light->blue);
	printf("\n");
}

void	destroy_scene(t_rt_scene *scene)
{
	free(scene->ambient);
	free(scene->camera);
	free(scene->light);
	ft_lstclear(&scene->objects, destroy_shape);
}

int	scene_to_world(t_world *w, t_rt_scene *s)
{
	(void)w;
	if (!s->ambient)
		return (ft_putendl_fd("Undefined ambient.", STDERR), -1);
	if (!s->camera)
		return (ft_putendl_fd("Undefined camera.", STDERR), -1);
	if (!s->light)
		return (ft_putendl_fd("Undefined light.", STDERR), -1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt_scene	scene;
	t_world		*world;

	if (argc != 2)
	{
		if (argc > 2)
			ft_putendl_fd("miniRT: too many arguments", STDERR);
		if (argc < 2)
			ft_putendl_fd("miniRT: too few arguments", STDERR);
		ft_putendl_fd("usage: ./miniRT <map file>.rt", STDERR);
		return (1);
	}
	ft_bzero(&scene, sizeof(t_rt_scene));
	if (read_rt_file(argv[1], &scene) != 0)
		return (destroy_scene(&scene), 1);
	world = create_world();
	if (!world)
		return (destroy_scene(&scene), 1);
	if (scene_to_world(world, &scene) != 0)
		return (destroy_world(world), destroy_scene(&scene), 1);
	print_scene(&scene);
	destroy_scene(&scene);
	destroy_world(world);
	return (0);
}
