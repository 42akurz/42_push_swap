/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:40:46 by akurz             #+#    #+#             */
/*   Updated: 2021/06/28 15:00:04 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	ptr1 = (char *) dst;
	ptr2 = (const char *) src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	if (dst >= src)
	{
		i = len;
		while (i-- != 0)
			ptr1[i] = ptr2[i];
	}
	return ((void *)dst);
}
//zweites if: strings ueberlappen nicht also normal cpy
//drittes if: strings ueberlappen
//i = len: zum ende des strings und reverse cpy
//letzte while: bis index beim 0 (erster char) ist
