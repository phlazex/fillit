/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:06:26 by kreilly           #+#    #+#             */
/*   Updated: 2019/03/05 15:19:28 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
		ft_exit(1);
}

int		ft_bufftostr(char *buff, char **str)
{
	char	*tmp;

	tmp = NULL;
	if (*str == NULL)
	{
		if ((*str = ft_strdup(buff)) == NULL)
			return (-1);
	}
	else
	{
		if ((tmp = ft_strdup(*str)) == NULL)
			return (-1);
		ft_strdel(str);
		if ((*str = ft_strjoin(tmp, buff)) == NULL)
			return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

char	*ft_read(int fd)
{
	int		ret;
	int		x;
	char	buff[BUFF_SIZE + 1];
	char	*str;

	str = NULL;
	x = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		x++;
		if ((ft_bufftostr(buff, &str)) == -1)
			ft_exit(1);
	}
	if ((ret == 0) && (x == 0))
		ft_exit(1);
	return (str);
}

int		ft_open(char *fn)
{
	int		fd;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		ft_exit(1);
	return (fd);
}
