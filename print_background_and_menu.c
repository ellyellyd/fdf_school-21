/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background_and_menu.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:46:37 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/12 01:35:54 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu_2(t_fdf **m, int color)
{
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 175, color, "height (rise/low):");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 195, color, "				U D");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 215, color, "change colors: B");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 245, color, "set default pic: R");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 265, color, "rotate: T S");
}

void	print_menu(t_fdf **m)
{
	int		color;

	if (m[0][0].back == 1)
		color = 0xb37c57;
	else
		color = 0x9f94f0;
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 0, color, "exit : esc");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 30, color, "hide / show menu: M");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 60, color, "move picture:");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 75, color, "	use arrows(<- ->)");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 105, color, "zoom: + -");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 125, color, "change proection:");
	mlx_string_put(m[0][0].mlx_ptr, m[0][0].win_ptr,\
			10, 145, color, "			space");
	print_menu_2(m, color);
}

void	print_back_menu(t_fdf **m, int *x, int *y, int *color)
{
	if (m[0][0].back == 1)
		*color = 0x9aacb8;
	else
		*color = 0x516c97;
	while (*x <= m[0][0].win_x / 4 || *x <= 199)
	{
		mlx_pixel_put(m[0][0].mlx_ptr, m[0][0].win_ptr, *x, *y, *color);
		(*x)++;
	}
}

void	print_background(t_fdf **m)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y <= m[0][0].win_y)
	{
		x = 0;
		if (m[0][0].menu == 1)
		{
			print_back_menu(m, &x, &y, &color);
			print_menu(m);
		}
		if (m[0][0].back == 1)
		{
			while (x <= m[0][0].win_x)
			{
				mlx_pixel_put(m[0][0].mlx_ptr, m[0][0].win_ptr, x, y, 0x3c455c);
				x++;
			}
		}
		y++;
	}
}
