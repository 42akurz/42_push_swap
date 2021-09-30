/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:35:40 by akurz             #+#    #+#             */
/*   Updated: 2021/09/29 14:12:58 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	m_push_B(t_Node **b_Ref, t_Node **a_Ref)
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
}

void	m_push_A(t_Node **b_Ref, t_Node **a_Ref)
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
}

void	m_swap_AB(t_Node **a_ref, t_Node **b_ref)
{
	int	flag;

	flag = 1;
	swap_A(a_ref, flag);
	swap_B(b_ref, flag);
}

void	m_rotate_AB(t_Node **a_ref, t_Node **b_ref)
{
	int	flag;

	flag = 1;
	rotate_A(a_ref, flag);
	rotate_B(b_ref, flag);
}

void	m_revrotate_AB(t_Node **a_ref, t_Node **b_ref)
{
	int	flag;

	flag = 1;
	revrotate_B(a_ref, flag);
	revrotate_B(b_ref, flag);
}
