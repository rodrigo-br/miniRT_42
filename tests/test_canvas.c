/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:42:58 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/19 18:45:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	test_canvas_creation(void)
{
	void		*mlx;
	t_canvas	*canvas;

	mlx = mlx_init();
	if (!mlx)
		return ;
	canvas = create_canvas(mlx, 500, 500);
	TEST_ASSERT_NOT_NULL(canvas);
	TEST_ASSERT_NOT_NULL(canvas->image);
	TEST_ASSERT_NOT_NULL(canvas->addr);
	mlx_destroy_image(mlx, canvas->image);
	mlx_destroy_display(mlx);
	free(mlx);
	free(canvas);
}

void	test_canvas_painting(void)
{
	void		*mlx;
	char		*pixel;
	t_rgb		*rgb;
	t_canvas	*canvas;

	mlx = mlx_init();
	if (!mlx)
		return ;
	canvas = create_canvas(mlx, 500, 500);
	rgb = create_color(255, 0, 0);
	write_to_canvas(canvas, 250, 250, rgb);
	pixel = canvas->addr + (250 * canvas->line_len) + (250 * (canvas->bpp / 8));
	TEST_ASSERT_EQUAL_HEX(0xFF0000FF, *(int *)pixel);
	mlx_destroy_image(mlx, canvas->image);
	mlx_destroy_display(mlx);
	free(mlx);
	free(rgb);
	free(canvas);
}

void	test_canvas(void)
{
	RUN_TEST(test_canvas_creation);
	RUN_TEST(test_canvas_painting);
}
