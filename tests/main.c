/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:18 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/17 14:56:13 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity/unity.h"
#include <minirt.h>

#define ARBITRARY_X 42
#define ARBITRARY_Y 999
#define ARBITRARY_Z 1337
#define ARBITRARY_W 123

void	setUp(void)
{
	// set stuff up here
}

void	tearDown(void)
{
	// clean stuff up here
}

void	is_tuple_value_correct(void)
{
	t_tuple	*tuple;

	tuple = create_tuple(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z, ARBITRARY_W);
	TEST_ASSERT_EQUAL_INT(tuple->x, ARBITRARY_X);
	TEST_ASSERT_EQUAL_INT(tuple->y, ARBITRARY_Y);
	TEST_ASSERT_EQUAL_INT(tuple->z, ARBITRARY_Z);
	TEST_ASSERT_EQUAL_INT(tuple->w, ARBITRARY_W);
	free(tuple);
}

void	is_point_value_correct(void)
{
	t_point	*point;

	point = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	TEST_ASSERT_EQUAL_INT(point->x, ARBITRARY_X);
	TEST_ASSERT_EQUAL_INT(point->y, ARBITRARY_Y);
	TEST_ASSERT_EQUAL_INT(point->z, ARBITRARY_Z);
	free(point);
}

void	is_vector_value_correct(void)
{
	t_vector	*vector;

	vector = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	TEST_ASSERT_EQUAL_INT(vector->x, ARBITRARY_X);
	TEST_ASSERT_EQUAL_INT(vector->y, ARBITRARY_Y);
	TEST_ASSERT_EQUAL_INT(vector->z, ARBITRARY_Z);
	free(vector);
}

void	is_point_ending_in_one(void)
{
	t_point	*point;

	point = create_point(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	TEST_ASSERT_EQUAL_INT(point->w, 1);
	free(point);
}

void	is_vector_ending_in_zero(void)
{
	t_vector	*vector;

	vector = create_vector(ARBITRARY_X, ARBITRARY_Y, ARBITRARY_Z);
	TEST_ASSERT_EQUAL_INT(vector->w, 0);
	free(vector);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(is_tuple_value_correct);
	RUN_TEST(is_point_value_correct);
	RUN_TEST(is_vector_value_correct);
	RUN_TEST(is_point_ending_in_one);
	RUN_TEST(is_vector_ending_in_zero);
	return (UNITY_END());
}
