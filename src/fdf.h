/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:45:20 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/12 05:36:26 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"

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
	int		is_iso;
	double	angle;
	int		menu;
	int		back;
	int		scale;
	int		scale_default;
	int		z_scale;
	int		shift_x;
	int		shift_y;
	void	*win_ptr;
	void	*mlx_ptr;
}						t_fdf;

int						**get_num_matrix(t_fdf *tmp, char *file);
void					print_background(t_fdf **m);
void					set_default(t_fdf **m);
void					set_param(t_fdf *a, t_fdf *b, t_fdf **m);
void					set_start_param(t_fdf **m_struct, t_fdf tmp, \
															char **argv);
void					draw_struct(t_fdf **m_struct);
void					do_key(int key, t_fdf **matrix);
void					free_m_struct(t_fdf **m_struct);
void					free_m_num(int **m_num);
t_fdf					**get_struct_mtrx(t_fdf *tmp, int **m_num);

#endif
