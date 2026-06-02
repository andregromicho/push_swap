#include "push_swap.h"

static void	rotate_top(t_stack *stack)
{
	// Segurança: Para rodar, precisamos de pelo menos 2 elementos
	if (!stack || stack->size < 2 || !stack->top)
		return ;

	// O topo simplesmente avança para o próximo nó. É uma operação O(1)!
	stack->top = stack->top->next;
}

void	ra(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;

	rotate_top(data->a);

	if (!data->flags.silent)
		write(1, "ra\n", 3);

	if (data->flags.bench)
	{
		data->bench.op_count[RA]++;
		data->bench.total_ops++;
	}
}

void	rb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;

	rotate_top(data->b);

	if (!data->flags.silent)
		write(1, "rb\n", 3);

	if (data->flags.bench)
	{
		data->bench.op_count[RB]++;
		data->bench.total_ops++;
	}
}

void	rr(t_data *data)
{
	int	rotated;

	if (!data)
		return ;
	rotated = 0;
	// Ativa o silenciador para ra e rb não escreverem no terminal
	data->flags.silent = 1;

	if (data->a && data->a->size >= 2)
	{
		ra(data);
		rotated = 1;
	}
	if (data->b && data->b->size >= 2)
	{
		rb(data);
		rotated = 1;
	}

	// Desativa o silenciador
	data->flags.silent = 0;

	// Se pelo menos uma stack rodou, conta como a operação combinada 'rr'
	if (rotated)
	{
		if (!data->flags.silent)
			write(1, "rr\n", 3);

		if (data->flags.bench)
		{
			data->bench.op_count[RR]++;
			data->bench.total_ops++;
		}
	}
}