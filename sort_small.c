/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:44:58 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/15 16:41:06 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_is_sorted(t_stack *a)
{
	t_node	*cur;
	int		i;

	if (!a || a->size < 2)
		return (1);
	cur = a->top;
	i = -1;
	while (++i < a->size - 1)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	sort_3(t_data *data)
{
	int	guard;

	if (!data || !data->a)
		return ;
	if (data->a->size == 2)
	{
		if (data->a->top->index > data->a->top->next->index)
			sa(data);
		return ;
	}
	guard = 0;
	while (!a_is_sorted(data->a) && guard++ < 6)
	{
		if (data->a->top->index > data->a->top->next->index)
			sa(data);
		if (a_is_sorted(data->a))
			break ;
		if (data->a->top->index < data->a->top->next->index)
			rra(data);
		else
			ra(data);
	}
}

static void	bring_index_to_top_and_push(t_data *data, int target_index)
{
	int	pos;
	int	half;

	if (!data || !data->a)
		return ;
	pos = get_node_position(data->a, target_index);
	if (pos < 0)
		return ;
	half = data->a->size / 2;
	if (pos <= half)
	{
		while (pos-- > 0)
			ra(data);
	}
	else
	{
		while (pos++ < data->a->size)
			rra(data);
	}
	pb(data);
}

void	sort_5(t_data *data)
{
	int	pushed;

	if (!data || !data->a)
		return ;
	if (data->a->size <= 3)
	{
		sort_3(data);
		return ;
	}
	pushed = 0;
	while (data->a->size > 3 && pushed < 2)
	{
		bring_index_to_top_and_push(data, pushed);
		pushed++;
	}
	sort_3(data);
	while (data->b->size > 0)
		pa(data);
	if (data->a->top && data->a->top->next
		&& data->a->top->index > data->a->top->next->index)
		sa(data);
}
