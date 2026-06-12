/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:45 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 17:27:19 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Função para calcular quantos bits precisamos para o maior índice
static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	run_radix_sort(t_data *data)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

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
	size = data->a->size;
	max_bits = get_max_bits(size);
	i = 0;
	// Loop para cada bit (da direita para a esquerda)
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			// Se o bit atual for 0, vai para B. Se for 1, roda em A.
			if (((data->a->top->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
			j++;
		}
		// Recupera tudo o que ficou no "balde" B para manter a ordem estável
		while (data->b->size > 0)
			pa(data);
		i++;
	}
}