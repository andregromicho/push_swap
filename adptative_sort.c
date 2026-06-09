/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adptative_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:22 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/09 20:53:22 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_adaptive_sort(t_data *data)
{
	double	disorder;

	if (!data || !data->a || data->a->size <= 1)
		return ;
	disorder = data->bench.disorder;
	if (disorder < 0.2)
	{
		data->bench.strategy = "Insertion Sort";
		data->bench.complexity = "O(n²)";
		run_insertion_sort(data);
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
		data->bench.complexity = "O(n * k)";
		run_radix_sort(data);
	}
}
