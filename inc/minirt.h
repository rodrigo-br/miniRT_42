/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/17 20:31:44 by ralves-b         ###   ########.fr       */
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
