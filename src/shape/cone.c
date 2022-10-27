/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:56:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 16:45:59 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	is_cap_within_radius_cone(t_ray *ray, double time, double radius)
{
	double	x;
	double	z;

	x = ray->origin->x + (time * ray->direction->x);
	z = ray->origin->z + (time * ray->direction->z);
	return (((x * x) + (z * z)) <= radius);
}

void	intersect_caps_cone(t_object *cone, t_ray *ray, t_intersect **head)
{
	double	time;

	if (!cone->cone.capped || fabs(ray->direction->y) < EPSILON)
		return ;
	time = (cone->cone.min - ray->origin->y) / ray->direction->y;
	if (is_cap_within_radius_cone(ray, time, cone->cone.min))
		intersection_sorted_insert(head, create_intersection(time, cone));
	time = (cone->cone.max - ray->origin->y) / ray->direction->y;
	if (is_cap_within_radius_cone(ray, time, cone->cone.max))
		intersection_sorted_insert(head, create_intersection(time, cone));
}

void	intersect_cone(t_object *cone, t_ray *ray, t_intersect **head)
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	t_bhaskara	_;

	intersect_caps_cone(cone, ray, head);
	_.a = pow(ray->direction->x, 2) - pow(ray->direction->y, 2) + pow(ray->direction->z, 2);
	_.b = (2 * ray->origin->x * ray->direction->x) - (2 * ray->origin->y * ray->direction->y) + (2 * ray->origin->z * ray->direction->z);
	_.c = pow(ray->origin->x, 2) - pow(ray->origin->y, 2) + pow(ray->origin->z, 2);
	if (is_equal_double(0.0, _.a) && is_equal_double(0.0, _.b))
		return ;
	if (is_equal_double(0.0, _.a))
		return (intersection_sorted_insert(head, create_intersection((-_.c / (2 * _.b)), cone)));
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	if (_.delta < 0)
		return ;
	x1 = (-_.b - sqrt(_.delta)) / (2 * _.a);
	x2 = (-_.b + sqrt(_.delta)) / (2 * _.a);
	y1 = ray->origin->y + (x1 * ray->direction->y);
	y2 = ray->origin->y + (x2 * ray->direction->y);
	if (cone->cone.min < y1 && y1 < cone->cone.max)
		intersection_sorted_insert(head, create_intersection(x1, cone));
	if (!is_equal_double(x1, x2))
		if (cone->cone.min < y2 && y2 < cone->cone.max)
			intersection_sorted_insert(head, create_intersection(x2, cone));
}

t_vector	*get_cone_normal(t_object *cone, t_point *point)
{
	double	distance;
	double	y;

	distance = (point->x * point->x) + (point->z * point->z);
	if (distance < 1 && point->y >= cone->cone.max - EPSILON)
		return (create_vector(0, 1, 0));
	if (distance < 1 && point->y <= cone->cone.min + EPSILON)
		return (create_vector(0, -1, 0));
	y = sqrt((point->x * point->x) + (point->z * point->z));
	if (point->y > 0.0)
		y = -y;
	return (create_vector(point->x, y, point->z));
}

t_object	*create_cone(void)
{
	t_object	*cone;

	cone = create_shape();
	if (!cone)
		return (NULL);
	cone->type = ID_CONE;
	cone->cone.diameter = 1.0;
	cone->cone.min = -INFINITY;
	cone->cone.max = INFINITY;
	cone->cone.capped = FALSE;
	cone->intersect = intersect_cone;
	cone->get_normal = get_cone_normal;
	return (cone);
}
