/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:16:15 by akurz             #+#    #+#             */
/*   Updated: 2021/06/28 14:50:28 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count < n)
	{
		if ((unsigned char)str1[count] != (unsigned char)str2[count])
		{
			return ((unsigned char)str1[count] - (unsigned char)str2[count]);
		}
		if ((unsigned char)str1[count] == '\0'
			|| (unsigned char)str2[count] == '\0')
		{
			return (0);
		}
		count++;
	}
	return (0);
}
