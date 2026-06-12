/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:54 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 17:10:02 by goperez-         ###   ########.fr       */
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
	emit_op(data, "sa\n", 3, SA);
}

void	sb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	swap_top(data->b);
	emit_op(data, "sb\n", 3, SB);
}

void	ss(t_data *data)
{
	swap_top(data->a);
	swap_top(data->b);
	emit_op(data, "ss\n", 3, SS);
}
