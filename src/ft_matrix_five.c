/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:20:30 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/26 18:20:32 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

static char	*ft_fillmatrix_t_hor(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + 2 || i == row + 3
			|| i == row + s + 2)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_fillmatrix_t_hor_rev(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + s || i == row + s + 1
			|| i == row + s + 2)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_fillmatrix_t_vert(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + s + 1 || i == row + s + 2
			|| i == row + 2 * s + 1)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_fillmatrix_t_vert_rev(int s, int row, char name)
{
	int		i;
	char	*line;

	line = (char*)malloc(sizeof(char) * (s * s + 2));
	i = 0;
	while (i < s * s + 1)
	{
		if (i == 0)
			line[i] = name;
		else if (i == row + 1 || i == row + s || i == row + s + 1
			|| i == row + 2 * s + 1)
			line[i] = '1';
		else
			line[i] = '0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char		**ft_matrix_five(t_tetr *head, int s, size_t j)
{
	char	**matrix;
	int		rows;
	int		i;

	rows = (s - 2) * (s - 1);
	if (!(matrix = (char**)malloc(sizeof(char*) * (rows + 1))))
		return (NULL);
	i = -1;
	while (++i < s * s)
	{
		if (head->id == 15)
			if (i >= 0 && i <= s * s - s - 3 && i % s >= 0 && i % s <= s - 3)
				matrix[j++] = ft_fillmatrix_t_hor(s, i, head->name);
		if (head->id == 16)
			if (i >= 1 && i <= s * s - s - 2 && i % s >= 1 && i % s <= s - 2)
				matrix[j++] = ft_fillmatrix_t_hor_rev(s, i, head->name);
		if (head->id == 17 && (i >= 0 && i <= s * s - 2 * s - 2 && i % s >= 0 \
				&& i % s <= s - 2))
			matrix[j++] = ft_fillmatrix_t_vert(s, i, head->name);
		if (head->id == 18 && (i >= 1 && i <= s * s - 2 * s - 1 && i % s >= 1 \
				&& i % s <= s - 1))
			matrix[j++] = ft_fillmatrix_t_vert_rev(s, i, head->name);
	}
	matrix[j] = NULL;
	return (matrix);
}
