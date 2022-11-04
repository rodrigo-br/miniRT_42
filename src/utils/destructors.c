/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:44:52 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 19:44:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	destroy_scene(t_rt_scene *scene)
{
	if (scene->camera)
	{
		ft_memfree((void *)&scene->camera->orientation);
		ft_memfree((void *)&scene->camera->view_point);
		ft_memfree((void *)&scene->camera);
	}
	if (scene->ambient)
	{
		ft_memfree((void *)&scene->ambient->color);
		ft_memfree((void *)&scene->ambient);
	}
	if (scene->light)
		ft_memfree((void *)&scene->light);
	ft_lstclear(&scene->objects, destroy_shape);
}

void	destroy_minirt(t_rt_scene *scene, t_minirt *rt)
{
	destroy_world(rt->world);
	destroy_camera(rt->camera);
	ft_memfree((void *)&scene->camera->orientation);
	ft_memfree((void *)&scene->camera->view_point);
	ft_memfree((void *)&scene->camera);
	ft_memfree((void *)&scene->ambient->color);
	ft_memfree((void *)&scene->ambient);
	ft_memfree((void *)&scene->light);
}
