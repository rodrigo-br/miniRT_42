/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:07:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 20:04:56 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_cam	*create_camera(double h_size, double v_size, double field_of_view)
{
	double	half_view;
	double	aspect_ratio;
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	half_view = tan(field_of_view / 2);
	aspect_ratio = h_size / v_size;
	cam->half_width = half_view;
	cam->half_height = half_view / aspect_ratio;
	if (aspect_ratio < 1)
	{
		cam->half_width = half_view * aspect_ratio;
		cam->half_height = half_view;
	}
	cam->field_of_view = field_of_view;
	cam->h_size = h_size;
	cam->v_size = v_size;
	cam->pixel_size = (cam->half_width * 2) / h_size;
	cam->transformation = create_identity_matrix();
	cam->inverse_transformation = create_identity_matrix();
	return (cam);
}
