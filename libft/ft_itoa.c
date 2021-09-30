/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:44:28 by akurz             #+#    #+#             */
/*   Updated: 2021/07/02 12:18:39 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_null(char *a)
{
	if (ft_strlen(a) == 0)
	{
		a[0] = '0';
		a[1] = '\0';
		return ;
	}
}

static void	ft_reverse(char *a, int minus)
{
	int		i;
	int		x;
	char	res;

	i = ft_strlen(a) - 1;
	x = 0;
	if (minus == 0)
		a[i + 1] = '\0';
	if (minus == 1)
	{
		a[i + 1] = '-';
		a[i + 2] = '\0';
		i++;
	}
	while (x < i)
	{
		res = a[i];
		a[i] = a[x];
		a[x] = res;
		x++;
		i--;
	}
	if (ft_strlen(a) == 0)
		ft_null(a);
}

static char	ft_minimal(int n, char *temp)
{
	if (n == -2147483648)
	{
		temp[0] = '-';
		temp[1] = '2';
		temp[2] = '1';
		temp[3] = '4';
		temp[4] = '7';
		temp[5] = '4';
		temp[6] = '8';
		temp[7] = '3';
		temp[8] = '6';
		temp[9] = '4';
		temp[10] = '8';
		temp[11] = '\0';
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*temp;
	size_t	i;
	int		minus;

	temp = malloc(ft_countdigits(n) + 1);
	if (temp == NULL)
		return (NULL);
	if (ft_minimal(n, temp) == 1)
		return (temp);
	i = 0;
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n = n * (-1);
	}
	while (n > 0)
	{
		temp[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	temp[i] = '\0';
	ft_reverse(temp, minus);
	return (temp);
}

//falls n null ist setzt i to a an erste stelle \0 (temp[i] = \0)
//dadurch wird strlen == 0 und in reverse wird ft_null aufgerufen
