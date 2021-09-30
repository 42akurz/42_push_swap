/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_true_false.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:28:08 by akurz             #+#    #+#             */
/*   Updated: 2021/09/28 14:08:09 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_true_false(t_Node **head_a, int pos)
{
	t_Node	*temp;
	int		x;
	int		temp2;

	temp = *head_a;
	x = 0;
	while (x < pos)
	{
		temp = temp->next;
		x++;
	}
	temp2 = temp->data;
	temp->true = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->data > temp2)
		{
			temp->true = 1;
			temp2 = temp->data;
		}
		else
			temp->true = 0;
	}
}

void	set_true_false2(t_Node **head_a, int pos)
{
	t_Node	*temp;
	int		x;
	int		temp2;

	temp = *head_a;
	x = 0;
	while (x < pos)
	{
		temp = temp->next;
		x++;
	}
	temp2 = temp->index;
	temp->true = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->index == temp2 + 1)
		{
			temp->true = 1;
			temp2 = temp->index;
		}
		else
			temp->true = 0;
	}
}
