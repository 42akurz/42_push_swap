/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 09:07:06 by akurz             #+#    #+#             */
/*   Updated: 2021/09/20 10:52:42 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_B(t_Node **b_Ref, t_Node **a_Ref)
{
	t_Node	*newNode;

	newNode = *a_Ref;
	if (newNode == NULL)
	{
		return ;
	}
	*a_Ref = newNode->next;
	newNode->next = *b_Ref;
	*b_Ref = newNode;
	write(1, "pb\n", 3);
}

void	push_A(t_Node **b_Ref, t_Node **a_Ref)
{
	t_Node	*newNode;

	newNode = *b_Ref;
	if (newNode == NULL)
	{
		return ;
	}
	*b_Ref = newNode->next;
	newNode->next = *a_Ref;
	*a_Ref = newNode;
	write(1, "pa\n", 3);
}

void	swap_A(t_Node **a_ref, int flag)
{
	t_Node	*temp;
	t_Node	*temp_2;

	if ((*a_ref) == NULL || (*a_ref)->next == NULL)
	{
		return ;
	}
	temp = *a_ref;
	(*a_ref) = (*a_ref)->next;
	temp_2 = (*a_ref)->next;
	(*a_ref)->next = temp;
	(*a_ref)->next->next = temp_2;
	if (flag != 1)
		write(1, "sa\n", 3);
}

void	swap_B(t_Node **b_ref, int flag)
{
	t_Node	*temp;
	t_Node	*temp_2;

	if ((*b_ref) == NULL || (*b_ref)->next == NULL)
	{
		return ;
	}
	temp = *b_ref;
	(*b_ref) = (*b_ref)->next;
	temp_2 = (*b_ref)->next;
	(*b_ref)->next = temp;
	(*b_ref)->next->next = temp_2;
	if (flag != 1)
		write(1, "sb\n", 3);
}

void	swap_AB(t_Node **a_ref, t_Node **b_ref)
{
	int	flag;

	flag = 1;
	swap_A(a_ref, flag);
	swap_B(b_ref, flag);
	write(1, "ss\n", 3);
}
