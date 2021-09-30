/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:44:32 by akurz             #+#    #+#             */
/*   Updated: 2021/09/28 14:17:03 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	greater_markup(t_Node **head_a)
{
	t_Node	*markup_head;
	int		temp;
	int		count;

	markup_head = *head_a;
	temp = markup_head->data;
	count = 1;
	while (markup_head->next != NULL)
	{
		markup_head = markup_head->next;
		if (markup_head->data > temp)
		{
			count++;
			temp = markup_head->data;
		}
	}
	return (count);
}

int	markup_1(t_Node **head_a, int *head_pos)
{
	t_Node	*move_head;
	t_M1	m1;

	m1.flag = 0;
	m1.x = 0;
	m1.count = 0;
	move_head = *head_a;
	m1.temp = greater_markup(&move_head);
	while (move_head->next != NULL)
	{
		move_head = move_head->next;
		m1.x++;
		m1.count = greater_markup(&move_head);
		if (m1.count > m1.temp)
		{
			(*head_pos) = m1.x;
			m1.temp = m1.count;
			m1.flag = 1;
		}
	}
	if (m1.flag == 0)
		(*head_pos) = m1.temp;
	return (m1.temp);
}

int	index_markup(t_Node **head_a)
{
	t_Node	*markup_head;
	int		temp;
	int		count;

	markup_head = *head_a;
	temp = markup_head->index;
	count = 1;
	while (markup_head->next != NULL)
	{
		markup_head = markup_head->next;
		if (markup_head->index == temp + 1)
		{
			count++;
			temp = markup_head->index;
		}
	}
	return (count);
}

int	markup_2(t_Node **head_a, int *head_pos2)
{
	t_Node	*move_head;
	t_M1	m2;

	m2.flag = 0;
	m2.x = 0;
	m2.count = 0;
	move_head = *head_a;
	m2.temp = index_markup(&move_head);
	while (move_head->next != NULL)
	{
		move_head = move_head->next;
		m2.x++;
		m2.count = index_markup(&move_head);
		if (m2.count > m2.temp)
		{
			(*head_pos2) = m2.x;
			m2.temp = m2.count;
			m2.flag = 1;
		}
	}
	if (m2.flag == 0)
		(*head_pos2) = m2.temp;
	return (m2.temp);
}
