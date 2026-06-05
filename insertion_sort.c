#include "push_swap.h"

/* Insertion Sort: algoritmo adaptativo para desordem baixa */
void	run_insertion_sort(t_data *data)
{
	int	size;
	int	pos;
	int	target_index;

	if (!data || !data->a || data->a->size <= 1)
		return ;

	// Se já está ordenado, não faz nenhuma operação
	if (compute_disorder(data->a) == 0.0)
		return ;

	// Seleção simples: move o maior elemento restante para B e depois repõe em A
	while (data->a->size > 0)
	{
		size = data->a->size;
		target_index = size - 1;
		pos = get_node_position(data->a, target_index);
		if (pos == -1)
			break ;
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(data);
		}
		else
		{
			while (pos++ < size)
				rra(data);
		}
		pb(data);
	}
	while (data->b->size > 0)
		pa(data);
}
