/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:05:13 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/20 20:00:29 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_scene(t_scene *scene)
{
	ft_lstclear(&scene->objects, free_lst_obj);
	if (scene->ambience)
	{
		free(scene->ambience->rgb);
		free(scene->ambience);
	}
	if (scene->light)
	{
		free(scene->light->rgb);
		free(scene->light);
	}
	if (scene->camera)
		free(scene->camera);
	free(scene);
}
