/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:06:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/18 18:34:18 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef t_tuple	t_vector; /* tuple with 'w' value equal to 0 */
typedef t_tuple	t_point; /* tuple with 'w' value equal to 1 */

typedef union u_rgb
{
	int					color;
	struct
	{
		unsigned char	opacity;
		unsigned char	red;
		unsigned char	green;
		unsigned char	blue;
	};
}	t_rgb;

typedef struct s_ambience
{
	double	ratio;
	t_rgb	rgb;
}	t_ambience;

typedef struct s_camera
{
	double	view_x;
	double	view_y;
	double	view_z;
	double	x_3d;
	double	y_3d;
	double	z_3d;
	int		fov;
}	t_camera;

typedef struct s_light
{
	double	x;
	double	y;
	double	z;
	double	brightness;
	t_rgb	rgb;
}	t_light;

typedef struct s_object
{
	int		type;
	double	x;
	double	y;
	double	z;
	t_rgb	rgb;
	void	*specs;
}	t_object;

/* tipos de acordo com as especificaçoes de cada um */
typedef double	t_sphere;

typedef struct s_plane
{
	double	x;
	double	y;
	double	z;
}	t_plane;

typedef struct s_cylinder
{
	double	x;
	double	y;
	double	z;
	double	diamenter;
	double	height;
}	t_cylinder;

typedef struct s_scene
{
	t_ambience	ambience;
	t_light		light;
	t_camera	camera;
	t_object	*objects;
}	t_scene;

#endif