/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:24:16 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	setUp(void)
{
	// set stuff up here
}

void	tearDown(void)
{
	// clean stuff up here
}

int	main(void)
{
	srand(time(NULL));
	UNITY_BEGIN();
	test_tuple_operations();
	test_colors();
	test_canvas();
	test_atod();
	test_check_light();
	test_check_ambient();
	test_check_camera();
	test_check_cylinder();
	test_check_plane();
	test_check_sphere();
	test_parser();
	test_matrix();
	test_transformations();
	test_ray();
	test_light_and_shading();
	return (UNITY_END());
}
