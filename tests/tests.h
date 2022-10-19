/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:25:39 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/19 17:44:15 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include <unity/unity.h>
#include <minirt.h>
#include <time.h>

#define LOOP_ITERATIONS 100

void	test_tuple_operations(void);
void	test_colors(void);
void	test_canvas(void);
void	pre_parser_errors(void);
void	test_parser(void);
void	test_check_light(void);
void	test_check_ambient(void);
void	test_check_camera(void);

#endif /* TESTS_H */
