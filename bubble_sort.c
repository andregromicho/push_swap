/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:20 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 16:45:54 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_bubble_sort(t_data *data)
{
	int size;
	int i;
	int j;
	int sorted;

	if (!data || !data->a || data->a->size < 2)
		return ;
	size = data->a->size;
	if (size == 5)
	{
		sort_5(data);
		return ;
	}
	i = 0;
	while (i < size)
	{
		sorted = 1;
		j = 0;
		while (j < size - 1)
		{
			if (data->a->top->index > data->a->top->next->index)
			{
				sa(data);
				sorted = 0;
			}
			ra(data);
			j++;
		}
		if (sorted)
			break ;
		i++;
	}
	/* rotate A so that smallest element (index 0) is at top */
	if (data->a->size > 0)
	{
		int pos = get_node_position(data->a, 0);
		if (pos >= 0)
		{
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
	}
}
