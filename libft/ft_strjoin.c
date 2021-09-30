/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:10:28 by akurz             #+#    #+#             */
/*   Updated: 2021/06/29 13:43:00 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	i;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[x] = s2[i];
		i++;
		x++;
	}
	str[x] = '\0';
	return (str);
}
