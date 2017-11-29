/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:25:59 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/24 21:26:37 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_copy_matrix(char **src)
{
	size_t	i;
	char	**dst;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dst = (char**)malloc(sizeof(char*) * (i + 1));
	if (!dst)
		return (NULL);
	dst[i] = NULL;
	while (i--)
		dst[i] = ft_strdup(src[i]);
	return (dst);
}
