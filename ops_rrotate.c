#include "push_swap.h"

static void	reverse_rotate_top(t_stack *stack)
{
	if (!stack || stack->size < 2 || !stack->top)
		return ;
	stack->top = stack->top->prev;
}

void	rra(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;
	reverse_rotate_top(data->a);
	if (!data->flags.bench)
		write(1, "rra\n", 4);
	if (data->flags.bench)
	{
		data->bench.op_count[RRA]++;
		data->bench.total_ops++;
	}
}

void	rrb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	reverse_rotate_top(data->b);
	if (!data->flags.bench)
		write(1, "rrb\n", 4);
	if (data->flags.bench)
	{
		data->bench.op_count[RRB]++;
		data->bench.total_ops++;
	}
}

void	rrr(t_data *data)
{
	int	rotated;

	if (!data)
		return ;
	rotated = 0;
	if (data->a && data->a->size >= 2)
	{
		reverse_rotate_top(data->a);
		rotated = 1;
	}
	if (data->b && data->b->size >= 2)
	{
		reverse_rotate_top(data->b);
		rotated = 1;
	}
	if (rotated)
	{
		if (!data->flags.bench)
			write(1, "rrr\n", 4);
		if (data->flags.bench)
		{
			data->bench.op_count[RRR]++;
			data->bench.total_ops++;
		}
	}
}
