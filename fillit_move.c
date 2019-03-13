/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:45:20 by mfahey            #+#    #+#             */
/*   Updated: 2019/03/05 14:53:12 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mv_scnd(int *mn_mx_xy, t_tetr *root, size_t xy)
{
	size_t	i;
	t_coord *p;

	p = &root->a;
	i = 0;
	while (i < 4)
	{
		p->x += mn_mx_xy[4];
		p->y += mn_mx_xy[5];
		i++;
		if (i < 4)
			p++;
	}
	if (((mn_mx_xy[4] < 0) && (mn_mx_xy[5] < 0)) ||
			((mn_mx_xy[2] == (int)(xy - 1)) && (mn_mx_xy[3]) == (int)(xy - 1)))
		return (1);
	return (0);
}

int		ft_mv_frst(int *mn_mx_xy, t_tetr *root, size_t xy)
{
	if ((mn_mx_xy[2] == (int)(xy - 1)) && (mn_mx_xy[3] == (int)(xy - 1)))
	{
		mn_mx_xy[4] = -mn_mx_xy[0];
		mn_mx_xy[5] = -mn_mx_xy[1];
	}
	else if (mn_mx_xy[2] == (int)(xy - 1))
	{
		mn_mx_xy[4] = -mn_mx_xy[0];
		mn_mx_xy[5] += 1;
	}
	else
	{
		mn_mx_xy[4] += 1;
		mn_mx_xy[5] = 0;
	}
	if ((ft_mv_scnd(mn_mx_xy, root, xy)) == 1)
		return (1);
	return (0);
}

int		ft_mv(t_tetr *root, size_t lines)
{
	int		arr[6];
	t_coord *p;

	p = &root->a;
	arr[0] = (int)ft_min(ft_min(((long long)p->x), ((long long)((p + 1)->x))),
			ft_min(((long long)((p + 2)->x)), ((long long)((p + 3)->x))));
	arr[1] = (int)ft_min(ft_min(((long long)p->y), ((long long)((p + 1)->y))),
			ft_min(((long long)((p + 2)->y)), ((long long)((p + 3)->y))));
	arr[2] = (int)ft_max(ft_max(((long long)p->x), ((long long)((p + 1)->x))),
			ft_max(((long long)(p + 2)->x), (long long)(p + 3)->x));
	arr[3] = (int)ft_max(ft_max(((long long)(p->y)), ((long long)((p + 1)->y))),
			ft_max((long long)((p + 2)->y), (long long)((p + 3)->y)));
	arr[4] = 0;
	arr[5] = 0;
	if ((ft_mv_frst(arr, root, lines)) == 1)
		return (1);
	return (0);
}
