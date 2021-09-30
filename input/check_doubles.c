/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:39:50 by akurz             #+#    #+#             */
/*   Updated: 2021/09/29 14:08:59 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_doubles(int arr[], int len)
{
	int	temp;
	int	t;
	int	a;

	a = 0;
	while (a < len)
	{
		temp = arr[a];
		t = a + 1;
		while (t < len)
		{
			if (temp == arr[t])
			{
				write(2, "ERROR\n", 6);
				exit(0);
			}
			t++;
		}
		a++;
	}
}
