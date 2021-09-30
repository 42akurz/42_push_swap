/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_of_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:41:05 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 13:53:34 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	smallest_element(t_Node **a_ref)
{
	int		min;
	int		pos;
	t_Node	*temp;
	t_Node	*temp_2;

	min = INT_MAX;
	temp = *a_ref;
	temp_2 = *a_ref;
	while (temp != NULL)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	pos = 1;
	while (temp_2->data != min)
	{
		pos++;
		temp_2 = temp_2->next;
	}
	return (pos);
}

void	push_samllest_to_b_2(t_Node **a_ref, t_Node **b_ref, int x, int pos)
{
	while (pos + 4 - 5 > x)
	{
		rotate_A(a_ref, 0);
		x++;
	}
	push_B(b_ref, a_ref);
}

void	push_samllest_to_b(t_Node **a_ref, t_Node **b_ref)
{
	int	pos;
	int	x;
	int	iter;

	iter = 0;
	while (iter < 2)
	{
		pos = smallest_element(a_ref);
		x = 0;
		if (pos == 4 || pos == 5)
		{
			while (5 - pos + 1 - iter > x)
			{
				revrotate_A(a_ref, 0);
				x++;
			}
			push_B(b_ref, a_ref);
		}
		if (pos == 1 || pos == 2 || pos == 3)
			push_samllest_to_b_2(a_ref, b_ref, x, pos);
		iter++;
	}
}

void	check_b(t_Node **b_ref)
{
	if ((*b_ref)->data < (*b_ref)->next->data)
		swap_B(b_ref, 0);
	else
		return ;
}

void	hardcode_5(t_Node **a_ref, t_Node **b_ref)
{
	push_samllest_to_b(a_ref, b_ref);
	hardcode_3(a_ref);
	check_b(b_ref);
	push_A(b_ref, a_ref);
	push_A(b_ref, a_ref);
}
