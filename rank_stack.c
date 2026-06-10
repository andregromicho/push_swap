/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:42 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/09 20:52:43 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Estrutura auxiliar para sorting durante ranking */
typedef struct s_rank_pair
{
	int	value;
	int	pos;
}	t_rank_pair;

/* Comparador para qsort */
static int	compare_rank(const void *a, const void *b)
{
	return (((t_rank_pair *)a)->value - ((t_rank_pair *)b)->value);
}

/* Faz ranking dos valores da stack: o menor fica com índice 0, o próximo com 1, etc. */
void	rank_stack(t_stack *stack)
{
	t_rank_pair	*pairs;
	t_node		*current;
	int			i;
	int			size;

	if (!stack || !stack->top || stack->size <= 1)
		return ;
	
	size = stack->size;
	
	// Cria um array com pares (valor, posição)
	pairs = malloc(sizeof(t_rank_pair) * size);
	if (!pairs)
		return ;
	
	current = stack->top;
	i = 0;
	while (i < size)
	{
		pairs[i].value = current->value;
		pairs[i].pos = i;
		current = current->next;
		i++;
	}
	
	// Ordena por valor
	qsort(pairs, size, sizeof(t_rank_pair), compare_rank);
	
	// Cria um mapa de índices (valor original -> novo índice)
	int *index_map = malloc(sizeof(int) * size);
	if (!index_map)
	{
		free(pairs);
		return ;
	}
	
	for (i = 0; i < size; i++)
		index_map[pairs[i].pos] = i;
	
	// Aplica os novos índices à stack
	current = stack->top;
	i = 0;
	while (i < size)
	{
		current->index = index_map[i];
		current = current->next;
		i++;
	}
	
	free(pairs);
	free(index_map);
}
