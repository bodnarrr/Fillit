/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:19:04 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/18 18:06:42 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include <stdlib.h>

t_tetr	*ft_tetrnew(const uint8_t id)
{
	t_tetr *tetrimino;

	if ((tetrimino = malloc(sizeof(t_tetr))) == NULL)
		return (NULL);
	tetrimino->id = id;
	tetrimino->name = 0;
	tetrimino->matrix = NULL;
	tetrimino->next = NULL;
	return (tetrimino);
}
