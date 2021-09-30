/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:35:12 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 14:06:32 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./bonus/get_next_line/get_next_line.h"

typedef struct s_Node
{
	int				data;
	int				index;
	int				true;
	int				insertion;
	int				operations;
	struct s_Node	*next;
}			t_Node;

typedef struct s_Vars
{
	char	**input;
	int		flag;
	int		flag2;
	int		len;
	int		*arr;
	int		*sortarr;
}			t_vars;

typedef struct s_Mark
{
	int	head_pos;
	int	count;
	int	head_pos2;
	int	count2;
}			t_Mark;

typedef struct s_Force
{
	int		opcount;
	int		opcount_b;
	int		x;
	int		len_b;
	int		tempcount;
	int		element;
	int		insertion_var;
	int		insertion_temp;
}			t_Force;

typedef struct s_M1
{
	int		count;
	int		temp;
	int		x;
	int		flag;
}			t_M1;

typedef struct s_job
{
	int	x;
	int	y;
	int	len_a;
}			t_job;

typedef struct s_insert
{
	int		diff;
	int		diff_temp;
	int		pos;
	int		x;
	int		flag;
}			t_insert;

/* Checks, if a stack is sorted in ascending order (top to bottom).
Returns 1 if sorted, 0 if unsorted. */
int		check_sorted(t_Node *head_ref);

/*-------------------------- operations folder ---------------------------*/

void	push_B(t_Node **b_Ref, t_Node **a_Ref);
void	push_A(t_Node **b_Ref, t_Node **a_Ref);
void	swap_A(t_Node **a_ref, int flag);
void	swap_B(t_Node **b_ref, int flag);
void	swap_AB(t_Node **a_ref, t_Node **b_ref);
void	rotate_A(t_Node **a_ref, int flag);
void	rotate_B(t_Node **b_ref, int flag);
void	rotate_AB(t_Node **a_ref, t_Node **b_ref);
void	revrotate_A(t_Node **a_ref, int flag);
void	revrotate_B(t_Node **b_ref, int flag);
void	revrotate_AB(t_Node **a_ref, t_Node **b_ref);

/*------------------------------------------------------------------------*/

/*--------------------------- input folder -------------------------------*/

/* In case the function is called with variable as an argument,
it splits it into seperate arguments.
It also checks if an element is a non integer or bigger then INT_MAX with
the help of ft_atoll (in libft). */
void	get_input(int argc, char **argv, char ***input, int *flag);

/* Gets lenght of a stack. */
int		get_input_lenght(t_Node *head);

/* Adding element to the end of the stack. */
void	addback(t_Node **head_ref, int new_data);

/* Puts all the arguments in stack A (linked list). */
void	fill_list(char **argv, char **input, t_Node **head_a, int flag);

/* Puts stack into a list of integers :
- required to check for doubles
- required for bubble sort
- required to then add index */
int		*list_to_array(t_Node *head_a, int listlen);

/* Checks if array contains any element more than once. */
void	check_doubles(int arr[], int len);

/* Sorts array by comparing each element with the following element
and swapping them if neccesary. */
int		*bubble_sort(int arr[], int len);

/* Iterating through the sorted array and adding the index to the
corresponding element of the stack (linked list). */
void	add_index(t_Node **head_a, int sortarr[], int len);

/*------------------------------------------------------------------------*/

/*------------------------- small_sorting folder -------------------------*/

/* Sorting in case i have only 2, 3 or 5 elements to sort,
to minimize the amount of operations */
void	small_sorting(int len, t_Node **head_a, t_Node **head_b);
void	hardcode_2(t_Node **a_ref);
void	hardcode_3(t_Node **a_ref);
void	hardcode_4(t_Node **a_ref, t_Node **b_ref);
void	hardcode_5(t_Node **a_ref, t_Node **b_ref);

/* Checks for the smallest element inside a stack (linked list) */
int		smallest_element(t_Node **a_ref);

/*------------------------------------------------------------------------*/

/*--------------------------- algorithm folder ---------------------------*/

/* Driver for the brute force algorithm */
void	algorithm(t_Node **head_a, t_Node **head_b, int len);

/* Checks for the biggest existing sorted array inside of STACK A.
It compares the data. */
int		markup_1(t_Node **head_a, int *head_pos);

/* Checks for the biggest existing sorted array inside of STACK A.
It compares the Index. */
int		markup_2(t_Node **head_a, int *head_pos2);

/* Any element thats part of the sorted part will be true (1).
All the other elements get marked as false (0). */
void	set_true_false(t_Node **head_a, int pos);
void	set_true_false2(t_Node **head_a, int pos);

/* All false elements get pushed to STACK B! */
void	push_false_to_b(t_Node **head_a, t_Node **head_b, int len);

/* Checks for each element in Stack B how many Operations it would take;
to get it to the right position inside of Stack A. */
void	brute_force(t_Node **a_ref, t_Node **b_ref);

/* Executes the Operations to get the Element with the least operations,
to it's position in Stack A. */
void	do_the_job(t_Node **a_ref, t_Node **b_ref, t_Force force);

/* When B is empty and A is sorted,
the smallest element in A needs to be at the top. */
void	smallest_to_top(t_Node **head_a);

/*------------------------------------------------------------------------*/

/*--------------------------------- bonus --------------------------------*/

void	m_push_B(t_Node **b_Ref, t_Node **a_Ref);
void	m_push_A(t_Node **b_Ref, t_Node **a_Ref);
void	m_swap_AB(t_Node **a_ref, t_Node **b_ref);
void	m_rotate_AB(t_Node **a_ref, t_Node **b_ref);
void	m_revrotate_AB(t_Node **a_ref, t_Node **b_ref);

void	fill_list_b(char **argv, char **input, t_Node **head_a, int flag);
void	fill_list_2_b(char **input, t_Node **head_a);
void	get_input_b(int argc, char **argv, char ***input, int *flag);
int		get_input_lenght_b(t_Node *head);

/* Reads from the stdin with get_next_line. */
void	while_loop(t_Node **a_bonus, t_Node **b_bonus);

/* Checks, if the commands on stdin are valid commands. */
int		check_in(char *str);

/* Executes the commands from stdin on the stack. */
void	read_exeute(t_Node **a_bonus, t_Node **b_bonus, char *str);

/*------------------------------------------------------------------------*/

#endif
