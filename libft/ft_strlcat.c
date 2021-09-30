/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:13:14 by akurz             #+#    #+#             */
/*   Updated: 2021/06/28 14:54:26 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	i;
	int		re;

	x = ft_strlen(dst);
	re = ft_strlen(src);
	if (dstsize <= x)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (x < dstsize - 1 && src[i] != '\0')
	{
		dst[x] = src[i];
		x++;
		i++;
	}
	dst[x] = '\0';
	return (ft_strlen(dst) + re - i);
}
//erster while loop: src[i] waere das selbe wie src[i] != '\0'
//return: laenge die in dstsize hineinpasst
