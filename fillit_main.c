/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:48:54 by kreilly           #+#    #+#             */
/*   Updated: 2019/03/07 16:39:02 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_exit(int a)
{
	if (a > 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

static void		fillit(int fd)
{
	t_tetr	*root;
	char	*str;
	char	*square;
	size_t	quant;
	size_t	xy;

	root = NULL;
	square = NULL;
	str = ft_read(fd);
	quant = ft_vld(str);
	if (!(root = (t_tetr *)malloc(sizeof(t_tetr) * quant)))
		ft_exit(1);
	fill_coords(str, &root->a, &(root + quant - 1)->d, quant);
	ft_strdel(&str);
	change_coords(&root->a, &(root + quant - 1)->d, quant);
	xy = calculate_line_of_square(&root->a, quant);
	calculate_square(&square, xy);
	ft_srch(square, root, xy, quant);
	ft_putchar('\n');
	free(root);
	root = NULL;
}

int				main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc == 2)
	{
		fd = ft_open(argv[1]);
		fillit(fd);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	ft_close(fd);
	return (0);
}
