/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:29:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:01:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

double double_rand()
{
	return ((double)rand() / RAND_MAX * 40.0 - 20.0);
}

double color_rand()
{
	return ((double)rand() / RAND_MAX);
}

int	decode_rgba(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
