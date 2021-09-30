/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_of_2or3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:39:21 by akurz             #+#    #+#             */
/*   Updated: 2021/09/21 10:49:27 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	hardcode_3(t_Node **a_ref)
{
	int	a;
	int	b;
	int	c;

	a = (*a_ref)->data;
	b = (*a_ref)->next->data;
	c = (*a_ref)->next->next->data;
	if (a > b && b > c)
	{
		swap_A(a_ref, 0);
		revrotate_A(a_ref, 0);
	}
	else if (a > b && c < a)
		rotate_A(a_ref, 0);
	else if (a > b && b < c)
		swap_A(a_ref, 0);
	else if (a < b && c < a)
		revrotate_A(a_ref, 0);
	else if (a < b && c > a && b > c)
	{
		revrotate_A(a_ref, 0);
		swap_A(a_ref, 0);
	}
	else
		return ;
}

void	hardcode_2(t_Node **a_ref)
{
	int	a;
	int	b;

	a = (*a_ref)->data;
	b = (*a_ref)->next->data;
	if (a > b)
		swap_A(a_ref, 0);
	else
		return ;
}
