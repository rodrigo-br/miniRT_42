/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:06:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/21 14:56:15 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MATRIX_MAX 4

typedef enum e_object_id
{
	ID_SPHERE,
	ID_CYLINDER,
	ID_PLANE,
}	t_object_id;

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
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	opacity;
	};
}	t_rgb;

typedef struct s_ambience
{
	double	ratio;
	t_rgb	*rgb;
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
	t_rgb	*rgb;
}	t_light;

/* tipos de acordo com as especificaçoes de cada um */
typedef double	t_sphere;

typedef struct s_plane
{
	double	x_3d;
	double	y_3d;
	double	z_3d;
}	t_plane;

typedef struct s_cylinder
{
	double	x_3d;
	double	y_3d;
	double	z_3d;
	double	diameter;
	double	height;
}	t_cylinder;

typedef struct s_object
{
	int		type;
	union
	{
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_plane		plane;
	};
	double	x;
	double	y;
	double	z;
	t_rgb	*rgb;
}	t_object;

typedef struct s_scene
{
	t_ambience	*ambience;
	t_light		*light;
	t_camera	*camera;
	t_list		*objects;
}	t_scene;

typedef struct s_canvas
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}	t_canvas;

typedef struct s_matrix
{
	size_t	size;
	double	matrix[MATRIX_MAX][MATRIX_MAX];
}	t_matrix;

typedef struct s_ray
{
	t_point		*origin;
	t_vector	*direction;
}	t_ray;

#endif
