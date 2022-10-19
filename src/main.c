/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:23:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/19 13:36:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(void)
{
	t_scene scene;

	ft_bzero(&scene, sizeof(t_scene));
	ft_putstr_fd("Brace yourself, a cool miniRT is coming", 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
