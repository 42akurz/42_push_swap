/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:46:56 by akurz             #+#    #+#             */
/*   Updated: 2021/09/20 10:53:57 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	revrotate_A(t_Node **a_ref, int flag)
{
	t_Node	*temp_2;
	t_Node	*temp;

	if ((*a_ref)->next == NULL)
	{
		return ;
	}
	temp_2 = *a_ref;
	while (temp_2->next->next != NULL)
	{
		temp_2 = temp_2->next;
	}
	temp = temp_2->next;
	temp->next = *a_ref;
	*a_ref = temp;
	temp_2->next = NULL;
	if (flag != 1)
		write(1, "rra\n", 4);
}

void	revrotate_B(t_Node **b_ref, int flag)
{
	t_Node	*temp_2;
	t_Node	*temp;

	if ((*b_ref)->next == NULL)
	{
		return ;
	}
	temp_2 = *b_ref;
	while (temp_2->next->next != NULL)
	{
		temp_2 = temp_2->next;
	}
	temp = temp_2->next;
	temp->next = *b_ref;
	*b_ref = temp;
	temp_2->next = NULL;
	if (flag != 1)
		write(1, "rrb\n", 4);
}

void	revrotate_AB(t_Node **a_ref, t_Node **b_ref)
{
	int	flag;

	flag = 1;
	revrotate_B(a_ref, flag);
	revrotate_B(b_ref, flag);
	write(1, "rrr\n", 4);
}
