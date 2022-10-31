/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:29:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/31 20:02:04 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	cavalinho_cai_matando_geral(t_world *world, t_cam *camera, t_scene *scene)
{
	t_list	*temp;

	destroy_world(world);
	destroy_camera(camera);
	free(scene->light->rgb);
	free(scene->light);
	free(scene->camera);
	free(scene->ambience->rgb);
	free(scene->ambience);
	while (scene->objects)
	{
		temp = scene->objects->next;
		free(scene->objects);
		scene->objects = temp;
	}
	free(scene);
}

int	end_program(t_canvas *mlx)
{
	destroy_canvas(mlx);
	exit(0);
	return (0);
}

void	generate_objects(t_world *world, t_scene *scene)
{
	t_list		*lst_aux;
	t_object	*obj_aux;

	lst_aux = scene->objects;
	while (lst_aux)
	{
		obj_aux = (t_object *)lst_aux->content;
		ft_lstadd_front(&world->objects, ft_lstnew(obj_aux));
		lst_aux = lst_aux->next;
	}
}

void	generate_world(t_scene *scene)
{
	t_world		*world;
	t_light_pnt	*lp;
	t_cam		*camera;
	t_canvas	*canvas;
	t_point		*f;

	lp = create_light_point(
			create_point(scene->light->x, scene->light->y, scene->light->z), \
		scalar_multiply_color(scene->light->rgb, scene->light->brightness));
	world = create_world();
	world->light_point = ft_lstnew(lp);
	generate_objects(world, scene);
	camera = create_camera(1000, 500, radians(scene->camera->fov));
	f = normalize(&(t_point){scene->camera->x_3d, scene->camera->y_3d, scene->camera->z_3d, 1});
	set_camera_transformation(camera, view_transform(
		&(t_point){scene->camera->view_x, scene->camera->view_y, scene->camera->view_z, 1},
		f,
		&(t_vector){0, 1, 0, 0}
	));
	canvas = render(camera, world);
	canvas->win = mlx_new_window(
		canvas->mlx, camera->h_size, camera->v_size, "cavalinho assassino");
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->image, 0, 0);
	cavalinho_cai_matando_geral(world, camera, scene);
	mlx_hook(canvas->win, 17, (1L << 2), end_program, canvas);
	mlx_loop(canvas->mlx);
}

int	sub_main(int argc, char **argv)
{
	t_scene	*scene;
	int		fd;

	if (errors(argc, argv, &fd))
		return (EXIT_FAILURE);
	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (parser_1(fd, scene))
		return (EXIT_FAILURE);
	generate_world(scene);
	return (EXIT_SUCCESS);
}

int	parse_line(char **line_splited, t_scene *scene)
{
	int	errors;

	errors = 0;
	if (!ft_strcmp(line_splited[0], LIGHT) && !scene->light)
		errors = check_light(line_splited, &scene->light);
	else if (!ft_strcmp(line_splited[0], AMBIENT) && !scene->ambience)
		errors = check_ambient(line_splited, &scene->ambience);
	else if (!ft_strcmp(line_splited[0], CAMERA) && !scene->camera)
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
	if (errors || !scene->camera || !scene->ambience || !scene->light)
		return (free_scene(scene), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
