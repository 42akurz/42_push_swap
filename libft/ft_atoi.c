/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:34:29 by akurz             #+#    #+#             */
/*   Updated: 2021/09/22 08:21:35 by akurz            ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

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

/*
special char: space, carriage return, newline, tab, feed,
              backspace, vertical tab
int res: ergebnis speichern
int sign: vorzeichen
erstes if: dass auch negative zahlen converted werden koennen
letzte while: *10 fuer weitere digits, + str[i] - '0', dass digit
             ein wert bekommt und ascii wert mit reelem stimmt
*/
