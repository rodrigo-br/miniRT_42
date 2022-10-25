/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_view_transformation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:18:19 by maolivei          #+#    #+#             */
/*   Updated: 2022/10/25 18:34:22 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

/* Scenario: The transformation matrix for the default orientation
Given from ← point(0, 0, 0)
And to ← point(0, 0, -1)
And up ← vector(0, 1, 0)
When t ← view_transform(from, to, up)
Then t = identity_matrix */
void	test_default_orientation(void)
{
	t_matrix	*id, *dfl;
	t_point		*from, *to;
	t_vector	*up;

	from = create_point(0, 0, 0);
	to = create_point(0, 0, -1);
	up = create_vector(0, 1, 0);
	id = create_identity_matrix();
	dfl = view_transform(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(id, dfl));
	free(from);
	free(to);
	free(up);
	free(id);
	free(dfl);
}

/* Scenario: A view transformation matrix looking in positive z direction
Given from ← point(0, 0, 0)
And to ← point(0, 0, 1)
And up ← vector(0, 1, 0)
When t ← view_transform(from, to, up)
Then t = scaling(-1, 1, -1) */
void	test_positive_z_direction(void)
{
	t_matrix	*sc, *vt;
	t_point		*from, *to;
	t_vector	*up;

	from = create_point(0, 0, 0);
	to = create_point(0, 0, 1);
	up = create_vector(0, 1, 0);
	sc = scale_matrix(-1, 1, -1);
	vt = view_transform(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(sc, vt));
	free(from);
	free(to);
	free(up);
	free(sc);
	free(vt);
}

/* Scenario: The view transformation moves the world
Given from ← point(0, 0, 8)
And to ← point(0, 0, 0)
And up ← vector(0, 1, 0)
When t ← view_transform(from, to, up)
Then t = translation(0, 0, -8) */
void	test_transformation_moves_the_world(void)
{
	t_matrix	*ts, *vt;
	t_point		*from, *to;
	t_vector	*up;

	from = create_point(0, 0, 8);
	to = create_point(0, 0, 0);
	up = create_vector(0, 1, 0);
	ts = translate_matrix(0, 0, -8);
	vt = view_transform(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(ts, vt));
	free(from);
	free(to);
	free(up);
	free(ts);
	free(vt);
}

/* Scenario: An arbitrary view transformation
Given from ← point(1, 3, 2)
And to ← point(4, -2, 8)
And up ← vector(1, 1, 0)
When t ← view_transform(from, to, up)
Then t is the following 4x4 matrix:
| -0.50709 | 0.50709 | 0.67612 | -2.36643 |
| 0.76772 | 0.60609 | 0.12122 | -2.82843 |
| -0.35857 | 0.59761 | -0.71714 | 0.00000 |
| 0.00000 | 0.00000 | 0.00000 | 1.00000 | */
void	test_arbitrary_view_transformation(void)
{
	double		aux[MAT_MAX][MAT_MAX] = {
		{ -0.50709, 0.50709, 0.67612, -2.36643 },
		{ 0.76772, 0.60609, 0.12122, -2.82843 },
		{ -0.35857, 0.59761, -0.71714, 0.00000 },
		{ 0.00000, 0.00000, 0.00000, 1.00000 }
	};
	t_matrix	*ar, *vt;
	t_point		*from, *to;
	t_vector	*up;

	from = create_point(1, 3, 2);
	to = create_point(4, -2, 8);
	up = create_vector(1, 1, 0);
	ar = create_matrix(4, aux);
	vt = view_transform(from, to, up);
	TEST_ASSERT_TRUE(is_equal_matrix(ar, vt));
	free(from);
	free(to);
	free(up);
	free(ar);
	free(vt);
}

void	test_view_transformation(void)
{
	RUN_TEST(test_default_orientation);
	RUN_TEST(test_positive_z_direction);
	RUN_TEST(test_transformation_moves_the_world);
	RUN_TEST(test_arbitrary_view_transformation);
}
