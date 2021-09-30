/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:38:31 by akurz             #+#    #+#             */
/*   Updated: 2021/09/28 15:31:39 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	biggest_element(t_Node **a_ref)
{
	int		min;
	int		pos;
	t_Node	*temp;
	t_Node	*temp_2;

	min = INT_MIN;
	temp = *a_ref;
	temp_2 = *a_ref;
	while (temp != NULL)
	{
		if (min < temp->data)
			min = temp->data;
		temp = temp->next;
	}
	pos = 1;
	while (temp_2->data != min)
	{
		pos++;
		temp_2 = temp_2->next;
	}
	return (pos);
}

/* finding the next biggest element in a, so i know where i have to put b */
/* i would have to rotate depending on the position of next biggest */
int	check_insertion(t_Node *temp_a, t_Node *temp_b)
{
	t_Node		*temp_a_2;
	t_insert	insert;

	insert.x = 0;
	insert.pos = 0;
	insert.flag = 0;
	temp_a_2 = temp_a;
	insert.diff_temp = INT_MAX;
	while (temp_a_2 != NULL)
	{
		insert.diff = temp_a_2->index - temp_b->index;
		if (insert.diff < insert.diff_temp && insert.diff > 0)
		{
			insert.diff_temp = insert.diff;
			insert.pos = insert.x;
			insert.flag = 1;
		}
		temp_a_2 = temp_a_2->next;
		insert.x++;
	}
	if (insert.flag == 0)
		insert.pos = biggest_element(&temp_a);
	return (insert.pos);
}

int	count_ops(t_Node **a_ref, t_Node *temp_b, int *opcount)
{
	t_Node	*temp_a;
	int		len_a;
	int		count;

	temp_a = *a_ref;
	len_a = get_input_lenght(temp_a);
	count = check_insertion(temp_a, temp_b);
	if (count > len_a / 2)
		(*opcount) = len_a - count;
	else
		(*opcount) = count;
	return (count);
}

void	finder(t_Node *temp_b, t_Node **a_ref, t_Force *force)
{
	t_Node	*a;

	while (temp_b != NULL)
	{
		force->opcount = 0;
		a = *a_ref;
		force->insertion_temp = count_ops(&a, temp_b, &force->opcount);
		temp_b->insertion = force->insertion_temp;
		if (force->x > force->len_b / 2)
			force->opcount_b = force->len_b - force->x;
		else
			force->opcount_b = force->x;
		force->opcount = force->opcount + force->opcount_b;
		temp_b->operations = force->opcount;
		if (force->tempcount > force->opcount)
		{
			force->tempcount = force->opcount;
			force->element = force->x;
			force->insertion_var = force->insertion_temp;
		}
		temp_b = temp_b->next;
		force->x++;
	}
}

void	brute_force(t_Node **a_ref, t_Node **b_ref)
{
	t_Node	*temp_b;
	t_Force	force;

	force.x = 0;
	temp_b = *b_ref;
	force.len_b = get_input_lenght(*b_ref);
	force.tempcount = INT_MAX;
	finder(temp_b, a_ref, &force);
	do_the_job(a_ref, b_ref, force);
}
