/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:25:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 19:16:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include <unity/unity.h>
#include <minirt.h>
#include <time.h>

#define LOOP_ITERATIONS 100

void	test_tuple_operations(void);
void	test_colors(void);
void	test_canvas(void);
void	test_matrix(void);
void	pre_parser_errors(void);
void	test_parser(void);
void	test_check_light(void);
void	test_check_ambient(void);
void	test_check_camera(void);
void	test_check_cylinder(void);
void	test_check_plane(void);
void	test_check_sphere(void);
void	test_transformations(void);
void	test_ray(void);
void	test_world(void);
void	test_light_and_shading(void);
void	test_view_transformation(void);
void	test_camera(void);
void	test_shape(void);

/* Utils */
double	double_rand();
double	color_rand();
int		decode_rgba(int r, int g, int b);
int		pixel_at(t_canvas *canvas, int x, int y);
int		merge_colors(double r, double g, double b);
int		to_rgb(double color);
t_world	*default_world(void);

#endif /* TESTS_H */
