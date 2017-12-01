/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:48:55 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/26 18:18:19 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

static char	*ft_fillmatrix_i_vert(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + s + 1 || i == row + 2 * s + 1
			|| i == row + 3 * s + 1)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_fillmatrix_i_hor(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + 2 || i == row + 3 || i == row + 4)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_fillmatrix_sq(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + 2 || i == row + s + 1
			|| i == row + s + 2)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char		**ft_matrix_one(t_tetr *head, int s, size_t j)
{
	char	**matrix;
	int		rows;
	int		i;

	if ((i = -1) == -1 && head->id == 0)
		rows = (s - 1) * (s - 1);
	else
		rows = s * (s - 3);
	if (!(matrix = (char**)malloc(sizeof(char*) * (rows + 1))))
		return (NULL);
	while (++i < s * s)
	{
		if (head->id == 0)
			if (i >= 0 && i <= s * s - s - 2 && i % s >= 0 && i % s <= s - 2)
				matrix[j++] = ft_fillmatrix_sq(s, i, head->name);
		if (head->id == 1)
			if (i >= 0 && i <= s * s - 4 && i % s >= 0 && i % s <= s - 4)
				matrix[j++] = ft_fillmatrix_i_hor(s, i, head->name);
		if (head->id == 2 && (i >= 0 && i <= s * s - 3 * s - 1))
			matrix[j++] = ft_fillmatrix_i_vert(s, i, head->name);
	}
	matrix[j] = NULL;
	return (matrix);
}
