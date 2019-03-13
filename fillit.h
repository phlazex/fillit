/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:07 by mfahey            #+#    #+#             */
/*   Updated: 2019/03/05 15:17:07 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# define BUFF_SIZE 21
# include <fcntl.h>

typedef struct	s_coords
{
	size_t x;
	size_t y;
}				t_coord;

typedef struct	s_tetr
{
	t_coord a;
	t_coord b;
	t_coord c;
	t_coord d;
}				t_tetr;

size_t			ft_vld(char *str);
int				ft_vld_frth(char *str);
void			ft_close(int fd);
int				ft_bufftostr(char *buff, char **str);
char			*ft_read(int fd);
int				ft_open(char *fn);
void			print_coords(t_coord *begin, size_t quant);
void			change_coords(t_coord *p, t_coord *end, size_t quant);
void			fill_coords(char *buff, t_coord *c, t_coord *end, size_t quant);
void			ft_exit(int a);
void			calculate_square(char **a, size_t lines);
size_t			calculate_line_of_square(t_coord *a, size_t quant);
void			ft_srch(char *map, t_tetr *root, size_t lines, size_t k);
int				ft_mv(t_tetr *root, size_t lines);

#endif
