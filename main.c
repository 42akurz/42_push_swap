/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:34:12 by akurz             #+#    #+#             */
/*   Updated: 2021/09/29 09:01:21 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_Node *head_ref)
{
	while (head_ref->next != NULL)
	{
		if (head_ref->index > head_ref->next->index)
			return (0);
		head_ref = head_ref->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_Node	*head_a;
	t_Node	*head_b;
	t_vars	vars;

	vars.flag = 0;
	get_input(argc, argv, &vars.input, &vars.flag);
	fill_list(argv, vars.input, &head_a, vars.flag);
	vars.len = get_input_lenght(head_a);
	vars.arr = list_to_array(head_a, vars.len);
	check_doubles(vars.arr, vars.len);
	vars.sortarr = bubble_sort(vars.arr, vars.len);
	add_index(&head_a, vars.sortarr, vars.len);
	vars.flag2 = check_sorted(head_a);
	if (vars.flag2 == 1)
		exit(0);
	if (vars.len <= 5)
		small_sorting(vars.len, &head_a, &head_b);
	else
	{
		algorithm(&head_a, &head_b, vars.len);
	}
	return (0);
}
