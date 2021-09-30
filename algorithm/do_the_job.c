/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:20:36 by akurz             #+#    #+#             */
/*   Updated: 2021/09/28 14:51:33 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_the_job_3(t_Node **b_ref, t_Force force, t_job job)
{
	if (force.element > force.len_b / 2)
	{
		force.element = force.len_b - force.element;
		while (job.y < force.element)
		{
			revrotate_B(b_ref, 0);
			job.y++;
		}
	}
	else
	{
		while (job.y < force.element)
		{
			rotate_B(b_ref, 0);
			job.y++;
		}
	}
}

void	do_the_job_2(t_Node **a_ref, t_Node **b_ref, t_Force force, t_job job)
{
	if (force.insertion_var > job.len_a / 2)
	{
		force.insertion_var = job.len_a - force.insertion_var;
		while (job.x < force.insertion_var)
		{
			revrotate_A(a_ref, 0);
			job.x++;
		}
	}
	else
	{
		while (job.x < force.insertion_var)
		{
			rotate_A(a_ref, 0);
			job.x++;
		}
	}
	do_the_job_3(b_ref, force, job);
}

void	double_rotate(t_Node **a_ref, t_Node **b_ref, t_Force force, t_job *job)
{
	while ((job->x < force.insertion_var) && (job->y < force.element))
	{
		rotate_AB(a_ref, b_ref);
		job->x++;
		job->y++;
	}
}

void	do_the_job(t_Node **a_ref, t_Node **b_ref, t_Force force)
{
	t_job	job;

	job.y = 0;
	job.x = 0;
	job.len_a = get_input_lenght(*a_ref);
	if ((force.insertion_var > job.len_a / 2)
		&& (force.element > force.len_b / 2))
	{
		while ((job.x < job.len_a - force.insertion_var)
			&& (job.y < force.len_b - force.element))
		{
			revrotate_AB(a_ref, b_ref);
			job.x++;
			job.y++;
		}
	}
	else if ((force.insertion_var < job.len_a / 2)
		&& (force.element < force.len_b / 2))
		double_rotate(a_ref, b_ref, force, &job);
	do_the_job_2(a_ref, b_ref, force, job);
	push_A(b_ref, a_ref);
}
