/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:24 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/04 19:59:08 by maolivei         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>

# define RT_WIDTH 1366
# define RT_HEIGHT 768
# define VECTOR_W 0.0
# define POINT_W 1.0
# define EPSILON 0.00001
# ifndef M_PI
#  define M_PI 3.14159265358979323846	/* π */
# endif
# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923	/* π / 2 */
# endif

# define AMBIENT "A"
# define CAMERA "C"
# define LIGHT	"L"
# define SPHERE "sp"
# define PLANE	"pl"
# define CYLINDER "cy"
# define BLANKSPACES "\f\r\t\v"

typedef enum e_parse_id
{
	NONE,
	PARSE_AMBIENT,
	PARSE_CAMERA,
	PARSE_LIGHT,
	PARSE_SPHERE,
	PARSE_PLANE,
	PARSE_CYLINDER
}	t_parse_id;

# define PARSE_ID_MIN PARSE_AMBIENT
# define PARSE_ID_MAX PARSE_CYLINDER

typedef int	t_delegator(char **tokens, t_rt_scene *s);

/* ALT */
t_minirt	*scene_to_world(t_rt_scene *s);
int			read_rt_file(char *filename, t_rt_scene *s);
int			parse_ambient(char **tokens, t_rt_scene *s);
int			parse_camera(char **tokens, t_rt_scene *s);
int			parse_light(char **tokens, t_rt_scene *s);
int			parse_sphere(char **tokens, t_rt_scene *s);
int			parse_plane(char **tokens, t_rt_scene *s);
int			parse_cylinder(char **tokens, t_rt_scene *s);

/* Parser setters */
int			set_shape_color(char *token, t_object *shape);
int			set_shape_orientation_vector(char *token, t_object *shape);
int			set_shape_material(t_object *shape, t_rt_scene *s);

/* Checkers */
int			check_user_input(int argc);
int			check_file_extension(char *filename);
int			check_scene_elements(t_rt_scene *s);
int			check_vector_normalization(double x, double y, double z);

/* Error handling */
int			error(const char *warning);

/* MLX helpers */
int			end_program(t_minirt *rt);
int			keypress_handler(int keysym, t_minirt *rt);
void		setup_visual_environment(t_minirt *rt);

/* Destructors */
void		destroy_scene(t_rt_scene *scene);
void		destroy_minirt(t_rt_scene *scene, t_minirt *rt);

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
t_rgb		*create_formatted_color(double r, double g, double b);
t_rgb		*sum_color(t_rgb *a, t_rgb *b);
t_rgb		*sub_color(t_rgb *a, t_rgb *b);
t_rgb		*multiply_color(t_rgb *a, t_rgb *b);
t_rgb		*scalar_multiply_color(t_rgb *a, double multiplier);
void		set_color(t_rgb *color, double r, double g, double b);

/* Canvas */
t_canvas	*create_canvas(double height, double width);
void		destroy_canvas(t_canvas *canvas);
void		write_to_canvas(t_canvas *canvas, int x, int y, int color);

/* Matrix */
t_bool		is_equal_matrix(t_matrix *a, t_matrix *b);
t_matrix	*create_matrix(size_t size, const double m[MAT_MAX][MAT_MAX]);
t_matrix	*create_identity_matrix(void);
t_matrix	*create_submatrix(t_matrix *m, size_t delrow, size_t delcol);
t_matrix	*multiply_matrix(t_matrix *a, t_matrix *b);
t_matrix	*multiply_matrix_triple(t_matrix *a, t_matrix *b, t_matrix *c);
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
t_matrix	*full_rotation_matrix(t_vector *vector);
double		radians(double degree);

/* Ray */
t_ray		*create_ray(t_point *origin, t_vector *direction);
void		destroy_ray(t_ray *ray);
t_ray		*transform_ray(t_ray *ray, t_matrix *matrix);

t_object	*create_shape(void);
t_object	*create_sphere(void);
t_object	*create_plane(void);
t_object	*create_cylinder(void);
t_object	*create_cone(void);
void		destroy_shape(void *object);
void		set_object_transformation(t_object *object, t_matrix *transform);

t_point		*get_position(t_ray *ray, double time);
t_vector	*normal_at(t_object *shape, t_point *point);
t_vector	*get_sphere_normal(t_object *sphere, t_point *point);
t_vector	*get_plane_normal(t_object *plane, t_point *point);
t_vector	*get_cylinder_normal(t_object *cylinder, t_point *point);
t_vector	*get_cone_normal(t_object *cone, t_point *point);
t_intersect	*get_hit(t_intersect *intersect);

void		intersect_sphere(t_object *sphere, t_ray *ray, t_intersect **head);
void		intersect_plane(t_object *plane, t_ray *ray, t_intersect **head);
void		intersect_cylinder(t_object *cyl, t_ray *ray, t_intersect **head);
void		intersect_cone(t_object *cone, t_ray *ray, t_intersect **head);
void		intersection_sorted_insert(t_intersect **head, t_intersect *new);
void		intersection_list_clear(t_intersect **list);
size_t		intersection_list_size(t_intersect *list);
t_intersect	*create_intersection(double time, t_object *object);

/* Light */
t_bool		is_shadowed(t_world *world, t_point *point, t_light_pnt *lp);
t_vector	*reflect(t_vector *in, t_vector *normal);
t_rgb		*lighting(t_lightattr *args);
t_material	*create_material(void);
t_pos_attr	*create_pos_attr(t_vector *camera, t_vector *normal, t_point *pos);
t_light_pnt	*create_light_point(t_point *position, t_rgb *intensity);
t_lightattr	*create_lightattr(t_light_pnt *lp, t_pos_attr *pos, t_material *m);
void		destroy_material(t_material *material);
void		destroy_light_point(void *light_point);
void		destroy_lightattr(t_lightattr *attributes);

/* World */
t_world		*create_world(void);
void		destroy_world(t_world *w);
void		intersect_world(t_world *world, t_ray *ray, t_intersect **head);
t_comp		*prepare_computation(t_intersect *i, t_ray *ray);
void		destroy_computation(t_comp *comps);
t_rgb		*shade_hit(t_world *world, t_comp *comps, t_list *light_list);
t_rgb		*color_at(t_world *world, t_ray *ray);
t_matrix	*view_transform(t_point *from, t_point *to, t_vector *up);

/* Camera */
t_cam		*create_camera(double h_size, double v_size, double field_of_view);
t_ray		*ray_for_pixel(t_cam *camera, double x, double y);
void		destroy_camera(t_cam *camera);
void		set_camera_transformation(t_cam	*camera, t_matrix *transform);
t_canvas	*render(t_cam *camera, t_world *world);

/* Pattern */
t_pattern	*create_pattern(t_rgb *a, t_rgb *b);
t_rgb		*pattern_at(t_pattern *pattern, t_point	*point);
void		destroy_pattern(t_pattern *pattern);
t_rgb		*pattern_at_obj(t_pattern *pat, t_point *point, t_object *obj);
void		set_pattern_transformation(t_pattern *pattern, t_matrix *transform);

#endif /* MINIRT_H */
