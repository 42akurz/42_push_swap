/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:45:34 by akurz             #+#    #+#             */
/*   Updated: 2021/09/24 12:00:33 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_sorting(int len, t_Node **head_a, t_Node **head_b)
{
	if (len == 2)
		hardcode_2(head_a);
	if (len == 3)
		hardcode_3(head_a);
	if (len == 4)
		hardcode_4(head_a, head_b);
	if (len == 5)
		hardcode_5(head_a, head_b);
}
