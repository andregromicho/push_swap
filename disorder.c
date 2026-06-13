/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:08 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:31:41 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Auxiliar para o loop interior: conta os mistakes a partir do nó atual */
static void	count_pairs_and_mistakes(t_stack *a, t_node *curr_i,
				long *total_pairs, long *mistakes)
{
	t_node	*curr_j;

	curr_j = curr_i->next;
	while (curr_j != a->top)
	{
		(*total_pairs)++;
		if (curr_i->index > curr_j->index)
			(*mistakes)++;
		curr_j = curr_j->next;
	}
}

/* Calcula a desordem da stack entre 0.0 e 1.0 */
double	compute_disorder(t_stack *a)
{
	t_node	*curr_i;
	long	mistakes;
	long	total_pairs;

	if (!a || a->size <= 1 || !a->top)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	curr_i = a->top;
	while (1)
	{
		count_pairs_and_mistakes(a, curr_i, &total_pairs, &mistakes);
		curr_i = curr_i->next;
		if (curr_i == a->top)
			break ;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
