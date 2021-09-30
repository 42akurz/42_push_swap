/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:00:46 by akurz             #+#    #+#             */
/*   Updated: 2021/08/09 09:14:12 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	x;
	size_t	i;

	x = 0;
	i = start;
	if (s == NULL)
		return (NULL);
	substring = (char *)malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring[0] = 0;
		return (substring);
	}
	while (x < len && s[x] != '\0')
	{
		substring[x] = s[i];
		i++;
		x++;
	}
	substring[x] = '\0';
	return (substring);
}

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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(ft_strlen(s1) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
