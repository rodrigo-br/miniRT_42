/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 12:45:32 by maolivei         ###   ########.fr       */
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
# include <structs.h>

# define VECTOR_W 0.0
# define POINT_W 1.0
# define EPSILON 0.00001
# define OPACITY_MAX 255
# define AMBIENT 'A'
# define CAMERA 'C'
# define LIGHT	'L'
# define SPHERE "sp"
# define PLANE	"pl"
# define CYLINDER "cy"

int			errors(int argc, char **argv);
int			parser_1(int fd);
int			check_light(char **line_splited);
int			check_ambient(char **line_splited);
int			check_camera(char **line_splited);
double		ft_atod(char *s);
int			ft_is_a_double(char *string);
int			ft_is_all_digit(char *string);
void		ft_str_swap_set_chr(char *str, char *old, char new);
int			check_rgb_digits(char **rgb, int *red, int *green, int *blue);
int			check_coordinates_digits(char **coordinates);

/* Constructors */
t_tuple		*create_tuple(double x, double y, double z, double w);
t_point		*create_point(double x, double y, double z);
t_vector	*create_vector(double x, double y, double z);

/* Checkers */
t_bool		is_point(t_tuple *t);
t_bool		is_vector(t_tuple *t);
t_bool		is_tuple(t_tuple *t);
t_bool		is_equal_double(double a, double b);
t_bool		is_equal_tuple(t_tuple *a, t_tuple *b);

/* Operations */
t_tuple		*sum_tuple(t_tuple *a, t_tuple *b);
t_tuple		*sub_tuple(t_tuple *a, t_tuple *b);
t_tuple		*neg_tuple(t_tuple *a);
t_tuple		*scalar_multiply_tuple(t_tuple *t, double multiplier);
t_tuple		*scalar_divide_tuple(t_tuple *t, double divider);

/* Manipulators */
double		dot_product(t_tuple *a, t_tuple *b);
double		magnitude(t_tuple *t);
t_tuple		*normalize(t_tuple *t);
t_tuple		*cross_product(t_tuple *a, t_tuple *b);

/* Colors */
t_rgb		*create_color(int r, int g, int b);
t_rgb		*sum_color(t_rgb *a, t_rgb *b);
t_rgb		*sub_color(t_rgb *a, t_rgb *b);
t_rgb		*multiply_color(t_rgb *a, t_rgb *b);
t_rgb		*scalar_multiply_color(t_rgb *a, double multiplier);

#endif /* MINIRT_H */
