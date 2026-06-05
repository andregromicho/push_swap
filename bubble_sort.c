#include "push_swap.h"

void	run_bubble_sort(t_data *data)
{
	int	size;
	int	i;
	int	j;
	int	max_iterations;

	// 1. Validar se há elementos suficientes para ordenar
	if (!data || !data->a || data->a->size < 2)
		return ;
	
	size = data->a->size;
	i = 0;
	max_iterations = size * size * 2;  // Proteção contra loops infinitos
	
	// 2. Simples: faz tamanho² operações de ordenação (força bruta)
	while (i < size && max_iterations > 0)
	{
		j = 0;
		while (j < size - 1 && max_iterations > 0)
		{
			// Se não está em ordem, troca
			if (data->a->top->index > data->a->top->next->index)
				sa(data);
			
			// Move para o próximo
			ra(data);
			j++;
			max_iterations--;
		}
		i++;
		max_iterations--;
	}
}