/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_square_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:47:33 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/25 16:53:17 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		ft_min_square_size(t_tetr *head, int *fcount)
{
	int		size;
	int		counter;

	counter = 0;
	while (head)
	{
		counter++;
		head = head->next;
	}
	*fcount = counter;
	counter *= 4;
	size = 0;
	while (size * size < counter)
		size++;
	return (size);
}
