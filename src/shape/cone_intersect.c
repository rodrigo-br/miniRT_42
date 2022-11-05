/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:41:56 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 21:15:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_bhaskara	get_delta_value(t_ray *ray)
{
	t_bhaskara	_;

	_.a = pow(ray->direction->x, 2);
	_.a -= pow(ray->direction->y, 2);
	_.a += pow(ray->direction->z, 2);
	_.b = (2 * ray->origin->x * ray->direction->x);
	_.b -= (2 * ray->origin->y * ray->direction->y);
	_.b += (2 * ray->origin->z * ray->direction->z);
	_.c = pow(ray->origin->x, 2);
	_.c -= pow(ray->origin->y, 2);
	_.c += pow(ray->origin->z, 2);
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	return (_);
}

static t_bool	is_cap_within_radius(t_ray *ray, double time, double radius)
{
	double	x;
	double	z;

	x = ray->origin->x + (time * ray->direction->x);
	z = ray->origin->z + (time * ray->direction->z);
	return (((x * x) + (z * z)) <= radius);
}

static void	intersect_caps(t_object *cone, t_ray *ray, t_intersect **head)
{
	double	time;

	if (!cone->cone.capped || is_equal_double(0.0, ray->direction->y))
		return ;
	time = (cone->cone.min - ray->origin->y) / ray->direction->y;
	if (is_cap_within_radius(ray, time, (cone->cone.max / 2)))
		intersection_sorted_insert(head, create_intersection(time, cone));
	time = (cone->cone.max - ray->origin->y) / ray->direction->y;
	if (is_cap_within_radius(ray, time, (cone->cone.max / 2)))
		intersection_sorted_insert(head, create_intersection(time, cone));
}

void	intersect_cone(t_object *cone, t_ray *ray, t_intersect **head)
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	t_bhaskara	_;

	intersect_caps(cone, ray, head);
	_ = get_delta_value(ray);
	if (is_equal_double(0.0, _.a) && is_equal_double(0.0, _.b))
		return ;
	if (is_equal_double(0.0, _.a))
		return (intersection_sorted_insert(
				head, create_intersection((-_.c / (2 * _.b)), cone)));
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
