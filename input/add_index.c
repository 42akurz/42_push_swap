/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:34:46 by akurz             #+#    #+#             */
/*   Updated: 2021/09/23 18:37:03 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_index(t_Node **head_a, int sortarr[], int len)
{
	int		i;
	t_Node	*temp;

	temp = (*head_a);
	while (temp != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (temp->data == sortarr[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}
