/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:33:23 by akurz             #+#    #+#             */
/*   Updated: 2021/09/20 10:53:33 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_A(t_Node **a_ref, int flag)
{
	t_Node	*temp;
	t_Node	*temp_2;

	if ((*a_ref)->next == NULL)
	{
		return ;
	}
	temp = *a_ref;
	(*a_ref) = (*a_ref)->next;
	temp_2 = *a_ref;
	while (temp_2->next != NULL)
	{
		temp_2 = temp_2->next;
	}
	temp_2->next = temp;
	temp->next = NULL;
	if (flag != 1)
		write(1, "ra\n", 3);
}

void	rotate_B(t_Node **b_ref, int flag)
{
	t_Node	*temp;
	t_Node	*temp_2;

	if ((*b_ref)->next == NULL)
	{
		return ;
	}
	temp = *b_ref;
	(*b_ref) = (*b_ref)->next;
	temp_2 = *b_ref;
	while (temp_2->next != NULL)
	{
		temp_2 = temp_2->next;
	}
	temp_2->next = temp;
	temp->next = NULL;
	if (flag != 1)
		write(1, "rb\n", 3);
}

void	rotate_AB(t_Node **a_ref, t_Node **b_ref)
{
	int	flag;

	flag = 1;
	rotate_A(a_ref, flag);
	rotate_B(b_ref, flag);
	write(1, "rr\n", 3);
}
