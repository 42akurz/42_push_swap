/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_of_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:01:13 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 13:53:42 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_smallest_to_b(t_Node **a_ref, t_Node **b_ref)
{
	int	pos;
	int	x;

	pos = smallest_element(a_ref);
	x = 0;
	if (pos == 3 || pos == 4)
	{
		while (4 - pos + 1 > x)
		{
			revrotate_A(a_ref, 0);
			x++;
		}
		push_B(b_ref, a_ref);
	}
	if (pos == 2)
	{
		rotate_A(a_ref, 0);
		push_B(b_ref, a_ref);
	}
	if (pos == 1)
		push_B(b_ref, a_ref);
}

void	hardcode_4(t_Node **a_ref, t_Node **b_ref)
{
	push_smallest_to_b(a_ref, b_ref);
	hardcode_3(a_ref);
	push_A(b_ref, a_ref);
}
