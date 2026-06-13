/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:44:58 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:46:14 by goperez-         ###   ########.fr       */
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
