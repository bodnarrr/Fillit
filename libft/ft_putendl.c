/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 02:27:41 by ypikul            #+#    #+#             */
/*   Updated: 2017/10/25 02:27:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	if (s && *s)
	{
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, "\n", 1);
	}
}
