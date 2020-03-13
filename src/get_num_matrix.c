/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:45:31 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/13 22:49:14 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**fill_num_matrix(t_fdf *tmp, char **ar, int **m, char *file)
{
	int		fd;
	char	**line;
	int		row;
	int		col;

	row = 0;
	fd = open(file, O_RDONLY);
	line = (char **)ft_memalloc(sizeof(char *));
	while (get_next_line(fd, line) > 0)
	{
		m[row] = (int *)ft_memalloc(sizeof(int) * tmp->w);
		ar = ft_strsplit(*line, ' ');
		ft_strdel(line);
		col = 0;
		while (ar[col])
		{
			m[row][col] = ft_atoi(ar[col]);
			col += 1;
		}
		row += 1;
		wipe_mstr(ar);
	}
	close(fd);
	ft_strdel(line);
	return (m);
}

void	free_line_ar(char **line, char **ar)
{
	ft_strdel(line);
	wipe_mstr(ar);
}

void	get_width_and_heigth(t_fdf *tmp, char **ar, char *file)
{
	int		w;
	int		h;
	int		fd;
	char	**line;

	w = 0;
	h = 0;
	tmp->w = 0;
	line = (char **)ft_memalloc(sizeof(char *));
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
		ar = ft_strsplit(*line, ' ');
		while (ar[w])
			w += 1;
		if (tmp->w == 0)
			tmp->w = w;
		if (tmp->w != w)
			exit(1);
		free_line_ar(line, ar);
		h += 1;
	}
	tmp->h = h;
	close(fd);
	ft_strdel(line);
}

int		**get_num_matrix(t_fdf *tmp, char *file)
{
	char	**ar;
	int		**m;

	ar = NULL;
	get_width_and_heigth(tmp, ar, file);
	tmp->scale = 20;
	tmp->win_x = 21 * tmp->w;
	tmp->win_y = 21 * tmp->h;
	m = (int **)ft_memalloc(sizeof(int *) * (tmp->h + 1));
	m[tmp->h] = NULL;
	m = fill_num_matrix(tmp, ar, m, file);
	return (m);
}
