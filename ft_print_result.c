/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:05:35 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/26 01:51:23 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_print_result(char **matrix, int s)
{
	char	*res;
	int		j;
	int		k;

	if ((res = ft_strnew(s * s)) == NULL)
		return ;
	j = -1;
	k = 0;
	while (k < s * s)
		res[k++] = '.';
	res[k] = '\0';
	while (matrix[++j] && (k = -1) == -1)
		while (matrix[j][++k])
			if (matrix[j][k] >= 'A' && matrix[j][k] <= 'Z' && k != 0)
				res[k - 1] = matrix[j][k];
	k = -1;
	while (res[++k])
	{
		if (k % s == 0 && k != 0)
			ft_putchar('\n');
		ft_putchar(res[k]);
	}
	ft_putchar('\n');
	ft_strdel(&res);
}
