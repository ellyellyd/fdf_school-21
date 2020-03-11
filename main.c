/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:44:58 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/11 04:52:32 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
