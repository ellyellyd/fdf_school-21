/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 00:32:30 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/11 00:35:00 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_key(int key, t_fdf **matrix)
{
	if (key == 11)
	{
		if (matrix[0][0].back == 0)
			matrix[0][0].back = 1;
		else
			matrix[0][0].back = 0;
	}
	if (key == 2 && matrix[0][0].z_scale > (-1) * (matrix[0][0].win_y / matrix[0][0].scale))
		matrix[0][0].z_scale -= 1;
	if (key == 32 && matrix[0][0].z_scale < matrix[0][0].win_y / matrix[0][0].scale)
		matrix[0][0].z_scale += 1;
	if (key == 24)
		matrix[0][0].scale += 1;
	if (key == 27)
		matrix[0][0].scale -= 1;
	if (key == 124 && matrix[0][0].win_x >= matrix[0][0].shift_x + 3)
		matrix[0][0].shift_x += 3;
	if (key == 123 &&  matrix[0][0].shift_x - 3 > 0)
		matrix[0][0].shift_x -= 3;
	if (key == 125 && matrix[0][0].win_y >= matrix[0][0].shift_y + 3)
		matrix[0][0].shift_y += 3;
	if (key == 126 && matrix[0][0].shift_y - 3 > 0)
		matrix[0][0].shift_y -= 3;
	if (key == 46 || key == 49)
	{
		if (key == 49)
		{
			if (matrix[0][0].is_iso == 0)
				matrix[0][0].is_iso = 1;
			else
				matrix[0][0].is_iso = 0;
		}
		if (key == 46)
		{
			if (matrix[0][0].menu == 0)
			{
				matrix[0][0].menu = 1;
				matrix[0][0].shift_x = matrix[0][0].win_x / 2;
			}
			else
			{
				matrix[0][0].menu = 0;
				if (matrix[0][0].is_iso == 0)
					matrix[0][0].shift_x = matrix[0][0].win_x / 3;
			}
		}
	}
	if (key == 15)
		set_default(matrix);
	if (key == 17)
		matrix[0][0].angle += 0.1;
	if (key == 1)
		matrix[0][0].angle -= 0.1;
}

