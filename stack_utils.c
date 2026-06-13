/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:51:58 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:49:07 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->top || stack->size == 0)
		return (0);
	current = stack->top;
	while (1)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		if (current == stack->top)
			break ;
	}
	return (0);
}

int	add_back_circular(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*last_node;

	if (!stack)
		return (0);
	new_node = create_node(value, stack->size);
	if (!new_node)
		return (0);
	if (stack->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->top = new_node;
	}
	else
	{
		last_node = stack->top->prev;
		new_node->next = stack->top;
		new_node->prev = last_node;
		last_node->next = new_node;
		stack->top->prev = new_node;
	}
	stack->size++;
	return (1);
}
