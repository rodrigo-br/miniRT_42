/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:46:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/03 16:37:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_NO_EXT "Given file has no extension."
#define ERR_WRONG_EXT "Given file has wrong extension."
#define ERR_UNDEF_AMB "Undefined ambient."
#define ERR_UNDEF_CAM "Undefined camera."
#define ERR_UNDEF_LGT "Undefined light."
#define ERR_UNDEF_OBJ "At least one object is required."

int	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension)
		return (error(ERR_NO_EXT));
	else if (ft_strcmp(".rt", extension) != 0)
		return (error(ERR_WRONG_EXT));
	return (0);
}

int	check_scene_elements(t_rt_scene *s)
{
	int	status;

	status = 0;
	if (!s->ambient)
		status += error(ERR_UNDEF_AMB);
	if (!s->camera)
		status += error(ERR_UNDEF_CAM);
	if (!s->light)
		status += error(ERR_UNDEF_LGT);
	if (!s->objects)
		status += error(ERR_UNDEF_OBJ);
	return (status);
}

int	check_vector_normalization(double x, double y, double z)
{
	if (!is_equal_double(1.0, magnitude(&(t_vector){x, y, z, 0})))
		return (-1);
	return (0);
}
