/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:01:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 20:03:25 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_camera_transformation(t_cam	*camera, t_matrix *transformation)
{
	free(camera->inverse_transformation);
	free(camera->transformation);
	camera->transformation = transformation;
	camera->inverse_transformation = inverse_matrix(transformation);
}
