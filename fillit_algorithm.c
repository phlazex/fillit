/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:18:40 by mfahey            #+#    #+#             */
/*   Updated: 2019/03/04 17:39:35 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_srch_scnd(char *map, t_tetr *root, size_t lines)
{
	size_t	i;
	size_t	count;
	t_coord	*p;

	p = &root->a;
	count = 0;
	while (count < 4)
	{
		i = p->x + p->y * (lines + 1);
		if (i >= (lines * (lines + 1)) || map[i] != '.')
			break ;
		count++;
		if (count < 4)
			p++;
	}
	if (count == 4)
		return (1);
	return (0);
}

void	ft_bld(char *map, t_tetr *root, size_t lines, int c)
{
	size_t	count;
	t_coord *p;

	p = &root->a;
	count = 0;
	while (count < 4)
	{
		map[p->x + p->y * (lines + 1)] = c;
		count++;
		if (count < 4)
			p++;
	}
}

void	ft_srch(char *map, t_tetr *root, size_t lines, size_t k)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (i < k)
		if ((ft_srch_scnd(map, root + i, lines)) != 0)
		{
			ft_bld(map, root + i, lines, i + 65);
			i++;
		}
		else
			while ((z = ft_mv(root + i, lines)) == 1)
				if (i > 0)
				{
					--i;
					ft_bld(map, root + i, lines, '.');
				}
				else if (i == 0)
				{
					calculate_square(&map, ++lines);
					break ;
				}
	ft_putstr(map);
	ft_strdel(&map);
}
