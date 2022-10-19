/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:27:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 13:16:15 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	**check_rgb(char *s)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(s, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || !ft_is_all_digit(rgb[0])
		|| rgb[3] || !ft_is_all_digit(rgb[1]) || !ft_is_all_digit(rgb[2]))
		return (NULL);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	return (rgb);
}
