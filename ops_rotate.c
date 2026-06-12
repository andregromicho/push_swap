/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:59 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 17:10:02 by goperez-         ###   ########.fr       */
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
	emit_op(data, "ra\n", 3, RA);
}

void	rb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	rotate_top(data->b);
	emit_op(data, "rb\n", 3, RB);
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
		emit_op(data, "rr\n", 3, RR);
	}
}
