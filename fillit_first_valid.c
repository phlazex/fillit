/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_first_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:28:08 by mfahey            #+#    #+#             */
/*   Updated: 2019/03/05 16:39:51 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_vld_thrd(char *str)
{
	size_t	i;
	size_t	k;
	size_t	m;

	i = 0;
	k = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			k++;
		if ((str[i] == '\n') && (((i + 1) % 21) == 0) && (k == 4))
		{
			m++;
			k = 0;
		}
		i++;
	}
	if (k == 4)
		m++;
	if (m == ((i + 1) / 21))
		return (0);
	return (-1);
}

static int	ft_vld_scnd(char *str)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n') && (((i + 1) % 21) == 0) &&
				(str[i - 1] == '\n') && (str[i - 6] == '\n') &&
				(str[i - 11] == '\n') && (str[i - 16] == '\n'))
			k++;
		i++;
	}
	if ((str[i] == '\0') && (((i + 1) % 21) == 0) &&
			(str[i - 1] == '\n') && (str[i - 6] == '\n') &&
			(str[i - 11] == '\n') && (str[i - 16] == '\n'))
		k++;
	if (((i + 1) / 21) == k)
		return (0);
	return (-1);
}

static int	ft_vld_frst(char *str)
{
	size_t	i;
	size_t	n;
	size_t	m;

	i = 0;
	n = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		if (str[i] == '#')
			m++;
		i++;
	}
	if (((((n + 1) / 5) == ((i + 1) / 21)) && (((n + 1) % 5) == 0)) &&
			(((m % 4) == 0) && ((m / 4) == ((i + 1) / 21))))
		return (0);
	return (-1);
}

size_t		ft_vld(char *str)
{
	size_t	i;
	size_t	n;

	i = 0;
	while ((str[i] == '.') || (str[i] == '#') || (str[i] == '\n'))
		i++;
	n = (i + 1) / 21;
	if ((str[i] == '\0') && (i >= 20) && (i < 546) && (((i + 1) % 21) == 0) &&
			(ft_vld_frst(str) != -1) && (ft_vld_scnd(str) != -1) &&
			(ft_vld_thrd(str) != -1) && (ft_vld_frth(str) != -1))
		return (n);
	ft_exit(1);
	return (0);
}
