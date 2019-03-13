/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:37:37 by kreilly           #+#    #+#             */
/*   Updated: 2019/03/04 16:49:21 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_coords(char *buff, t_coord *c, t_coord *end, size_t quant)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (quant-- > 0)
	{
		while (y++ < 3)
		{
			while (x++ < 3)
				if (buff[x] == '#')
				{
					c->x = x;
					c->y = y;
					if (c < end)
						c = c + 1;
				}
			buff = buff + 5;
			x = -1;
		}
		*buff ? buff++ : 0;
		y = -1;
		x = -1;
	}
}

void	change_coords(t_coord *p, t_coord *end, size_t quant)
{
	size_t	diff_x;
	size_t	diff_y;
	size_t	count;

	while (quant-- > 0)
	{
		diff_y = p->y;
		diff_x = p->x;
		count = 0;
		while (count++ < 3)
		{
			if ((p + 1)->x < diff_x)
				diff_x = (p + 1)->x;
			p = p + 1;
		}
		p = p - 3;
		count = 0;
		while (count++ < 4)
		{
			p->x = p->x - diff_x;
			p->y = p->y - diff_y;
			if (p < end)
				p = p + 1;
		}
	}
}

size_t	calculate_line_of_square(t_coord *a, size_t quant)
{
	size_t lines;
	size_t n;
	size_t i;
	size_t *p;

	p = &a->x;
	i = 1;
	if (quant <= 2)
	{
		n = *p;
		while (i < quant * 8)
		{
			if (*(p + 1) > n)
				n = *(p + 1);
			p++;
			i++;
		}
		return (n + 1);
	}
	lines = 4;
	quant = quant * 4;
	while (lines * lines < quant)
		lines++;
	return (lines);
}

void	calculate_square(char **a, size_t lines)
{
	size_t	size;
	size_t	i;
	char	*p;
	size_t	count;

	i = 0;
	count = 0;
	size = lines * (lines + 1);
	if (!(p = (char *)malloc(sizeof(char) * size)))
		ft_exit(1);
	if (*a && **a)
		ft_strdel(a);
	*a = p;
	p[size - 1] = '\0';
	while (i < (size - 1))
	{
		if (++count == (lines + 1))
		{
			p[i] = '\n';
			count = 0;
		}
		else
			p[i] = '.';
		i++;
	}
}
