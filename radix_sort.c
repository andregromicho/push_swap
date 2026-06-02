#include "push_swap.h"

// Função para calcular quantos bits precisamos para o maior índice
static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	run_radix_sort(t_data *data)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	if (!data || !data->a || data->a->size <= 3)
		return ;
	// Regista a estratégia nas estatísticas do teu benchmark
	data->bench.strategy = "Radix Sort (Binário) / O(n * k)";
	size = data->a->size;
	max_bits = get_max_bits(size);
	i = 0;
	// Loop para cada bit (da direita para a esquerda)
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			// Se o bit atual for 0, vai para B. Se for 1, roda em A.
			if (((data->a->top->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
			j++;
		}
		// Recupera tudo o que ficou no "balde" B para manter a ordem estável
		while (data->b->size > 0)
			pa(data);
		i++;
	}
}