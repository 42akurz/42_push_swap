/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 09:19:12 by akurz             #+#    #+#             */
/*   Updated: 2021/09/23 18:37:21 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*list_to_array(t_Node *head_a, int listlen)
{
	int	*arr;
	int	a;

	a = 0;
	arr = malloc(sizeof(int) * listlen);
	if (arr == NULL)
	{
		write(2, "ERROR\nlist_to_array\n", 20);
		exit(0);
	}
	while (head_a != NULL)
	{
		arr[a] = head_a->data;
		a++;
		head_a = head_a->next;
	}
	return (arr);
}
