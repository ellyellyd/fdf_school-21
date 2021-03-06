/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:10:56 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/12 00:45:45 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_fdf **m, t_fdf a, t_fdf b)
{
	int		color;

	if (m[0][0].back == 0)
	{
		color = (b.z || a.z) ? 0xe1d9fc : 0x658f9b;
		color = (b.z != a.z) ? 0xf9f1fd : color;
	}
	else
	{
		color = (b.z || a.z) ? 0xdde2e3 : 0xb37c57;
		color = (b.z != a.z) ? 0x9aacb8 : color;
	}
	return (color);
}

int		module(float nb)
{
	return ((nb < 0) ? -nb : nb);
}

void	draw_line_bres(t_fdf a, t_fdf b, t_fdf **m)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, m);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = (module(step_x) > module(step_y)) ? module(step_x) : module(step_y);
	step_x /= max;
	step_y /= max;
	color = get_color(m, a, b);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(m[0][0].mlx_ptr, m[0][0].win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > m[0][0].win_x || a.y > m[0][0].win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_struct(t_fdf **m)
{
	int		row;
	int		x;

	row = 0;
	while (row < m[0][0].h)
	{
		x = 0;
		while (x < m[0][0].w - 1)
		{
			if (m[row + 1])
				draw_line_bres(m[row][x], m[row + 1][x], m);
			draw_line_bres(m[row][x], m[row][x + 1], m);
			x++;
		}
		if (m[row + 1])
			draw_line_bres(m[row][x], m[row + 1][x], m);
		row++;
	}
}
