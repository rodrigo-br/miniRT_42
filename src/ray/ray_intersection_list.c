/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:46:28 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 15:47:43 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_intersect	*create_intersection(double time, t_object *object)
{
	t_intersect	*intersection;

	intersection = (t_intersect *)malloc(sizeof(t_intersect));
	if (!intersection)
		return (NULL);
	intersection->time = time;
	intersection->object = object;
	intersection->next = NULL;
	return (intersection);
}

void	intersection_sorted_insert(t_intersect **head, t_intersect *new)
{
	t_intersect	*tmp;

	if (!*head || new->time < (*head)->time)
	{
		new->next = *head;
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next && tmp->next->time < new->time)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
}

size_t	intersection_list_size(t_intersect *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		++size;
	}
	return (size);
}

void	intersection_list_clear(t_intersect **list)
{
	t_intersect	*tmp;

	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
