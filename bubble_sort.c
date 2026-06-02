#include "push_swap.h"

void	run_bubble_sort(t_data *data)
{
	int	size;
	int	i;
	int	swapped;

	// 1. Validar se há elementos suficientes para ordenar
	if (!data || !data->a || data->a->size < 2)
		return ;
	size = data->a->size;
	swapped = 1;
	// 2. O ciclo principal continua até que uma volta inteira ocorra SEM trocas
	while (swapped)
	{
		swapped = 0;
		i = 0;
		// 3. Fazemos uma passagem pela stack (fazendo size - 1 comparações)
		while (i < size - 1)
		{
			// Compara o elemento do topo atual com o que está logo abaixo dele
			if (data->a->top->index > data->a->top->next->index)
			{
				sa(data);    // Chamas a operação passando apenas o contentor 'data'
				swapped = 1; // Marca que houve uma alteração nesta passagem
			}
			ra(data);        // Roda a stack para trazer os próximos números ao topo
			i++;
		}
		// 4. No fim da passagem, damos mais uma rotação para que a stack 
		// volte exatamente à sua posição original antes de reavaliar o 'while'
		ra(data);
	}
}