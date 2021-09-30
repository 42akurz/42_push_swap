/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:03:42 by akurz             #+#    #+#             */
/*   Updated: 2021/09/29 14:29:19 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	read_exeute(t_Node **a_bonus, t_Node **b_bonus, char *str)
{
	if (ft_strncmp(str, "pb\n", 3) == 0)
		m_push_B(b_bonus, a_bonus);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		m_push_A(b_bonus, a_bonus);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate_A(a_bonus, 1);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate_B(b_bonus, 1);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		m_rotate_AB(a_bonus, b_bonus);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		revrotate_A(a_bonus, 1);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		revrotate_B(b_bonus, 1);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		m_revrotate_AB(a_bonus, b_bonus);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_A(a_bonus, 1);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_B(b_bonus, 1);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		m_swap_AB(a_bonus, b_bonus);
}

int	check_sorted(t_Node *head_ref)
{
	while (head_ref->next != NULL)
	{
		if (head_ref->data > head_ref->next->data)
			return (0);
		head_ref = head_ref->next;
	}
	return (1);
}

int	check_in(char *str)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(str, "pb\n", 3) == 0
		|| ft_strncmp(str, "pa\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "ra\n", 3) == 0
		|| ft_strncmp(str, "rb\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "rra\n", 4) == 0
		|| ft_strncmp(str, "rrb\n", 4) == 0)
		flag = 1;
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		flag = 1;
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		flag = 1;
	return (flag);
}

void	list_to_array_2(t_Node *head_a)
{
	int	*arr;
	int	a;
	int	listlen;

	listlen = get_input_lenght_b(head_a);
	a = 0;
	arr = malloc(sizeof(int) * listlen);
	if (arr == NULL)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	while (head_a != NULL)
	{
		arr[a] = head_a->data;
		a++;
		head_a = head_a->next;
	}
	check_doubles(arr, listlen);
}

int	main(int argc, char **argv)
{
	t_Node	*a_bonus;
	t_Node	*b_bonus;
	int		flag;
	char	**arr;

	flag = 0;
	if (argc == 1)
		exit(0);
	get_input_b(argc, argv, &arr, &flag);
	fill_list_b(argv, arr, &a_bonus, flag);
	list_to_array_2(a_bonus);
	while_loop(&a_bonus, &b_bonus);
	if (check_sorted(a_bonus) == 1 && b_bonus == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
