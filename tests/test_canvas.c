/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:42:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/26 09:34:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	test_canvas_creation(void)
{
	t_canvas	*canvas;

	canvas = create_canvas(500.0, 500.0);
	TEST_ASSERT_NOT_NULL(canvas);
	TEST_ASSERT_NOT_NULL(canvas->image);
	TEST_ASSERT_NOT_NULL(canvas->address);
	destroy_canvas(canvas);
}

void	test_canvas_painting(void)
{
	t_rgb		*rgb;
	t_canvas	*canvas;

	canvas = create_canvas(500.0, 500.0);
	rgb = create_color(255, 0, 0);
	write_to_canvas(canvas, 250, 250, rgb->merged);
	TEST_ASSERT_EQUAL_HEX(0xFF0000, pixel_at(canvas, 250, 250));
	destroy_canvas(canvas);
	free(rgb);
}

void	test_canvas(void)
{
	RUN_TEST(test_canvas_creation);
	RUN_TEST(test_canvas_painting);
}
