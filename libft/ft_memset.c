/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:43:20 by akurz             #+#    #+#             */
/*   Updated: 2021/06/28 14:57:26 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*ptr;

	ptr = (char *) str;
	count = 0;
	while (count < n)
	{
		ptr[count] = c;
		count++;
	}
	return (str);
}
