/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/04 10:23:34 by maolivei         ###   ########.fr       */
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
	return (UNITY_END());
}
