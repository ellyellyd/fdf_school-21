#include "fdf.h"
#include "unistd.h"//check

/*
void	draw_3d_mtrx(t_fdf **mtrx)
{
}
*/

void	join_dots_in_col(t_fdf **m, int row, int x)
{
  int		row2;

  row2 = 0;
  while (row2 < m[0][0].scale)
  {
  //  printf("%d\n", m[0][0].scale);//check
    mlx_pixel_put(m[0][0].mlx_ptr, m[0][0].win_ptr, x + m[0][0].shift_x, row + row2 + m[0][0].shift_y, m[0][0].color);
    row2++;
  }
}

void	join_dots_in_line(t_fdf **m, int row, int x)
{
  int		x2;

  x2 = 0;
  while (x2 <= m[0][0].scale)
  {
    mlx_pixel_put(m[0][0].mlx_ptr, m[0][0].win_ptr, x + x2 + m[0][0].shift_x, (row * m[0][0].scale) + m[0][0].shift_y, m[0][0].color);
    x2++;
  }
}

void	join_dots(t_fdf **mtx, int row)
{
  int		x;

  x = 0;
  if (row < mtx[0][0].h - 1)
  {
	  while (x < mtx[0][0].w - 1)
	  {
		if (mtx[row][x].z != 0 || ((x + 1) < mtx[0][0].w && mtx[row][x + 1].z != 0))
		  mtx[0][0].color = 0xFFD8D9;
		else
		  mtx[0][0].color = 0xB43864;
		join_dots_in_line(mtx, row, x * mtx[0][0].scale);
		if (mtx[row][x].z != 0 || (mtx[row + 1] && mtx[row + 1][x].z != 0))
		  mtx[0][0].color = 0xFFD8D9;
		else
		  mtx[0][0].color = 0xB43864;
		join_dots_in_col(mtx, row * mtx[0][0].scale, x * mtx[0][0].scale);
		x++;
	  }
	  if (row < mtx[0][0].h - 1)
		join_dots_in_col(mtx, row * mtx[0][0].scale, x * mtx[0][0].scale);
  }
  join_dots_in_line(mtx, row, 0 * mtx[0][0].scale);
}

void	draw_struct(t_fdf **m_struct)
{
  int		row;

  row = 0;
  while (row < m_struct[0][0].h)
  {
	 join_dots(m_struct, row);
     row++;
  }
}

//
void	do_key(int key, t_fdf **matrix)
{
  if (key == 24)
    matrix[0][0].scale += 1;
  if (key == 27)
    matrix[0][0].scale -= 1;
  if (key == 124)
    matrix[0][0].shift_x += 3;
  if (key == 123)
    matrix[0][0].shift_x -= 3;
  if (key == 125)
    matrix[0][0].shift_y += 3;
  if (key == 126)
    matrix[0][0].shift_y -= 3;
}

int		is_key(int key)
{
  return (key == 24 || key == 27 || key == 124 || key == 123 || key == 126 || key == 125);
}

int		deal_key(int key, t_fdf **mtrx)
{
  printf("key = %d\n", key);//check
  if (is_key(key))
  {
    mlx_clear_window(mtrx[0][0].mlx_ptr, mtrx[0][0].win_ptr);
    do_key(key, mtrx);
    //print menu
    draw_struct(mtrx);
  }
  if (key == 53)
  {
    mlx_destroy_window(mtrx[0][0].mlx_ptr, mtrx[0][0].win_ptr);
    free (mtrx);
    exit(0);
  }
  if (key == 49)
  {
  //	printf("%d, %d\n", (int)mtrx[0][0].mlx_ptr, (int)mtrx[0][0].win_ptr);//check
    mlx_clear_window(mtrx[0][0].mlx_ptr, mtrx[0][0].win_ptr);
	//draw_3d_mtrx(mtrx);//new
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
		matrix[row][x].h = tmp->h;
		matrix[row][x].w = tmp->w;

		matrix[row][x].win_y = tmp->h * 21;
		matrix[row][x].win_x = tmp->w * 21;

		matrix[row][x].scale = tmp->scale;

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
	//ft_strdel(mtrx);
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
  m_struct[0][0].mlx_ptr = mlx_init();
  m_struct[0][0].win_ptr = mlx_new_window(m_struct[0][0].mlx_ptr, m_struct[0][0].win_x, m_struct[0][0].win_y, argv[1]);
  m_struct[0][0].shift_x = 1;
  m_struct[0][0].shift_y = 1;
  draw_struct(m_struct);
 // printf("%d, %d\n", (int)m_struct[0][0].mlx_ptr, (int)m_struct[0][0].win_ptr);//check
  mlx_key_hook(m_struct[0][0].win_ptr, deal_key, m_struct);
  mlx_loop(m_struct[0][0].mlx_ptr);
  return (0);
} 
