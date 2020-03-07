/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mstr_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 22:55:24 by slisandr          #+#    #+#             */
/*   Updated: 2020/02/05 04:45:49 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_mstr_w(char **m)
{
	if (m && m[0])
		return (ft_strlen(m[0]));
	else
		return (0);
}
