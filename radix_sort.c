/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:45 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:44:16 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	process_bit_pass(t_data *data, int bit, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((data->a->top->index >> bit) & 1) == 0)
			pb(data);
		else
			ra(data);
		j++;
	}
}

void	run_radix_sort(t_data *data)
{
	int	size;
	int	max_bits;
	int	i;

	if (!data || !data->a)
		return ;
	if (data->a->size <= 3)
	{
		sort_3(data);
		return ;
	}
	if (data->a->size == 5)
	{
		sort_5(data);
		return ;
	}
	size = data->a->size;
	max_bits = get_max_bits(size);
	i = -1;
	while (++i < max_bits)
	{
		process_bit_pass(data, i, size);
		while (data->b->size > 0)
			pa(data);
	}
}
