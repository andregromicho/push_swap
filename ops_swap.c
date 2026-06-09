/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:54 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/09 20:52:55 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	// 1. Segurança: Se tiver menos de 2 elementos, não há nada para trocar
	if (!stack || stack->size < 2)
		return ;

	first = stack->top;
	second = first->next;

	// 2. CASO ESPECIAL: Se a stack tiver exatamente 2 elementos
	if (stack->size == 2)
	{
		stack->top = second; // Numa roda de 2, basta mudar quem é o topo
		return ;
	}

	// 3. CASO GERAL: 3 ou mais elementos
	last = first->prev; // Guardamos o último elemento da stack (a base)

	// Ligar o primeiro nó ao que vinha depois do segundo
	first->next = second->next;
	second->next->prev = first;

	// Inverter a ligação entre o primeiro e o segundo
	second->next = first;
	first->prev = second;

	// Ligar o segundo nó (novo topo) ao último elemento da stack
	second->prev = last;
	last->next = second;

	// 4. Atualizar o ponteiro principal da stack para o novo topo
	stack->top = second;
}

void	sa(t_data *data)
{
	if (!data || !data->a || data->a->size < 2)
		return ;

	// 1. Move fisicamente na memória
	swap_top(data->a);

	// 2. Se NÃO estiver em modo silencioso, imprime no stdout
	if (!data->flags.silent)
		write(1, "sa\n", 3);

	// 3. Se o modo bench estiver ativo, regista nas estatísticas
	if (data->flags.bench)
	{
		data->bench.op_count[SA]++;
		data->bench.total_ops++;
	}
}

void	sb(t_data *data)
{
	if (!data || !data->b || data->b->size < 2)
		return ;
	
	swap_top(data->b);

	if (!data->flags.silent)
		write(1, "sb\n", 3);
	if (data->flags.bench)
	{
		data->bench.op_count[SB]++;
		data->bench.total_ops++;
	}
}

void	ss(t_data *data)
{
	// 1. Ativa o silenciado
	// 2. Chama as operações normais (elas movem a memória e contam o bench se ativo, mas não imprimem nada!)
	swap_top(data->a);
	swap_top(data->b);
	// 3. Desativa o silenciado
	// 4. Imprime ou contabiliza o comando combinado 'ss'
	if (!data->flags.silent) // Garante consistência de fluxo
		write(1, "ss\n", 3);
	
	if (data->flags.bench)
	{
		data->bench.op_count[SS]++;
		data->bench.total_ops++;
	}
}

