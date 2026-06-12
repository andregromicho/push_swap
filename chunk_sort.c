/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:39:27 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 16:45:54 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_node  *cur;

	while (data->b->size > 0)
	{
		/* compute the actual maximum index present in stack B */
		cur = data->b->top;
		target_index = cur->index;
		pos = 0;
		while (pos < data->b->size)
		{
			if (cur->index > target_index)
				target_index = cur->index;
			cur = cur->next;
			pos++;
		}
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
	if (!data || !data->a)
		return ;
	if (data->a->size <= 3)
	{
		sort_3(data);
		return ;
	}
	if (data->a->size == 5)
	{
		sort_5(data);
		return ;
	}
	chunk = ft_sqrt(data->a->size);
	push_to_b_sqrt(data, chunk);
	pull_to_a_ordered(data);
}

/* Calcula a posição de um nó com um dado índice (contando do topo) */
int	get_node_position(t_stack *stack, int target_index)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
