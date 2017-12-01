/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:13:44 by abodnar           #+#    #+#             */
/*   Updated: 2017/12/01 12:50:17 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_change_symbol_in_row(char **matrix, int pos_y)
{
	int	j;

	j = 0;
	while (matrix[pos_y][j])
	{
		if (matrix[pos_y][j] == '1')
			matrix[pos_y][j] = matrix[pos_y][0] - 32;
		j++;
	}
}

static void	ft_clear_same_letter(char **matrix, int pos_y)
{
	char	name;
	int		i;
	int		j;

	i = 0;
	j = 0;
	name = matrix[pos_y][0];
	while (matrix[i])
	{
		if (matrix[i][0] == name && i != pos_y)
		{
			j = 0;
			while (matrix[i][j])
				matrix[i][j++] = '.';
		}
		i++;
	}
}

char		**ft_clear_rows(char **matrix, int pos_y)
{
	int		i;
	int		j;
	int		k;

	ft_clear_same_letter(matrix, pos_y);
	j = -1;
	while (matrix[pos_y][++j])
		if (matrix[pos_y][j] == '1')
		{
			i = -1;
			while (matrix[++i])
				if (matrix[i][j] == '1' && i != pos_y)
				{
					k = 0;
					while (matrix[i][k])
						matrix[i][k++] = '.';
				}
		}
	matrix[pos_y][0] += 32;
	ft_change_symbol_in_row(matrix, pos_y);
	return (matrix);
}
