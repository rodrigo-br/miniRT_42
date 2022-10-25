/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/25 20:02:34 by ralves-b         ###   ########.fr       */
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
# define AMBIENT 'A'
# define CAMERA 'C'
# define LIGHT	'L'
# define SPHERE "sp"
# define PLANE	"pl"
# define CYLINDER "cy"

/* Errors before canvas*/
int			errors(int argc, char **argv, int *fd);

/* Parser */
int			parser_1(int fd, t_scene *scene);
int			check_light(char **line_splited, t_light **light);
int			check_ambient(char **line_splited, t_ambience **ambience);
int			check_camera(char **line_splited, t_camera **camera);
int			check_sphere(char **line_splited, t_list **object);
int			check_plane(char **line_splited, t_list **object);
int			check_cylinder(char **line_splited, t_list **object);
int			check_rgb_digits(char **rgb, int *red, int *green, int *blue);
int			check_object_3d_orientation(char *s);
int			check_coordinates_digits(char **coordinates);
char		**check_rgb(char *s);

/* List */
void		free_lst_obj(void *obj);
void		free_scene(t_scene *scene);

/* Extra libft functions */
double		ft_atod(char *s);
int			ft_is_a_double(char *string);
int			ft_is_all_digit(char *string);
void		ft_str_swap_set_chr(char *str, char *old, char new);
int			set_double_value(double *variable, char *value);
size_t		ft_get_matrix_len(char **matrix);

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
t_rgb		*create_color(double r, double g, double b);
t_rgb		*sum_color(t_rgb *a, t_rgb *b);
t_rgb		*sub_color(t_rgb *a, t_rgb *b);
t_rgb		*multiply_color(t_rgb *a, t_rgb *b);
t_rgb		*scalar_multiply_color(t_rgb *a, double multiplier);
int			to_rgb(double color);

/* Canvas */
t_canvas	*create_canvas(void *mlx, int width, int height);
void		write_to_canvas(t_canvas *canvas, int x, int y, t_rgb rgb);

/* Matrix */
t_bool		is_equal_matrix(t_matrix *a, t_matrix *b);
t_matrix	*create_matrix(size_t size, const double m[MAT_MAX][MAT_MAX]);
t_matrix	*create_identity_matrix(void);
t_matrix	*create_submatrix(t_matrix *m, size_t delrow, size_t delcol);
t_matrix	*multiply_matrix(t_matrix *a, t_matrix *b);
t_tuple		*multiply_matrix_tuple(t_matrix *m, t_tuple *t);
t_matrix	*transpose_matrix(t_matrix *m);
t_matrix	*inverse_matrix(t_matrix *m);
double		determinant(t_matrix *m);
double		minor(t_matrix *m, size_t row, size_t col);
double		cofactor(t_matrix *m, size_t row, size_t col);

/* Transformation */
t_matrix	*translate_matrix(double x, double y, double z);
t_matrix	*scale_matrix(double x, double y, double z);
t_matrix	*shearing_matrix(t_shearing s);
t_matrix	*rotate_matrix_x(double r);
t_matrix	*rotate_matrix_y(double r);
t_matrix	*rotate_matrix_z(double r);
double		radians(double degree);

/* Ray */
t_ray		*create_ray(t_point *origin, t_vector *direction);
void		destroy_ray(t_ray *ray);
t_object	*create_sphere(void);
void		destroy_shape(void *object);
t_point		*get_position(t_ray *ray, double time);
t_vector	*get_sphere_normal(t_object *sphere, t_point *point);
t_intersect	*create_intersection(double time, t_object *object);
t_intersect	*get_hit(t_intersect *intersect);
t_ray		*transform_ray(t_ray *ray, t_matrix *matrix);
void		set_transformation(t_object *object, t_matrix *transformation);
void		intersection_sorted_insert(t_intersect **head, t_intersect *new);
void		intersect_sphere(t_object *sphere, t_ray *ray, t_intersect **head);
void		intersection_list_clear(t_intersect **list);
size_t		intersection_list_size(t_intersect *list);

/* Light */
t_vector	*reflect(t_vector *in, t_vector *normal);
t_rgb		*lighting(t_lightattr *args);
t_material	*create_material(void);
t_pos_attr	*create_pos_attr(t_vector *camera, t_vector *normal, t_point *pos);
t_light_pnt	*create_light_point(t_point *position, t_rgb *intensity);
t_lightattr	*create_lightattr(t_light_pnt *lp, t_pos_attr *pos, t_material *m);
void		destroy_material(t_material *material);
void		destroy_light_point(void *light_point);
void		destroy_lightattr(t_lightattr *attributes);

/*World*/
t_world		*create_world(void);
void		destroy_world(t_world *w);
void		intersect_world(t_world *world, t_ray *ray, t_intersect **head);
t_comp		*prepare_computation(t_intersect *i, t_ray *ray);
void		destroy_computation(t_comp *comps);
t_rgb		*shade_hit(t_world *world, t_comp *comps);
t_rgb		*color_at(t_world *world, t_ray *ray);
t_matrix	*view_transform(t_point *from, t_point *to, t_vector *up);

/*Camera*/
t_cam		*create_camera(double h_size, double v_size, double field_of_view);
t_ray		*ray_for_pixel(t_cam *camera, double x, double y);
void		destroy_camera(t_cam *cam);
void		set_camera_transformation(t_cam	*camera, t_matrix *transformation);

#endif /* MINIRT_H */
