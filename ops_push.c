/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:02 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:36:41 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Remove o nó do topo da stack de origem e ajusta os vizinhos
static t_node	*detach_top(t_stack *src)
{
	t_node	*node;

	node = src->top;
	if (src->size == 1)
		src->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		src->top = node->next;
	}
	src->size--;
	return (node);
}

// Encaixa o nó no topo da stack de destino
static void	attach_top(t_stack *dest, t_node *node)
{
	if (dest->size == 0)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = dest->top;
		node->prev = dest->top->prev;
		dest->top->prev->next = node;
		dest->top->prev = node;
	}
	dest->top = node;
	dest->size++;
}

void	pa(t_data *data)
{
	t_node	*node;

	if (!data || !data->b || data->b->size == 0 || !data->b->top)
		return ;
	node = detach_top(data->b);
	attach_top(data->a, node);
	emit_op(data, "pa\n", 3, PA);
}

void	pb(t_data *data)
{
	t_node	*node;

	if (!data || !data->a || data->a->size == 0 || !data->a->top)
		return ;
	node = detach_top(data->a);
	attach_top(data->b, node);
	emit_op(data, "pb\n", 3, PB);
}
