/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:17:03 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 12:44:38 by maolivei         ###   ########.fr       */
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
	cylinder->intersect = intersect_cylinder;
	cylinder->get_normal = get_cylinder_normal;
	return (cylinder);
}

void	intersect_cylinder(t_object *cyl, t_ray *ray, t_intersect **head)
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	t_bhaskara	bhaskara;

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
	(void)cylinder;
	return (create_vector(point->x, 0, point->z));
}
