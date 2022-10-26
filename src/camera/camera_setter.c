/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:01:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/26 09:28:24 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_camera_transformation(t_cam *camera, t_matrix *transform)
{
	free(camera->transformation);
	free(camera->inverse_transformation);
	camera->transformation = transform;
	camera->inverse_transformation = inverse_matrix(transform);
}
