/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:10:56 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/11 00:14:01 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		module(float nb)
{
	return ((nb < 0) ? -nb : nb);
}

void	draw_line_bres(t_fdf a, t_fdf b, t_fdf **m)
{
	float		step_x;
	float   step_y;
	float   max;
	int     color;

	set_param(&a, &b, m);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = (module(step_x) > module(step_y)) ? module(step_x) : module(step_y);
	step_x /= max;
	step_y /= max;
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
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(m[0][0].mlx_ptr, m[0][0].win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > m[0][0].win_x || a.y > m[0][0].win_y || a.y < 0 || a.x < 0)
			break;
	}
}

void	draw_struct(t_fdf **m_struct)
{
	int		row;
	int		x;

	row = 0;
	while (row < m_struct[0][0].h)
	{
		x = 0;
		while (x < m_struct[0][0].w - 1)
		{
			if (m_struct[row + 1])
				draw_line_bres(m_struct[row][x], m_struct[row + 1][x], m_struct);
			draw_line_bres(m_struct[row][x], m_struct[row][x + 1], m_struct);
			x++;
		}
		if (m_struct[row + 1])
			draw_line_bres(m_struct[row][x], m_struct[row + 1][x], m_struct);
		row++;
	}
}

