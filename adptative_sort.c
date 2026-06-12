/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adptative_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:22 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 16:45:54 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_adaptive_sort(t_data *data)
{
	double	disorder;

	if (!data || !data->a || data->a->size <= 1)
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
	disorder = data->bench.disorder;
	if (disorder < 0.2)
	{
		data->bench.strategy = "Bubble Sort";
		data->bench.complexity = "O(n²)";
		run_bubble_sort(data);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		data->bench.strategy = "Chunk Sort";
		data->bench.complexity = "O(n√n)";
		run_chunk_sort(data);
	}
	else
	{
		data->bench.strategy = "Radix Sort";
		data->bench.complexity = "O(n log n)";
		run_radix_sort(data);
	}
}
