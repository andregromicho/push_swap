#include "push_swap.h"

/* Insertion Sort: Algoritmo para lidar com desordem baixa (D < 0.2) */
void	run_insertion_sort(t_data *data)
{
	int	size;
	int	i;
	int	j;

	if (!data || !data->a || data->a->size <= 1)
		return ;
	
	size = data->a->size;
	i = 1;
	
	// Loop para cada elemento da stack (começando do segundo)
	while (i < size)
	{
		j = 0;
		// Procura a posição correta para inserir o elemento atual
		while (j < i)
		{
			// Se o elemento no topo é maior que o que está em posição i
			// precisamos de o mover para trás
			if (data->a->top->index > data->a->top->next->index)
				sa(data);
			
			ra(data);
			j++;
		}
		i++;
	}
	
	// Roda a stack para deixá-la na posição original
	while (data->a->size > 0 && data->a->top->index != 0)
		ra(data);
}
