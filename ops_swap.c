/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:54 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/10 14:53:35 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	if (stack->size == 2)
	{
		stack->top = second;
		return ;
	}
	last = first->prev;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = last;
	last->next = second;
	stack->top = second;
}

void	sa(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	swap_top(data->a);
	if (!data->flags.bench)
		write(1, "sa\n", 3);
	if (data->flags.bench)
	{
		data->bench.op_count[SA]++;
		data->bench.total_ops++;
	}
}

void	sb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	swap_top(data->b);
	if (!data->flags.bench)
		write(1, "sb\n", 3);
	if (data->flags.bench)
	{
		data->bench.op_count[SB]++;
		data->bench.total_ops++;
	}
}

void	ss(t_data *data)
{
	swap_top(data->a);
	swap_top(data->b);
	if (!data->flags.bench)
		write(1, "ss\n", 3);
	if (data->flags.bench)
	{
		data->bench.op_count[SS]++;
		data->bench.total_ops++;
	}
}
