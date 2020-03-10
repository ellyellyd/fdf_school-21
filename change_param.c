/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:40:01 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/10 23:55:54 by fcatina          ###   ########.fr       */
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

void 	set_param(t_fdf *a, t_fdf *b, t_fdf **m)
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
