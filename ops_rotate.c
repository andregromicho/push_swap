/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:59 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/10 14:54:29 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_top(t_stack *stack)
{
	if (!stack || stack->size < 2 || !stack->top)
		return ;
	stack->top = stack->top->next;
}

void	ra(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	rotate_top(data->a);
	if (!data->flags.bench)
		write(1, "ra\n", 3);
	if (data->flags.bench)
	{
		data->bench.op_count[RA]++;
		data->bench.total_ops++;
	}
}

void	rb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	rotate_top(data->b);
	if (!data->flags.bench)
		write(1, "rb\n", 3);
	if (data->flags.bench)
	{
		data->bench.op_count[RB]++;
		data->bench.total_ops++;
	}
}

void	rr(t_data *data)
{
	int	rotated;

	if (!data)
		return ;
	rotated = 0;
	if (data->a && data->a->size >= 2)
	{
		rotate_top(data->a);
		rotated = 1;
	}
	if (data->b && data->b->size >= 2)
	{
		rotate_top(data->b);
		rotated = 1;
	}
	if (rotated)
	{
		if (!data->flags.bench)
			write(1, "rr\n", 3);
		if (data->flags.bench)
		{
			data->bench.op_count[RR]++;
			data->bench.total_ops++;
		}
	}
}
