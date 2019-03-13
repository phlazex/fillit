/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_second_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:38:03 by mfahey            #+#    #+#             */
/*   Updated: 2019/03/06 14:31:36 by mfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_vld_sxth(char *str, size_t i, size_t k)
{
	size_t	r;

	r = 0;
	if ((k == 1) && (str[i] == str[i + 1]))
		r++;
	if ((k == 1) && (i < 15) && (str[i] == str[i + 5]))
		r++;
	if ((k == 4) && (str[i] == str[i - 1]))
		r++;
	if ((k == 4) && (i >= 5) && (str[i] == str[i - 5]))
		r++;
	if ((k > 1) && (k < 4) && (str[i] == str[i + 1]))
		r++;
	if ((k > 1) && (k < 4) && (str[i] == str[i - 1]))
		r++;
	if ((k > 1) && (k < 4) && (i >= 5) && (str[i] == str[i - 5]))
		r++;
	if ((k > 1) && (k < 4) && (i < 15) && (str[i] == str[i + 5]))
		r++;
	return (r);
}

static size_t	ft_vld_ffth(char *str)
{
	size_t	i;
	size_t	k;
	size_t	r;

	i = 0;
	k = 0;
	r = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			k++;
			r += ft_vld_sxth(str, i, k);
		}
		i++;
	}
	return (r);
}

int				ft_vld_frth(char *str)
{
	size_t	i;
	size_t	r;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n') && (((i + 1) % 21) == 0))
		{
			r = ft_vld_ffth(str + i - 20);
			if ((r != 6) && (r != 8))
				return (-1);
		}
		i++;
	}
	r = ft_vld_ffth(str + i - 20);
	if ((r != 6) && (r != 8))
		return (-1);
	return (0);
}
