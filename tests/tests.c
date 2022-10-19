/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/19 15:34:09 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity/unity.h"
#include "tests.h"

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
	UNITY_BEGIN();
	test_tuple_operations();
	test_colors();
	pre_parser_errors();
	test_atod();
	test_check_light();
	test_check_ambient();
	test_check_camera();
	return (UNITY_END());
}
