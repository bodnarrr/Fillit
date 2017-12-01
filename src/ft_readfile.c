/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 06:57:13 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/26 03:53:06 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
**	Function checks the size of read tetrimino.
*/

static int		ft_verify_size(char *buf, int ret)
{
	if (ret == 20)
		return (0);
	else if (ret == 21 && buf[20] == '\n')
	{
		buf[20] = '\0';
		return (0);
	}
	return (1);
}

/*
**	Function checks the validity of characters in the tetrimino.
*/

static int		ft_check_chars(const char *tetrimino)
{
	size_t	i;

	i = 0;
	while (i < 20)
	{
		if (((i % 5) != 4 && \
				!ISVALID_ELEM(tetrimino[i])) || \
			((i % 5) == 4 && \
				tetrimino[i] != '\n'))
			return (1);
		i++;
	}
	return (0);
}

/*
**	Function reads one tetrimino at time from the file
*/

static	t_tetr	*ft_read_map(int fd, t_tetr **list, char *buf, char c)
{
	int			ret;
	int			cflag;
	uint8_t		id;

	while ((cflag = 0) == 0)
	{
		if ((ret = read(fd, buf, 21)) == 21)
			cflag = 1;
		if (ft_verify_size(buf, ret) || ft_check_chars(buf) ||
				((id = ft_get_id(buf)) == 42) || c > 'Z')
		{
			ft_tetrdel(list);
			ft_putendl_fd("error", STDOUT_FILENO);
			exit(1);
		}
		else
		{
			ft_tetradd(list, ft_tetrnew(id));
			(*list)->name = c++;
			if (cflag == 0)
				break ;
		}
	}
	return (*list);
}

/*
** Function set up variables for ft_read_map
*/

t_tetr			*ft_readfile(const char *file_name)
{
	int		fd;
	t_tetr	*list;
	char	buf[22];

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putendl_fd("error", STDOUT_FILENO);
		exit(1);
	}
	list = NULL;
	list = ft_read_map(fd, &list, buf, 'A');
	close(fd);
	return (list);
}
