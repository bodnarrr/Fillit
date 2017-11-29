/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:34:11 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/26 01:45:10 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_check_input_error(int ac)
{
	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit map.fillit", STDERR_FILENO);
		exit(1);
	}
}

int			main(int ac, char **av)
{
	t_tetr	*list;
	char	**matrix;
	int		square;
	int		fcount;

	ft_check_input_error(ac);
	list = ft_readfile(av[1]);
	square = ft_min_square_size(list, &fcount);
	ft_make_all_matrix(list, square);
	matrix = ft_make_bigmatrix(ft_bigmatrix_size(square, list), list);
	while (ft_fillit(matrix, square, fcount, 'A') == NULL)
	{
		ft_make_all_matrix(list, ++square);
		matrix = ft_make_bigmatrix(ft_bigmatrix_size(square, list), list);
	}
	ft_tetrdel(&list);
	return (0);
}
