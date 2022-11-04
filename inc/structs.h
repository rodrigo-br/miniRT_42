/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:06:43 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/04 10:21:16 by maolivei         ###   ########.fr       */
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

typedef t_tuple			t_vector; /* tuple with 'w' value equal to 0 */
typedef t_tuple			t_point; /* tuple with 'w' value equal to 1 */
typedef struct s_object	t_object;

typedef struct s_matrix
{
	size_t	size;
	double	matrix[MAT_MAX][MAT_MAX];
}	t_matrix;

typedef struct s_rgb
{
	double	red;
	double	green;
	double	blue;
	int		merged;
}	t_rgb;

typedef struct s_rt_ambient
{
	double	ratio;
	t_rgb	*color;
}	t_rt_ambient;

typedef struct s_rt_camera
{
	t_point		*view_point;
	t_vector	*orientation;
	int			fov;
}	t_rt_camera;

typedef struct s_rt_light
{
	double	x;
	double	y;
	double	z;
	double	brightness;
	int		red;
	int		green;
	int		blue;
}	t_rt_light;

typedef struct s_rt_scene
{
	t_rt_ambient	*ambient;
	t_rt_camera		*camera;
	t_rt_light		*light;
	t_list			*objects;
}	t_rt_scene;

/* tipos de acordo com as especificaçoes de cada um */
typedef struct s_sphere
{
	double	diameter;
	t_point	center;
}	t_sphere;

typedef struct s_plane
{
	t_point	position;
}	t_plane;

typedef struct s_cylinder
{
	t_point	position;
	double	diameter;
	double	min;
	double	max;
	t_bool	capped;
}	t_cylinder;

typedef struct s_pattern
{
	t_rgb		*color_a;
	t_rgb		*color_b;
	t_matrix	*transformation;
	t_matrix	*inverse_transformation;
}	t_pattern;

typedef struct s_material
{
	t_rgb		*color;
	t_rgb		*ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	t_pattern	*pattern;
}	t_material;

typedef struct s_ray
{
	t_point		*origin;
	t_vector	*direction;
}	t_ray;

typedef struct s_intersect
{
	t_object			*object;
	double				time;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_object
{
	t_object_id	type;
	union
	{
		t_sphere	sphere;
		t_cylinder	cylinder;
		t_plane		plane;
	};
	t_vector	*orientation;
	t_matrix	*transformation;
	t_matrix	*inverse_transformation;
	t_material	*material;
	void		(*intersect)(t_object *, t_ray *, t_intersect **);
	t_vector	*(*get_normal)(t_object *, t_point *);
}	t_object;

typedef struct s_canvas
{
	void	*mlx;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endianness;
}	t_canvas;

typedef struct s_bhaskara
{
	double	a;
	double	b;
	double	c;
	double	delta;
}	t_bhaskara;

typedef struct s_shearing
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shearing;

typedef struct s_light_point
{
	t_point	*position;
	t_rgb	*intensity;
}	t_light_pnt;

typedef struct s_position_attributes
{
	t_vector	*camera;
	t_vector	*normal;
	t_point		*position;
}	t_pos_attr;

typedef struct s_light_attributes
{
	t_light_pnt	*light_point;
	t_object	*object;
	t_vector	*camera;
	t_vector	*normal;
	t_point		*position;
	t_material	*material;
	t_bool		in_shadow;
}	t_lightattr;

typedef struct s_world
{
	t_list	*light_point;
	t_list	*objects;
}	t_world;

typedef struct s_comp
{
	t_object	*object;
	double		time;
	t_point		*point;
	t_vector	*normal;
	t_vector	*camera;
	t_point		*over_point;
}	t_comp;

typedef struct s_cam
{
	double		pixel_size;
	double		field_of_view;
	double		h_size;
	double		v_size;
	double		half_width;
	double		half_height;
	t_matrix	*transformation;
	t_matrix	*inverse_transformation;
}	t_cam;

typedef struct s_minirt
{
	t_cam		*camera;
	t_canvas	*canvas;
	t_world		*world;
	void		*window;
}	t_minirt;

#endif
