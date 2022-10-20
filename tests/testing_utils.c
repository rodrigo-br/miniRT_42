/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:29:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/20 14:30:41 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

double double_rand()
{
	return ((double)rand() / RAND_MAX * 40.0 - 20.0);
}

int	decode_rgba(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + ((b & 0xFF)));
}
