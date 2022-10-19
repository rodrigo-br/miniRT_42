/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:40:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 15:57:07 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	check_ambient_light_ratio(char *s)
{
	double	ratio;

	if (!ft_is_a_double(s))
		return (EXIT_FAILURE);
	ratio = ft_atod(s);
	if (ratio < 0.0 || ratio > 1.0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_ambience	*set_ambient(char *s, char **rgb)
{
	t_ambience	*ambience;

	ambience = (t_ambience *)malloc(sizeof(t_ambience));
	if (!ambience)
		return (NULL);
	ambience->ratio = ft_atod(s);
	ambience->rgb = create_color(ft_atoi(rgb[0]), \
								ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_matrix((void *)&rgb);
	return (ambience);
}

int	check_ambient(char **line_splited, t_ambience **ambience)
{
	char		**rgb;
	int			errors;

	if (ft_get_matrix_len(line_splited) != 3)
		return (EXIT_FAILURE);
	errors = check_ambient_light_ratio(line_splited[1]);
	rgb = check_rgb(line_splited[2]);
	if (!rgb)
		errors = 1;
	if (errors)
		return (EXIT_FAILURE);
	*ambience = set_ambient(line_splited[1], rgb);
	if (!(*ambience))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
