/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:18:57 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/26 00:50:11 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_del_matrix(char ***matrix)
{
	size_t i;

	if (matrix != NULL && *matrix != NULL)
	{
		i = 0;
		while ((*matrix)[i] != NULL)
			free((*matrix)[i++]);
		free((char *)*matrix);
		*matrix = NULL;
	}
}
