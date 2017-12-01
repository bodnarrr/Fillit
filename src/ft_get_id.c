/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 01:49:38 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/25 23:14:32 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

/*
**                 ##                  #
**  13 - #    12 - #   14 - ###  11 -  #
**       ###       #          #       ##
**
**                 #                  ##
**  9  -   #  7  - #   10 - ###  8  -  #
**       ###       ##       #          #
*/

static uint8_t	ft_find_jl(const uint16_t mask)
{
	if (mask == 36352 || mask == 2272 || mask == 142 || \
			mask == 18176 || mask == 1136 || mask == 71)
		return (13);
	if (mask == 51328 || mask == 25664 || mask == 12832 || \
			mask == 3208 || mask == 1604 || mask == 802)
		return (12);
	if (mask == 57856 || mask == 3616 || mask == 226 || \
			mask == 28928 || mask == 1808 || mask == 113)
		return (14);
	if (mask == 17600 || mask == 8800 || mask == 4400 || \
			mask == 1100 || mask == 550 || mask == 275)
		return (11);
	if (mask == 11776 || mask == 736 || mask == 46 || \
			mask == 5888 || mask == 368 || mask == 23)
		return (9);
	if (mask == 35008 || mask == 17504 || mask == 8752 || \
			mask == 2188 || mask == 1094 || mask == 547)
		return (7);
	if (mask == 59392 || mask == 3712 || mask == 232 || \
			mask == 29696 || mask == 1856 || mask == 116)
		return (10);
	if (mask == 50240 || mask == 25120 || mask == 12560 || \
			mask == 3140 || mask == 1570 || mask == 785)
		return (8);
	return (42);
}

/*
**                 #                   #
**  5  -  ##  6  - ##  3  - ##   4  - ##
**       ##         #        ##       #
*/

static uint8_t	ft_find_sz(const uint16_t mask)
{
	if (mask == 27648 || mask == 1728 || mask == 108 || \
			mask == 13824 || mask == 864 || mask == 54)
		return (5);
	if (mask == 35904 || mask == 17952 || mask == 8976 || \
			mask == 2244 || mask == 1122 || mask == 561)
		return (6);
	if (mask == 50688 || mask == 3168 || mask == 198 || \
			mask == 25344 || mask == 1584 || mask == 99)
		return (3);
	if (mask == 19584 || mask == 9792 || mask == 4896 || \
			mask == 1224 || mask == 612 || mask == 306)
		return (4);
	return (42);
}

/*
**                  #
**  1  - ####  2  - #  0  - ##
**                  #       ##
**                  #
**
**                 #                   #
**  16 -  #   17 - ##  15 - ###  18 - ##
**       ###       #         #         #
*/

static uint8_t	ft_find_iot(const uint16_t mask)
{
	if (mask == 61440 || mask == 3840 ||  \
			mask == 240 || mask == 15)
		return (1);
	if (mask == 34952 || mask == 17476 || \
			mask == 8738 || mask == 4369)
		return (2);
	if (mask == 52224 || mask == 26112 || mask == 13056 || \
			mask == 3264 || mask == 1632 || mask == 816 || \
			mask == 204 || mask == 102 || mask == 51)
		return (0);
	if (mask == 19968 || mask == 1248 || mask == 78 || \
			mask == 9984 || mask == 624 || mask == 39)
		return (16);
	if (mask == 35968 || mask == 17984 || mask == 8992 || \
			mask == 2248 || mask == 1124 || mask == 562)
		return (17);
	if (mask == 58368 || mask == 3648 || mask == 228 || \
			mask == 29184 || mask == 1824 || mask == 114)
		return (15);
	if (mask == 19520 || mask == 9760 || mask == 4880 || \
			mask == 1220 || mask == 610 || mask == 305)
		return (18);
	return (42);
}

static uint16_t	ft_get_bitmask(const char *tetrimino)
{
	uint16_t mask;

	mask = 0;
	while (*tetrimino != '\0')
	{
		if (ISVALID_ELEM(*tetrimino))
		{
			mask = mask << 1;
			if (*tetrimino == FULL_BLOCK)
				mask++;
		}
		tetrimino++;
	}
	return (mask);
}

uint8_t			ft_get_id(const char *tetrimino)
{
	uint16_t	mask;
	uint8_t		id;

	mask = ft_get_bitmask(tetrimino);
	if ((id = ft_find_jl(mask)) != 42)
		;
	else if ((id = ft_find_sz(mask)) != 42)
		;
	else
		id = ft_find_iot(mask);
	return (id);
}
