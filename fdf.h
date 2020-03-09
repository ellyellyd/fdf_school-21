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

	int		scale;
  int   z_scale;
  int   shift_x;
  int   shift_y;

	void	*win_ptr;
	void	*mlx_ptr;
}						t_fdf;

int		**get_num_matrix(t_fdf *tmp, char *file);

# endif
