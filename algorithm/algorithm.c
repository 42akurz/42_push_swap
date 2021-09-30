/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:49:38 by akurz             #+#    #+#             */
/*   Updated: 2021/09/28 14:07:00 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_false_to_b(t_Node **head_a, t_Node **head_b, int len)
{
	int	x;

	x = 0;
	while (x < len)
	{
		if ((*head_a)->true == 1)
			rotate_A(head_a, 0);
		else
			push_B(head_b, head_a);
		x++;
	}
}

void	smallest_to_top(t_Node **head_a)
{
	int	pos;
	int	len;
	int	x;

	x = 0;
	pos = smallest_element(head_a);
	len = get_input_lenght(*head_a);
	if (pos < len / 2)
	{
		while ((*head_a)->index != 0)
		{
			rotate_A(head_a, 0);
			x++;
		}
	}
	else
	{
		while ((*head_a)->index != 0)
		{
			revrotate_A(head_a, 0);
			x++;
		}
	}
}

void	algorithm(t_Node **head_a, t_Node **head_b, int len)
{
	t_Mark	mark;

	mark.count = markup_1(head_a, &mark.head_pos);
	mark.count2 = markup_2(head_a, &mark.head_pos2);
	if (mark.count > mark.count2)
	{
		set_true_false(head_a, mark.head_pos);
	}
	else
	{
		set_true_false2(head_a, mark.head_pos2);
	}
	push_false_to_b(head_a, head_b, len);
	while ((*head_b) != NULL)
	{
		brute_force(head_a, head_b);
	}
	smallest_to_top(head_a);
}
