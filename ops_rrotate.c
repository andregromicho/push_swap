/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:57 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:37:00 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_top(t_stack *stack)
{
	if (!stack || stack->size < 2 || !stack->top)
		return ;
	stack->top = stack->top->prev;
}

void	rra(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	reverse_rotate_top(data->a);
	emit_op(data, "rra\n", 4, RRA);
}

void	rrb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	reverse_rotate_top(data->b);
	emit_op(data, "rrb\n", 4, RRB);
}

void	rrr(t_data *data)
{
	int	rotated;

	if (!data)
		return ;
	rotated = 0;
	if (data->a && data->a->size >= 2)
	{
		reverse_rotate_top(data->a);
		rotated = 1;
	}
	if (data->b && data->b->size >= 2)
	{
		reverse_rotate_top(data->b);
		rotated = 1;
	}
	if (rotated)
	{
		emit_op(data, "rrr\n", 4, RRR);
	}
}
