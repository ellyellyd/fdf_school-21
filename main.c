/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:44:58 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/10 22:26:30 by fcatina          ###   ########.fr       */
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

void  set_param(t_fdf *a, t_fdf *b, t_fdf **m)
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

int   module(float nb)
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

//
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

int		is_key(int key)
{
  return (key == 32 || key == 24 || key == 27 ||\
      key == 124 || key == 123 || key == 126 ||\
      key == 125 || key == 49 || key == 2 ||\
	  key == 46 || key == 11 || key == 15 ||\
	  key == 17 || key == 1);
}

int		deal_key(int key, t_fdf **mtrx)
{
  printf("key = %d\n", key);//check
  if (is_key(key))
  {
    mlx_clear_window(mtrx[0][0].mlx_ptr, mtrx[0][0].win_ptr);
    do_key(key, mtrx);
    print_background(mtrx);
    draw_struct(mtrx);
  }
  if (key == 53)
  {
    mlx_destroy_window(mtrx[0][0].mlx_ptr, mtrx[0][0].win_ptr);
    free (mtrx);
    exit(0);
  }
  return (key);
}

//
void	fill_mtrx(t_fdf *tmp, int **line, t_fdf **matrix, int row)
{
	int		x;

	x = 0;
	while (x <= tmp->w - 1)
	{
		matrix[row][x].x = x;
		matrix[row][x].y = row;
		matrix[row][x].z = line[row][x];
		x++;
	}
}

t_fdf	**get_struct_mtrx(t_fdf *tmp, int **m_num)
{
	t_fdf	**mtrx;
	int		row;

	mtrx = (t_fdf **)malloc(sizeof(t_fdf *) * (tmp->h + 1));
	mtrx[tmp->h] = NULL;
	row = 0;
	while (row < tmp->h)
		mtrx[row++] = (t_fdf *)malloc(sizeof(t_fdf) * (tmp->w + 1));
	row = 0;
	while (m_num[row])
	{
		fill_mtrx(tmp, m_num, mtrx, row);
		row++;
	}
	return (mtrx);
}


int		main(int argc, char **argv)
{
	int			**m_num;
	t_fdf		tmp;
	t_fdf		**m_struct;
  int     i;
    
	if (argc != 2)
	{
	 	ft_putstr("usage: ./fdf map.fdf\n");
	 	return (0);
	}
	m_num = get_num_matrix(&tmp, argv[1]);
	m_struct = get_struct_mtrx(&tmp, m_num);
  i = 0;
  while(m_num[i])
  {
    free(m_num[i]);
    m_num[i] = NULL;
    i++;
  }
  free(m_num);
  m_num = NULL;
	m_struct[0][0].h = tmp.h;
	m_struct[0][0].w = tmp.w;

	m_struct[0][0].win_y = (tmp.h * 42 > 800) ? 700 : tmp.h * 42;
	m_struct[0][0].win_x = (tmp.w * 42 > 800) ? 1000 : tmp.w * 42;

	while ((m_struct[0][0].win_x / 2 < tmp.w * tmp.scale) || (m_struct[0][0].win_y / 3 < tmp.h * tmp.scale))
		tmp.scale--;
	m_struct[0][0].scale_default = tmp.scale;

  m_struct[0][0].mlx_ptr = mlx_init();
  m_struct[0][0].win_ptr = mlx_new_window(m_struct[0][0].mlx_ptr, m_struct[0][0].win_x, m_struct[0][0].win_y, argv[1]);

  m_struct[0][0].menu = 1;
  m_struct[0][0].is_iso = 0;
  m_struct[0][0].back = 0;

  set_default(m_struct);//new

  print_background(m_struct);
  draw_struct(m_struct);
  mlx_key_hook(m_struct[0][0].win_ptr, deal_key, m_struct);
  mlx_loop(m_struct[0][0].mlx_ptr);
  i = 0;
  while(m_struct[i])
  {
    free(m_struct[i]);
    m_struct[i] = NULL;
    i++;
  }
  free(m_struct);
  m_struct = NULL;
  return (0);
} 
