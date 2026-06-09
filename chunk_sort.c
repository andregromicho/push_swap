#include "push_swap.h"

// Calcula a raiz quadrada aproximada para definir o tamanho dinâmico do bloco
static int	ft_sqrt(int num)
{
	int	i;

	i = 1;
	while (i * i < num)
		i++;
	return (i);
}

// Fase 1: Empurra de A para B usando a janela deslizante da raiz quadrada
static void	push_to_b_sqrt(t_data *data, int chunk)
{
	int	i;

	i = 0;
	while (data->a->size > 0)
	{
		if (data->a->top->index <= i)
		{
			pb(data);
			rb(data);
			i++;
		}
		else if (data->a->top->index <= (i + chunk))
		{
			pb(data);
			i++;
		}
		else
			ra(data);
	}
}

// Fase 2: Puxa de B para A trazendo sempre o maior elemento restante
static void	pull_to_a_ordered(t_data *data)
{
	int	target_index;
	int	pos;

	while (data->b->size > 0)
	{
		target_index = data->b->size - 1;
		pos = get_node_position(data->b, target_index);
		if (pos <= data->b->size / 2)
		{
			while (data->b->top->index != target_index)
				rb(data);
		}
		else
		{
			while (data->b->top->index != target_index)
				rrb(data);
		}
		pa(data);
	}
}

// Função Principal do teu Hub
void	run_chunk_sort(t_data *data)
{
	int	chunk;

	if (!data || !data->a || data->a->size <= 3)
		return ;
	chunk = ft_sqrt(data->a->size);
	push_to_b_sqrt(data, chunk);
	pull_to_a_ordered(data);
}
