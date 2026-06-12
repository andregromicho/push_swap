/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algorytm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:12 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 17:29:18 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Auxiliar estática para selecionar e executar a estratégia correta
static void	execute_strategy(t_data *data)
{
	if (data->flags.simple)
	{
		data->bench.strategy = "Simple";
		data->bench.complexity = "O(n²)";
		run_bubble_sort(data);
	}
	else if (data->flags.medium)
	{
		data->bench.strategy = "Medium";
		data->bench.complexity = "O(n√n)";
		run_chunk_sort(data);
	}
	else if (data->flags.complex)
	{
		data->bench.strategy = "Complex";
		data->bench.complexity = "O(n log n)";
		run_radix_sort(data);
	}
	else
	{
		data->bench.strategy = "Adaptive";
		run_adaptive_sort(data);
	}
}

// O Hub Principal
void	algorithm_hub(t_data *data)
{
	data->bench.disorder = compute_disorder(data->a) * 100.0;
	if (data->bench.disorder == 0.0)
	{
		data->bench.strategy = "None (Already Sorted)";
		data->bench.complexity = "O(1)";
		return ;
	}
	execute_strategy(data);
}
