/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:22:02 by akurz             #+#    #+#             */
/*   Updated: 2021/09/22 08:24:18 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_specialchar(char c)
{
	if (c == ' ' || c == '\r' || c == '\n'
		|| c == '\t' || c == '\f' || c == '\b' || c == '\v')
		return (1);
	return (0);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_specialchar(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while ((str[i] != '\0') && (str[i] - '0' >= 0 && str[i] - '0' <= 9))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
