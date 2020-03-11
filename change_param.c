/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:40:01 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/11 05:30:52 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_fdf **m)
{
	m[0][0].z_scale = 1;
	m[0][0].angle = 0.523599;
	m[0][0].scale = m[0][0].scale_default;
	m[0][0].shift_x = m[0][0].win_x / 2;
	m[0][0].shift_y = m[0][0].win_y / 3;
}

void	set_start_param(t_fdf **m, t_fdf tmp, char **argv)
{
	m[0][0].h = tmp.h;
	m[0][0].w = tmp.w;
	m[0][0].win_y = (tmp.h * 42 > 800) ? 700 : tmp.h * 42;
	m[0][0].win_x = (tmp.w * 42 > 800) ? 1000 : tmp.w * 42;
	while ((m[0][0].win_x / 2 < tmp.w * tmp.scale) || \
			(m[0][0].win_y / 3 < tmp.h * tmp.scale))
		tmp.scale--;
	m[0][0].scale_default = tmp.scale;
	m[0][0].mlx_ptr = mlx_init();
	m[0][0].win_ptr = mlx_new_window(m[0][0].mlx_ptr, \
			m[0][0].win_x, m[0][0].win_y, argv[1]);
	m[0][0].menu = 1;
	m[0][0].is_iso = 0;
	m[0][0].back = 0;
	set_default(m);
}

void	set_param(t_fdf *a, t_fdf *b, t_fdf **m)
{
	a->x *= m[0][0].scale;
	a->y *= m[0][0].scale;
	b->x *= m[0][0].scale;
	b->y *= m[0][0].scale;
	a->z *= m[0][0].z_scale;
	b->z *= m[0][0].z_scale;
	if (m[0][0].is_iso)
	{
		a->x = (a->x - a->y) * cos(m[0][0].angle);
		a->y = (a->x + a->y) * sin(m[0][0].angle) - a->z;
		b->x = (b->x - b->y) * cos(m[0][0].angle);
		b->y = (b->x + b->y) * sin(m[0][0].angle) - b->z;
	}
	a->x += m[0][0].shift_x;
	a->y += m[0][0].shift_y;
	b->x += m[0][0].shift_x;
	b->y += m[0][0].shift_y;
}
