/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:46:21 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:47:35 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
