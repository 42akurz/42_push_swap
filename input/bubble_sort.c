/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:15:02 by akurz             #+#    #+#             */
/*   Updated: 2021/09/23 18:37:09 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*bubble_sort(int arr[], int len)
{
	int	a;
	int	b;
	int	temp;

	a = 0;
	while (a < len - 1)
	{
		b = 0;
		while (b < len - a - 1)
		{
			if (arr[b] > arr[b + 1])
			{
				temp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = temp;
			}
			b++;
		}
		a++;
	}
	return (arr);
}
