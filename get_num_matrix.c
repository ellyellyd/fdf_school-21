#include "fdf.h"

int		**get_num_matrix(t_fdf *tmp, char *file)
{
	int		w;
	int		h;
	char	**line;
	char	**ar;
	int		**m;
	int		row;
	int		col;
	int		fd;

	w = 0;
	h = 0;
	line = (char **)ft_memalloc(sizeof(char *));
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
		if (w == 0)
		{
			ar = ft_strsplit(*line, ' ');
			while (ar[w])
				w += 1;
		}
		h += 1;
	}
	printf("h = %d, w = %d\n", h, w);//check
	tmp->w = w;
	tmp->h = h;
  tmp->scale = 20;
	tmp->win_x = 21 * w;
	tmp->win_y = 21 * h;
	m = (int **)ft_memalloc(sizeof(int *) * (h + 1));
	m[h] = NULL;
	row = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
		m[row] = (int *)ft_memalloc(sizeof(int) * w);
		ar = ft_strsplit(*line, ' ');
		col = 0;
		while (ar[col])
		{
			m[row][col] = ft_atoi(ar[col]);
			printf("%2d ", m[row][col]);
			col += 1;
		}
		row += 1;
		printf("\n");
	}
	close(fd);
	ft_strdel(line);
	return (m);
}
