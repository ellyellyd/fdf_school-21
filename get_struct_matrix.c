/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:50:25 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/12 01:02:36 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
