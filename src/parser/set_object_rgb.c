/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:27:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 10:27:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_object_rgb(t_object *object, char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(s, ',');
	if (check_rgb_digits(rgb, &red, &green, &blue))
		return (EXIT_FAILURE);
	object->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	object->rgb->opacity = 255;
	object->rgb->red = red;
	object->rgb->green = green;
	object->rgb->blue = blue;
	return (EXIT_SUCCESS);
}
