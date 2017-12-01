/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:28:28 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/26 00:43:26 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <string.h>

char	*ft_fillit(char **matrix, int square, const int fcount, char c)
{
	size_t	row;

	if (matrix == NULL)
		return (NULL);
	if ((row = 0) == 0 && ft_l_counter(matrix) == fcount)
	{
		ft_print_result(matrix, square);
		ft_del_matrix(&matrix);
		return ("OK");
	}
	while (matrix[row] != NULL)
	{
		if (matrix[row][0] != c)
			++row;
		else if (ft_fillit(ft_clear_rows(ft_copy_matrix(matrix), row), \
					square, fcount, c + 1) == NULL && matrix[row][0] == c)
			++row;
		else
		{
			ft_del_matrix(&matrix);
			return ("OK");
		}
	}
	ft_del_matrix(&matrix);
	return (NULL);
}
