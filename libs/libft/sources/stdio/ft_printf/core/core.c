/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:08:52 by maolivei          #+#    #+#             */
/*   Updated: 2022/09/23 00:33:11 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_param(t_output *output, char **format, va_list ap)
{
	t_flags	*flags;
	char	*tmp;
	char	*placeholder;
	int		offset;

	placeholder = *format;
	flags = get_data((placeholder + 1), ap);
	if (!flags)
		return ;
	if (flags->has_error)
	{
		free(flags->str);
		free(flags);
		output->size = -1;
		return ;
	}
	tmp = ft_strjoin(output->str, flags->str);
	free(output->str);
	output->str = tmp;
	output->size += flags->str_len;
	free(flags->str);
	offset = flags->placeholder_len + 1;
	*format += offset;
	free(flags);
}

static void	append_text(t_output *output, char **format)
{
	char	*tmp_str;
	char	*sub_str;
	char	*text;
	int		size;

	text = *format;
	tmp_str = ft_strchr(text, '%');
	if (tmp_str)
		size = tmp_str - text;
	else
		size = ft_strlen(text);
	sub_str = ft_substr(text, 0, size);
	*format = tmp_str;
	tmp_str = output->str;
	output->str = ft_strjoin(output->str, sub_str);
	output->size += size;
	free(tmp_str);
	free(sub_str);
}

t_output	*generate_output(char *format, va_list ap)
{
	t_output	*output;

	output = malloc(sizeof(t_output));
	if (!output)
		return (NULL);
	output->size = 0;
	output->str = (char *)ft_calloc(1, sizeof(char));
	while (TRUE)
	{
		append_text(output, &format);
		if (!format)
			break ;
		join_param(output, &format, ap);
		if (!format)
			break ;
	}
	return (output);
}
