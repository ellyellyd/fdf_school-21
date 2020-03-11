/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_m_num_and_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 04:42:54 by fcatina           #+#    #+#             */
/*   Updated: 2020/03/12 00:49:40 by fcatina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_m_struct(t_fdf **m_struct)
{
	int		i;

	i = 0;
	while (m_struct[i])
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
	int		i;

	i = 0;
	while (m_num[i])
	{
		free(m_num[i]);
		m_num[i] = NULL;
		i++;
	}
	free(m_num);
	m_num = NULL;
}
