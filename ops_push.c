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

static void	push_top(t_stack *dest, t_stack *src)
{
	t_node	*node_to_move;

	if (!src || src->size == 0 || !src->top)
		return ;
	node_to_move = detach_top(src);
	attach_top(dest, node_to_move);
}

void	pa(t_data *data)
{
	t_node	*node;

	// 1. O enunciado exige: não faz nada se a Stack B estiver vazia
	if (!data || !data->b || data->b->size == 0 || !data->b->top)
		return ;

	// 2. Move fisicamente o nó na memória (circular duplamente ligada)
	node = detach_top(data->b);
	attach_top(data->a, node);

	// 3. Se NÃO estiver em modo silencioso, imprime no stdout
	if (!data->flags.silent)
		write(1, "pa\n", 3);

	// 4. Se o modo benchmark estiver ativo, atualiza a contabilidade
	if (data->flags.bench)
	{
		data->bench.op_count[PA]++;
		data->bench.total_ops++;
	}
}

void	pb(t_data *data)
{
	t_node	*node;

	// 1. Segurança: não faz nada se a Stack A estiver vazia
	if (!data || !data->a || data->a->size == 0 || !data->a->top)
		return ;

	// 2. Move fisicamente o nó na memória
	node = detach_top(data->a);
	attach_top(data->b, node);

	// 3. Se NÃO estiver em modo silencioso, imprime no stdout
	if (!data->flags.silent)
		write(1, "pb\n", 3);

	// 4. Se o modo benchmark estiver ativo, atualiza a contabilidade
	if (data->flags.bench)
	{
		data->bench.op_count[PB]++;
		data->bench.total_ops++;
	}
}