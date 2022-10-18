/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/17 21:04:55 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define EPSILON 0.00001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

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

typedef t_tuple	t_vector; /* tuple with 'w' value equal to 0 */
typedef t_tuple	t_point; /* tuple with 'w' value equal to 1 */

t_tuple		*create_tuple(int x, int y, int z, int w);
t_point		*create_point(int x, int y, int z);
t_vector	*create_vector(int x, int y, int z);
int			errors(int argc, char **argv);

t_bool		is_equal(double a, double b);
t_bool		is_equal_tuple(t_tuple *a, t_tuple *b);
t_tuple		*sum_tuple(t_tuple *a, t_tuple *b);
t_tuple		*sub_tuple(t_tuple *a, t_tuple *b);
t_tuple		*neg_tuple(t_tuple *a);

#endif /* MINIRT_H */
