/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:45:20 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/11 00:14:28 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>//delete soon
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

typedef	struct			s_fdf
{
	int		w;
	int		h;

	float	x;
	float	y;
	float	z;
	int		color;

	int		win_x;
	int		win_y;
  int   is_iso;
  double  angle;
  int     menu;
  int	back;

	int		scale;
	int		scale_default;
  int   z_scale;
  int   shift_x;
  int   shift_y;

	void	*win_ptr;
	void	*mlx_ptr;
}						t_fdf;

int		**get_num_matrix(t_fdf *tmp, char *file);
void	print_background(t_fdf **m);
void	set_default(t_fdf **m);
void	set_param(t_fdf *a, t_fdf *b, t_fdf **m);
void	set_start_param(t_fdf **m_struct, t_fdf tmp, char **argv);
void	draw_struct(t_fdf **m_struct);

# endif
