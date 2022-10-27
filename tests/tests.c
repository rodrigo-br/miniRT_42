/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/27 17:34:26 by maolivei         ###   ########.fr       */
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
	test_world();
	test_view_transformation();
	test_camera();
	test_shape();
	test_cylinder();
	test_patterns();
	test_cone();
	return (UNITY_END());
}
