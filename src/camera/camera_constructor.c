/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:07:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 20:07:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_cam	*create_camera(double h_size, double v_size, double field_of_view)
{
	double	half_view;
	double	aspect_ratio;
	t_cam	*camera;

	camera = (t_cam *)malloc(sizeof(t_cam));
	if (!camera)
		return (NULL);
	half_view = tan(field_of_view / 2);
	aspect_ratio = h_size / v_size;
	camera->half_width = half_view;
	camera->half_height = half_view / aspect_ratio;
	if (aspect_ratio < 1)
	{
		camera->half_width = half_view * aspect_ratio;
		camera->half_height = half_view;
	}
	camera->field_of_view = field_of_view;
	camera->h_size = h_size;
	camera->v_size = v_size;
	camera->pixel_size = (camera->half_width * 2) / h_size;
	camera->transformation = create_identity_matrix();
	camera->inverse_transformation = create_identity_matrix();
	return (camera);
}
