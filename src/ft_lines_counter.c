/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:36:51 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/24 20:05:37 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_l_counter(char **matrix)
{
	int	little;
	int i;

	little = 0;
	i = -1;
	while (matrix[++i])
		if (matrix[i][0] >= 'a' && matrix[i][0] <= 'z')
			little++;
	return (little);
}

int		ft_b_counter(char **matrix)
{
	int big;
	int	i;

	big = 0;
	i = -1;
	while (matrix[++i])
		if (matrix[i][0] >= 'A' && matrix[i][0] <= 'Z')
			big++;
	return (big);
}
