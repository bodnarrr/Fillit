/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bigmatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:10:27 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/26 00:41:11 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

char		**ft_make_bigmatrix(int size, t_tetr *head)
{
	char	**matrix;
	size_t	i;
	size_t	j;

	if (!(matrix = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (head)
	{
		j = 0;
		while ((head->matrix)[j])
			matrix[i++] = (head->matrix)[j++];
		free((char *)(head->matrix));
		head->matrix = NULL;
		head = head->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
