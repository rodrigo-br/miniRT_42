/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/02 17:37:23 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_scene(t_rt_scene *s)
{
	t_list		*aux;
	t_object	*obj;

	printf("=== Ambient ===\n");
	printf("	- Ratio: %f\n", s->ambient->ratio);
	printf("	- Color: %d, %d, %d\n",
		(int)(s->ambient->color->red * 255),
		(int)(s->ambient->color->green * 255),
		(int)(s->ambient->color->blue * 255));
	printf("\n");
	printf("=== Camera ===\n");
	printf("	- View point: %f, %f, %f\n", s->camera->view_point->x, s->camera->view_point->y, s->camera->view_point->z);
	printf("	- Orientation: %f, %f, %f\n", s->camera->orientation->x, s->camera->orientation->y, s->camera->orientation->z);
	printf("	- Field of view: %d\n", s->camera->fov);
	printf("\n");
	printf("=== Light ===\n");
	printf("	- Coordinates: %f, %f, %f\n", s->light->x, s->light->y, s->light->z);
	printf("	- Brightness: %f\n", s->light->brightness);
	printf("	- Color: %d, %d, %d\n", s->light->red, s->light->green, s->light->blue);
	printf("\n");
	printf("=== Objects ===\n");
	printf(" - Total: %d\n", ft_lstsize(s->objects));
	aux = s->objects;
	while (aux)
	{
		obj = (t_object *)aux->content;
		if (obj->type == ID_SPHERE)
		{
			printf("	- Type: Sphere\n");
			printf("	- Center: %f, %f, %f\n", obj->sphere.center.x, obj->sphere.center.y, obj->sphere.center.z);
			printf("	- Diameter: %f\n", obj->sphere.diameter * 2);
		}
		else if (obj->type == ID_PLANE)
		{
			printf("	- Type: Plane\n");
			printf("	- Position: %f, %f, %f\n", obj->plane.position.x, obj->plane.position.y, obj->plane.position.z);
			printf("	- Orientation: %f, %f, %f\n", obj->orientation->x, obj->orientation->y, obj->orientation->z);
		}
		else if (obj->type == ID_CYLINDER)
		{
			printf("	- Type: Cylinder\n");
			printf("	- Position: %f, %f, %f\n", obj->cylinder.position.x, obj->cylinder.position.y, obj->cylinder.position.z);
			printf("	- Orientation: %f, %f, %f\n", obj->orientation->x, obj->orientation->y, obj->orientation->z);
			printf("	- Diameter: %f\n", obj->cylinder.diameter * 2);
			printf("	- Height: %f\n", obj->cylinder.max * 2);
		}
		printf("	- Ambient: %f\n", obj->material->ambient->red);
		printf("	- Specular: %f\n", obj->material->specular);
		printf("	- Diffuse: %f\n", obj->material->diffuse);
		printf("	- Shininess: %f\n", obj->material->shininess);
		printf("	- Color: %d, %d, %d\n",
			(int)(obj->material->color->red * 255),
			(int)(obj->material->color->green * 255),
			(int)(obj->material->color->blue * 255));
		printf("\n");
		aux = aux->next;
	}
	printf("\n");
}

void	destroy_scene(t_rt_scene *scene)
{
	ft_memfree((void *)&scene->camera->orientation);
	ft_memfree((void *)&scene->camera->view_point);
	ft_memfree((void *)&scene->ambient->color);
	ft_memfree((void *)&scene->camera);
	ft_memfree((void *)&scene->ambient);
	ft_memfree((void *)&scene->light);
}

int	end_program(t_minirt *rt)
{
	mlx_destroy_window(rt->canvas->mlx, rt->window);
	destroy_canvas(rt->canvas);
	destroy_world(rt->world);
	destroy_camera(rt->camera);
	ft_memfree((void *)&rt);
	exit(0);
	return (0);
}

int	escape_key(int keysym, t_minirt *rt)
{
	if (keysym == 65307)
		end_program(rt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt_scene	scene;
	t_minirt	*rt;

	if (argc != 2)
	{
		if (argc > 2)
			error("miniRT: too many arguments");
		if (argc < 2)
			error("miniRT: too few arguments");
		error("usage: ./miniRT <map file>.rt");
		return (1);
	}
	ft_bzero(&scene, sizeof(t_rt_scene));
	if (read_rt_file(argv[1], &scene) != 0)
		return (destroy_scene(&scene), 1);
	rt = scene_to_world(&scene);
	print_scene(&scene);
	destroy_scene(&scene);
	mlx_put_image_to_window(
		rt->canvas->mlx, rt->window, rt->canvas->image, 0, 0);
	mlx_hook(rt->window, 17, (1L << 2), end_program, rt);
	mlx_hook(rt->window, 2, (1L << 0), escape_key, rt);
	mlx_loop(rt->canvas->mlx);
	return (0);
}
