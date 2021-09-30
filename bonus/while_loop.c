/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:24:02 by akurz             #+#    #+#             */
/*   Updated: 2021/09/29 14:29:16 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	while_loop(t_Node **a_bonus, t_Node **b_bonus)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		else if (check_in(str) == 0)
		{
			write(2, "ERROR\n", 6);
			exit(0);
		}
		else
			read_exeute(a_bonus, b_bonus, str);
	}
}
