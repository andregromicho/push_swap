#include "push_swap.h"

void	run_adaptive_sort(t_data *data)
{
	double	disorder;

	if (!data || !data->a || data->a->size <= 1)
		return ;
		
	disorder = data->bench.disorder;

	// Regime Baixo: D < 0.2 -> Exige O(n²)
	if (disorder < 0.2)
	{
		data->bench.strategy = "Insertion Sort / Regime O(n²)";
		run_insertion_sort(data);
	}
	// Regime Médio: 0.2 <= D < 0.5 -> Exige O(n√n)
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		data->bench.strategy = "Chunk Sort (√n) / Regime O(n√n)";
		run_chunk_sort(data); // A versão com ft_sqrt que fizemos
	}
	// Regime Alto: D >= 0.5 -> Exige O(n log n)
	else
	{
		data->bench.strategy = "Radix Sort / Regime O(n log n)";
		run_radix_sort(data);
	}
}