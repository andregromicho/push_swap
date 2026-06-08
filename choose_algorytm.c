#include "push_swap.h"

#include "push_swap.h"

//Auxiliar estática para selecionar e executar a estratégia correta
static void	execute_strategy(t_data *data)
{
	if (data->flags.simple)
	{
		data->bench.strategy = "Bubble Sort";
		data->bench.complexity = "O(n²)";
		run_bubble_sort(data);
	}
	else if (data->flags.medium)
	{
		data->bench.strategy = "Chunk Sort";
		data->bench.complexity = "O(n√n)";
		run_chunk_sort(data);
	}
	else if (data->flags.complex)
	{
		data->bench.strategy = "Radix Sort";
		data->bench.complexity = "O(n log n)";
		run_radix_sort(data);
	}
	else
		run_adaptive_sort(data);
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
