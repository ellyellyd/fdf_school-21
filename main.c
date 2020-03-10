/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:44:58 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/11 00:14:46 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	free_m_struct(t_fdf **m_struct)
{
  int     i;

  i = 0;
  while(m_struct[i])
  {
    free(m_struct[i]);
    m_struct[i] = NULL;
    i++;
  }
  free(m_struct);
  m_struct = NULL;
}

void	free_m_num(int **m_num)
{
  int     i;

  i = 0;
  while(m_num[i])
  {
    free(m_num[i]);
    m_num[i] = NULL;
    i++;
  }
  free(m_num);
  m_num = NULL;
}

int		main(int argc, char **argv)
{
	int			**m_num;
	t_fdf		tmp;
	t_fdf		**m_struct;
    
	if (argc != 2)
	{
	 	ft_putstr("usage: ./fdf map.fdf\n");
	 	return (0);
	}
	m_num = get_num_matrix(&tmp, argv[1]);
	m_struct = get_struct_mtrx(&tmp, m_num);
	free_m_num(m_num);
	set_start_param(m_struct, tmp, argv);
	print_background(m_struct);
	draw_struct(m_struct);
	mlx_key_hook(m_struct[0][0].win_ptr, deal_key, m_struct);
	mlx_loop(m_struct[0][0].mlx_ptr);
	free_m_struct(m_struct);
	return (0);
} 
