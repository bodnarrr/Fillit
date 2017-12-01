/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 02:04:12 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/26 00:34:07 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

void	ft_tetrdel(t_tetr **start)
{
	t_tetr	*next;

	if (start != NULL)
		while (*start != NULL)
		{
			next = (*start)->next;
			free(*start);
			*start = next;
		}
}
