/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:17:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/01 20:34:18 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_object	*create_cylinder(void)
{
	t_object	*cylinder;

	cylinder = create_shape();
	if (!cylinder)
		return (NULL);
	cylinder->type = ID_CYLINDER;
	cylinder->cylinder.diameter = 1.0;
	cylinder->cylinder.min = -INFINITY;
	cylinder->cylinder.max = INFINITY;
	cylinder->cylinder.capped = TRUE;
	cylinder->intersect = intersect_cylinder;
	cylinder->get_normal = get_cylinder_normal;
	return (cylinder);
}

t_bool	is_cap_within_radius(t_ray *ray, double time)
{
	double	x;
	double	z;

	x = ray->origin->x + (time * ray->direction->x);
	z = ray->origin->z + (time * ray->direction->z);
	return (((x * x) + (z * z)) <= 1);
}

void	intersect_caps(t_object *cyl, t_ray *ray, t_intersect **head)
{
	double	time;

	if (!cyl->cylinder.capped || fabs(ray->direction->y) < EPSILON)
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
	t_bhaskara	bhaskara;

	intersect_caps(cyl, ray, head);
	bhaskara.a = pow(ray->direction->x, 2) + pow(ray->direction->z, 2);
	if (fabs(bhaskara.a) < EPSILON)
		return ;
	bhaskara.b = 2 * ray->origin->x * ray->direction->x;
	bhaskara.b += 2 * ray->origin->z * ray->direction->z;
	bhaskara.c = pow(ray->origin->x, 2) + pow(ray->origin->z, 2) - 1;
	bhaskara.delta = (bhaskara.b * bhaskara.b) - (4 * bhaskara.a * bhaskara.c);
	if (bhaskara.delta < 0)
		return ;
	x1 = (-bhaskara.b - sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	x2 = (-bhaskara.b + sqrt(bhaskara.delta)) / (2 * bhaskara.a);
	y1 = ray->origin->y + (x1 * ray->direction->y);
	y2 = ray->origin->y + (x2 * ray->direction->y);
	if (cyl->cylinder.min < y1 && y1 < cyl->cylinder.max)
		intersection_sorted_insert(head, create_intersection(x1, cyl));
	if (!is_equal_double(x1, x2))
		if (cyl->cylinder.min < y2 && y2 < cyl->cylinder.max)
			intersection_sorted_insert(head, create_intersection(x2, cyl));
}

t_vector	*get_cylinder_normal(t_object *cylinder, t_point *point)
{
	double	distance;

	distance = (point->x * point->x) + (point->z * point->z);
	if (distance < 1 && point->y >= cylinder->cylinder.max - EPSILON)
		return (create_vector(0, 1, 0));
	if (distance < 1 && point->y <= cylinder->cylinder.min + EPSILON)
		return (create_vector(0, -1, 0));
	return (create_vector(point->x, 0, point->z));
}
