/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:32:30 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/12 00:35:55 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_key_2(int key, t_fdf **m)
{
	if (key == 49)
		m[0][0].is_iso = 0 ? m[0][0].is_iso == 1 : m[0][0].is_iso == 0;
	if (key == 46)
	{
		if (m[0][0].menu == 0)
		{
			m[0][0].menu = 1;
			m[0][0].shift_x = m[0][0].win_x / 2;
		}
		else
		{
			m[0][0].menu = 0;
			if (m[0][0].is_iso == 0)
				m[0][0].shift_x = m[0][0].win_x / 3;
		}
	}
	if (key == 11)
	{
		if (m[0][0].back == 0)
			m[0][0].back = 1;
		else
			m[0][0].back = 0;
	}
}

void	do_key(int key, t_fdf **m)
{
	if (key == 2 && m[0][0].z_scale > (-1) * (m[0][0].win_y / m[0][0].scale))
		m[0][0].z_scale -= 1;
	if (key == 32 && m[0][0].z_scale < m[0][0].win_y / m[0][0].scale)
		m[0][0].z_scale += 1;
	if (key == 24)
		m[0][0].scale += 1;
	if (key == 27)
		m[0][0].scale -= 1;
	if (key == 124 && m[0][0].win_x >= m[0][0].shift_x + 3)
		m[0][0].shift_x += 3;
	if (key == 123 && m[0][0].shift_x - 3 > 0)
		m[0][0].shift_x -= 3;
	if (key == 125 && m[0][0].win_y >= m[0][0].shift_y + 3)
		m[0][0].shift_y += 3;
	if (key == 126 && m[0][0].shift_y - 3 > 0)
		m[0][0].shift_y -= 3;
	if (key == 15)
		set_default(m);
	if (key == 17)
		m[0][0].angle += 0.1;
	if (key == 1)
		m[0][0].angle -= 0.1;
	if (key == 46 || key == 49 || key == 11)
		do_key_2(key, m);
}
