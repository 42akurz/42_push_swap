/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:41:50 by akurz             #+#    #+#             */
/*   Updated: 2021/07/14 10:06:39 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (ptr[count] == (unsigned char)c)
		{
			return ((char *)(ptr + count));
		}
		count++;
	}
	return (0);
}
