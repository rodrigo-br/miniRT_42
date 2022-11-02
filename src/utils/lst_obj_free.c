/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:10:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/01 20:56:49 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	free_lst_obj(void *_obj)
{
	t_object	*obj;

	obj = (t_object *)_obj;
	// free(obj->rgb);
	free(obj);
}
