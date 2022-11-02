/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:51:52 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/02 11:30:57 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

#define ERR_OPEN_FAIL "Could not open .rt file"
#define ERR_BAD_ID "Invalid identifier in .rt file."

static t_delegator	*get_parse_function(t_parse_id id)
{
	static t_delegator	*function_table[PARSE_ID_MAX + 1];

	if (function_table[PARSE_ID_MIN])
		return (function_table[id]);
	function_table[PARSE_AMBIENT] = parse_ambient;
	function_table[PARSE_CAMERA] = parse_camera;
	function_table[PARSE_LIGHT] = parse_light;
	function_table[PARSE_SPHERE] = parse_sphere;
	function_table[PARSE_PLANE] = parse_plane;
	function_table[PARSE_CYLINDER] = parse_cylinder;
	return (function_table[id]);
}

static t_parse_id	get_token_id(char *token)
{
	if (ft_strcmp(AMBIENT, token) == 0)
		return (PARSE_AMBIENT);
	if (ft_strcmp(CAMERA, token) == 0)
		return (PARSE_CAMERA);
	if (ft_strcmp(LIGHT, token) == 0)
		return (PARSE_LIGHT);
	if (ft_strcmp(SPHERE, token) == 0)
		return (PARSE_SPHERE);
	if (ft_strcmp(CYLINDER, token) == 0)
		return (PARSE_CYLINDER);
	if (ft_strcmp(PLANE, token) == 0)
		return (PARSE_PLANE);
	return (NONE);
}

static int	parse_rt_file(char *line, t_rt_scene *s)
{
	int			status;
	char		**tokens;
	t_delegator	*parse_function;

	ft_str_swap_set_chr(line, BLANKSPACES, ' ');
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	parse_function = get_parse_function(get_token_id(tokens[0]));
	if (!parse_function)
		return (ft_free_matrix((void *)&tokens), error(ERR_BAD_ID));
	status = parse_function(tokens, s);
	ft_free_matrix((void *)&tokens);
	return (status);
}

int	read_rt_file(char *filename, t_rt_scene *s)
{
	int		file_descriptor;
	char	*current_line;

	if (check_file_extension(filename) != 0)
		return (-1);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor < 0)
		return (perror(ERR_OPEN_FAIL), -1);
	while (TRUE)
	{
		current_line = ft_gnl(file_descriptor, FALSE);
		if (!current_line)
			break ;
		if (!*current_line || *current_line == '#')
		{
			free(current_line);
			continue ;
		}
		if (parse_rt_file(current_line, s) != 0)
			return (free(current_line), -1);
		free(current_line);
	}
	return (check_scene_elements(s));
}
