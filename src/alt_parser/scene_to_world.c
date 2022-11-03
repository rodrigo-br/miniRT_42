/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_to_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:18:05 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 11:39:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	setup_camera(t_cam *camera, t_rt_camera *c)
{
	t_matrix	*transformation;
	t_vector	*up;

	up = create_vector(0, 1, 0);
	transformation = view_transform(c->view_point, c->orientation, up);
	set_camera_transformation(camera, transformation);
	free(up);
}

static void	setup_light(t_list **light, t_rt_scene *s)
{
	t_light_pnt	*lp;
	t_list		*new;
	t_rgb		*aux;

	aux = create_formatted_color(
			s->light->red,
			s->light->green,
			s->light->blue);
	lp = create_light_point(
			create_point(s->light->x, s->light->y, s->light->z),
			scalar_multiply_color(aux, s->light->brightness));
	new = ft_lstnew(lp);
	*light = new;
	free(aux);
}

static void	setup_objects(t_list **objects, t_rt_scene *s)
{
	t_object	*current_object;
	t_list		*object_list;

	object_list = s->objects;
	while (object_list)
	{
		current_object = (t_object *)object_list->content;
		set_shape_material(current_object, s);
		object_list = object_list->next;
	}
	*objects = s->objects;
}

static void	setup_world(t_world *world, t_rt_scene *s)
{
	setup_objects(&world->objects, s);
	setup_light(&world->light_point, s);
}

t_minirt	*scene_to_world(t_rt_scene *s)
{
	t_minirt	*rt;

	rt = (t_minirt *)malloc(sizeof(t_minirt));
	if (!rt)
		return (NULL);
	rt->world = create_world();
	setup_world(rt->world, s);
	rt->camera = create_camera(RT_WIDTH, RT_HEIGHT, radians(s->camera->fov));
	setup_camera(rt->camera, s->camera);
	rt->canvas = render(rt->camera, rt->world);
	rt->window = mlx_new_window(rt->canvas->mlx, RT_WIDTH, RT_HEIGHT, "miniRT");
	return (rt);
}
