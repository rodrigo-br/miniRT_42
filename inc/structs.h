/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:06:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/24 19:18:34 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MAT_MAX 4

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

typedef struct s_matrix
{
	size_t	size;
	double	matrix[MAT_MAX][MAT_MAX];
}	t_matrix;

typedef struct s_rgb
{
	double	blue;
	double	green;
	double	red;
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
typedef struct s_sphere
{
	double	diameter;
	t_point	center;
}	t_sphere;

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
	int			type;
	union
	{
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_plane		plane;
	};
	double		x;
	double		y;
	double		z;
	t_rgb		*rgb;
	t_matrix	*transformation;
	t_matrix	*inverse_transformation;
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

typedef struct s_ray
{
	t_point		*origin;
	t_vector	*direction;
}	t_ray;

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_bhaskara;

typedef struct s_intersect
{
	t_object			*object;
	double				time;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_shearing
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shearing;

#endif
