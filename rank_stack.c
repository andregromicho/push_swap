/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:42 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/11 17:59:24 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Helper function to sort the pairs array using bubble sort.
*/
static void	sort_pairs(t_rank_pair *pairs, int size)
{
	int			i;
	int			j;
	t_rank_pair	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (pairs[j].value > pairs[j + 1].value)
			{
				tmp = pairs[j];
				pairs[j] = pairs[j + 1];
				pairs[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
** Fills the index map and applies the ranks to the stack nodes.
*/
static void	apply_ranks(t_stack *stack, t_rank_pair *pairs, int size)
{
	t_node	*current;
	int		*index_map;
	int		i;

	index_map = malloc(sizeof(int) * size);
	if (!index_map)
		return ;
	i = 0;
	while (i < size)
	{
		index_map[pairs[i].pos] = i;
		i++;
	}
	current = stack->top;
	i = 0;
	while (i < size)
	{
		current->index = index_map[i];
		current = current->next;
		i++;
	}
	free(index_map);
}

/*
** Ranks the stack values so that the smallest becomes 0, next 1, etc.
*/
void	rank_stack(t_stack *stack)
{
	t_rank_pair	*pairs;
	t_node		*current;
	int			i;
	int			size;

	if (!stack || !stack->top || stack->size <= 1)
		return ;
	size = stack->size;
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
	sort_pairs(pairs, size);
	apply_ranks(stack, pairs, size);
	free(pairs);
}
