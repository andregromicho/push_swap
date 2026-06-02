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
		// Se for da metade inferior do bloco atual: empurra e joga para a base de B
		if (data->a->top->index <= i)
		{
			pb(data);
			rb(data);
			i++;
		}
		// Se for da metade superior do bloco atual: apenas empurra para o topo de B
		else if (data->a->top->index <= (i + chunk))
		{
			pb(data);
			i++;
		}
		// Se não pertencer a este bloco, roda A para procurar
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
		target_index = data->b->size - 1; // O maior índice que falta recuperar
		pos = get_node_position(data->b, target_index); // Usa a função que fizemos antes
		
		// Roda a stack B até que o elemento com o 'target_index' chegue ao topo
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
		pa(data); // Devolve à Stack A já ordenado
	}
}

// Função Principal do teu Hub
void	run_chunk_sort(t_data *data)
{
	int	chunk;

	if (!data || !data->a || data->a->size <= 3)
		return;
		
	// Define o nome da estratégia para o relatório do teu modo benchmark
	data->bench.strategy = "Chunk Sort / O(n√n)";
	
	// 1. Calcula o tamanho do bloco baseado na raiz quadrada
	chunk = ft_sqrt(data->a->size);
	
	// 2. Executa as duas fases do algoritmo
	push_to_b_sqrt(data, chunk);
	pull_to_a_ordered(data);
}