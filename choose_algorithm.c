/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:12 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:31:22 by goperez-         ###   ########.fr       */
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

/* Calcula a posição de um nó com um dado índice (contando do topo) */
int	get_node_position(t_stack *stack, int target_index)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
