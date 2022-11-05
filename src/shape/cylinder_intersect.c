/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:42:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 19:44:13 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bhaskara	get_delta_value(t_ray *ray)
{
	t_bhaskara	_;

	_.a = pow(ray->direction->x, 2);
	_.a += pow(ray->direction->z, 2);
	_.b = 2 * ray->origin->x * ray->direction->x;
	_.b += 2 * ray->origin->z * ray->direction->z;
	_.c = pow(ray->origin->x, 2) + pow(ray->origin->z, 2) - 1;
	_.delta = (_.b * _.b) - (4 * _.a * _.c);
	return (_);
}

static t_bool	is_cap_within_radius(t_ray *ray, double time)
{
	double	x;
	double	z;

	x = ray->origin->x + (time * ray->direction->x);
	z = ray->origin->z + (time * ray->direction->z);
	return (((x * x) + (z * z)) <= 1);
}

static void	intersect_caps(t_object *cyl, t_ray *ray, t_intersect **head)
{
	double	time;

	if (!cyl->cylinder.capped || is_equal_double(0.0, ray->direction->y))
		return ;
	time = (cyl->cylinder.min - ray->origin->y) / ray->direction->y;
	if (is_cap_within_radius(ray, time))
		intersection_sorted_insert(head, create_intersection(time, cyl));
	time = (cyl->cylinder.max - ray->origin->y) / ray->direction->y;
	if (is_cap_within_radius(ray, time))
		intersection_sorted_insert(head, create_intersection(time, cyl));
}

void	intersect_cylinder(t_object *cyl, t_ray *ray, t_intersect **head)
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	t_bhaskara	_;

	intersect_caps(cyl, ray, head);
	_ = get_delta_value(ray);
	if (is_equal_double(0.0, _.a))
		return ;
	if (_.delta < 0)
		return ;
	x1 = (-_.b - sqrt(_.delta)) / (2 * _.a);
	x2 = (-_.b + sqrt(_.delta)) / (2 * _.a);
	y1 = ray->origin->y + (x1 * ray->direction->y);
	y2 = ray->origin->y + (x2 * ray->direction->y);
	if (cyl->cylinder.min < y1 && y1 < cyl->cylinder.max)
		intersection_sorted_insert(head, create_intersection(x1, cyl));
	if (!is_equal_double(x1, x2))
		if (cyl->cylinder.min < y2 && y2 < cyl->cylinder.max)
			intersection_sorted_insert(head, create_intersection(x2, cyl));
}
