#include "push_swap.h"

void	run_bubble_sort(t_data *data)
{
	int	size;
	int	i;
	int	j;
	int	max_iterations;

	if (!data || !data->a || data->a->size < 2)
		return ;
	size = data->a->size;
	i = 0;
	max_iterations = size * size * 2;
	while (i < size && max_iterations > 0)
	{
		j = 0;
		while (j < size - 1 && max_iterations > 0)
		{
			if (data->a->top->index > data->a->top->next->index)
				sa(data);
			ra(data);
			j++;
			max_iterations--;
		}
		i++;
		max_iterations--;
	}
}
