/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:22 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:24:01 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_small_sort(t_data *data)
{
	if (data->a->size <= 3)
	{
		data->bench.complexity = "O(1)";
		sort_3(data);
	}
	else if (data->a->size == 5)
	{
		data->bench.complexity = "O(n)";
		sort_5(data);
	}
}

void	run_adaptive_sort(t_data *data)
{
	double	disorder;

	if (!data || !data->a || data->a->size <= 1)
		return ;
	if (data->a->size <= 5)
	{
		run_small_sort(data);
		return ;
	}
	disorder = data->bench.disorder;
	if (disorder < 0.2)
	{
		data->bench.complexity = "O(n²)";
		run_bubble_sort(data);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		data->bench.complexity = "O(n√n)";
		run_chunk_sort(data);
	}
	else
	{
		data->bench.complexity = "O(n log n)";
		run_radix_sort(data);
	}
}
