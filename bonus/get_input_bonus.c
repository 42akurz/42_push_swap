/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:16:15 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 14:00:11 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	addback(t_Node **head_ref, int new_data)
{
	t_Node	*newNode;
	t_Node	*last;

	last = *head_ref;
	newNode = malloc(sizeof(t_Node));
	newNode->data = new_data;
	newNode->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = newNode;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
	return ;
}

int	get_input_lenght_b(t_Node *head)
{
	int	len;

	len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	get_input_b(int argc, char **argv, char ***input, int *flag)
{
	if (argc == 2)
	{
		if ((ft_atoll(argv[1]) == 0) && (ft_strncmp(argv[1], "0", 1)))
			write(2, "ERROR\n", 6);
		(*input) = ft_split(argv[1], ' ');
		if ((*input)[1] == NULL)
			exit(0);
		else
		{
			*flag = 1;
			return ;
		}
	}
	if (argc > 2)
	{
		return ;
	}
	if (argc < 2)
		exit(0);
}

void	fill_list_2_b(char **input, t_Node **head_a)
{
	int			i;
	long long	d;

	i = 0;
	while (input[i] != NULL)
	{
		d = ft_atoll(input[i]);
		if (d == 0 && (ft_strncmp(input[i], "0", 1)))
		{
			write(2, "ERROR\n", 6);
			exit(0);
		}
		if (d > INT_MAX || d < INT_MIN)
		{
			write(2, "ERROR\n", 6);
			exit(0);
		}
		addback(head_a, d);
		i++;
	}
}

void	fill_list_b(char **argv, char **input, t_Node **head_a, int flag)
{
	int			x;
	long long	d;

	if (flag == 0)
	{
		x = 1;
		while (argv[x] != NULL)
		{
			d = ft_atoll(argv[x]);
			if (d == 0 && (ft_strncmp(argv[x], "0", 1)))
			{
				write(2, "ERROR\n", 6);
				exit(0);
			}
			if (d > INT_MAX || d < INT_MIN)
			{
				write(2, "ERROR\n", 6);
				exit(0);
			}
			addback(head_a, d);
			x++;
		}
	}
	else
		fill_list_2_b(input, head_a);
}
