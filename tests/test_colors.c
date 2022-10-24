/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:08:49 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/24 20:17:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	test_color_creation(void)
{
	int		r, g, b;
	t_rgb	*color;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		r = color_rand();
		g = color_rand();
		b = color_rand();
		color = create_color(r, g, b);
		TEST_ASSERT_EQUAL_HEX(
			decode_rgba(to_rgb(r), to_rgb(g), to_rgb(b)),
			color->merged
		);
		free(color);
	}
}

void	test_sum_colors(void)
{
	int		ra, ga, ba, rb, gb, bb;
	t_rgb	*color_a, *color_b, *sum;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		ra = color_rand();
		ga = color_rand();
		ba = color_rand();
		rb = color_rand();
		gb = color_rand();
		bb = color_rand();
		color_a = create_color(ra, ga, ba);
		color_b = create_color(rb, gb, bb);
		sum = sum_color(color_a, color_b);
		TEST_ASSERT_EQUAL_HEX(
			(decode_rgba(to_rgb(ra + rb), to_rgb(ga + gb), to_rgb(ba + bb))),
			sum->merged
		);
		free(color_a);
		free(color_b);
		free(sum);
	}
}

void	test_sub_colors(void)
{
	int		ra, ga, ba, rb, gb, bb;
	t_rgb	*color_a, *color_b, *sub;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		ra = color_rand();
		ga = color_rand();
		ba = color_rand();
		rb = color_rand();
		gb = color_rand();
		bb = color_rand();
		color_a = create_color(ra, ga, ba);
		color_b = create_color(rb, gb, bb);
		sub = sub_color(color_a, color_b);
		TEST_ASSERT_EQUAL_HEX(
			decode_rgba(to_rgb(ra - rb), to_rgb(ga - gb), to_rgb(ba - bb)),
			sub->merged
		);
		free(color_a);
		free(color_b);
		free(sub);
	}
}

void	test_multiply_colors(void)
{
	int		ra, ga, ba, rb, gb, bb;
	t_rgb	*color_a, *color_b, *multiply;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		ra = color_rand();
		ga = color_rand();
		ba = color_rand();
		rb = color_rand();
		gb = color_rand();
		bb = color_rand();
		color_a = create_color(ra, ga, ba);
		color_b = create_color(rb, gb, bb);
		multiply = multiply_color(color_a, color_b);
		TEST_ASSERT_EQUAL_HEX(
			decode_rgba(to_rgb(ra * rb), to_rgb(ga * gb), to_rgb(ba * bb)),
			multiply->merged
		);
		free(color_a);
		free(color_b);
		free(multiply);
	}
}

void	test_scalar_multiply_colors(void)
{
	int		r, g, b, multiplier;
	t_rgb	*color_a, *multiply;

	for (int i = 0; i < LOOP_ITERATIONS; i++)
	{
		r = color_rand();
		g = color_rand();
		b = color_rand();
		multiplier = color_rand();
		color_a = create_color(r, g, b);
		multiply = scalar_multiply_color(color_a, multiplier);
		TEST_ASSERT_EQUAL_HEX(
			decode_rgba(to_rgb(r * multiplier), to_rgb(g * multiplier), to_rgb(b * multiplier)),
			multiply->merged
		);
		free(color_a);
		free(multiply);
	}
}

void	test_colors(void)
{
	RUN_TEST(test_color_creation);
	RUN_TEST(test_sum_colors);
	RUN_TEST(test_sub_colors);
	RUN_TEST(test_multiply_colors);
	RUN_TEST(test_scalar_multiply_colors);
}
