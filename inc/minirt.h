/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/17 21:51:53 by ralves-b         ###   ########.fr       */
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

# define EPSILON 0.00001
# define AMBIENT 'A'
# define CAMERA 'C'
# define LIGHT	'L'
# define SPHERE "sp"
# define PLANE	"pl"
# define CYLINDER "cy"

t_tuple		*create_tuple(int x, int y, int z, int w);
t_point		*create_point(int x, int y, int z);
t_vector	*create_vector(int x, int y, int z);
int			errors(int argc, char **argv);
int			parser_1(int fd);

t_bool		is_equal(double a, double b);
t_bool		is_equal_tuple(t_tuple *a, t_tuple *b);
t_tuple		*sum_tuple(t_tuple *a, t_tuple *b);
t_tuple		*sub_tuple(t_tuple *a, t_tuple *b);
t_tuple		*neg_tuple(t_tuple *a);

#endif /* MINIRT_H */
