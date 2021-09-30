/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:03:52 by akurz             #+#    #+#             */
/*   Updated: 2021/06/28 15:00:37 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) dst;
	ptr2 = (unsigned char *) src;
	count = 0;
	if (ptr2 == NULL && ptr1 == NULL)
		return (NULL);
	while (count < n)
	{
		ptr1[count] = ptr2[count];
		count++;
	}
	return (dst);
}
