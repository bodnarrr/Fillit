/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigmatrix_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:51:06 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/25 17:59:44 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_bigmatrix_size(int s, t_tetr *head)
{
	int		res;

	res = 0;
	while (head)
	{
		if (head->id == 0)
			res += (s - 1) * (s - 1);
		else if (head->id == 1 || head->id == 2)
			res += s * (s - 3);
		else
			res += (s - 1) * (s - 2);
		head = head->next;
	}
	return (res);
}
