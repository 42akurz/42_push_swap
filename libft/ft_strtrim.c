/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:45:28 by akurz             #+#    #+#             */
/*   Updated: 2021/07/02 12:16:29 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_front(const char *s1, const char *set)
{
	int	i;
	int	x;
	int	flag;

	i = 0;
	while (s1[i] != '\0')
	{
		x = 0;
		flag = 0;
		while (set[x] != '\0' && flag != 1)
		{
			if (s1[i] == set[x])
				flag = 1;
			x++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_back(const char *s1, const char *set)
{
	int	i;
	int	x;
	int	flag;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		x = 0;
		flag = 0;
		while (set[x] != '\0' && flag != 1)
		{
			if (set[x] == s1[i])
				flag = 1;
			x++;
		}
		if (flag == 0)
			return (i);
		i--;
	}
	return (0);
}

static char	*ft_newstring(const char *s1, size_t start, size_t end)
{
	char	*newstring;
	size_t	i;
	size_t	x;

	newstring = (char *)malloc(end + 2 - start);
	if (newstring == NULL)
		return (NULL);
	if (start == 0 && end == 0)
	{
		newstring[0] = '\0';
		return ((char *)newstring);
	}
	i = 0;
	x = start;
	while (x <= end)
	{
		newstring[i] = s1[x];
		i++;
		x++;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*news;
	size_t	start;
	size_t	end;

	if (s1 == 0)
		return (0);
	start = ft_front(s1, set);
	end = ft_back(s1, set);
	news = ft_newstring(s1, start, end);
	return (news);
}
