/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:27:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 12:06:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	set_object_rgb(uchar *r, uchar *g, uchar *b, char *s)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	rgb = ft_split(s, ',');
	if (check_rgb_digits(rgb, &red, &green, &blue))
		return (EXIT_FAILURE);
	*r = red;
	*g = green;
	*b = blue;
	return (EXIT_SUCCESS);
}
