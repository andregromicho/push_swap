/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:20 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/15 16:53:16 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	align_stack_a(t_data *data)
{
	int	pos;

	if (!data->a || data->a->size <= 0)
		return ;
	pos = get_node_position(data->a, 0);
	if (pos < 0)
		return ;
	if (pos <= data->a->size / 2)
	{
		while (pos-- > 0)
			ra(data);
	}
	else
	{
		while (pos++ < data->a->size)
			rra(data);
	}
}

static void	execute_bubble_loop(t_data *data, int size)
{
	int	i;
	int	j;
	int	sorted;

	i = -1;
	while (++i < size)
	{
		sorted = 1;
		j = -1;
		while (++j < size - 1)
		{
			if (data->a->top->index > data->a->top->next->index)
			{
				sa(data);
				sorted = 0;
			}
			ra(data);
		}
		if (sorted)
			break ;
	}
}

void	run_bubble_sort(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	if (data->a->size <= 3)
	{
		sort_3(data);
		return ;
	}
	else if (data->a->size <= 5)
	{
		sort_5(data);
		return ;
	}
	execute_bubble_loop(data, data->a->size);
	align_stack_a(data);
}
