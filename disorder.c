#include "push_swap.h"

/* Auxiliar para o loop interior: conta os mistakes a partir do nó atual */
static void	count_pairs_and_mistakes(t_stack *a, t_node *curr_i,
				long *total_pairs, long *mistakes)
{
	t_node	*curr_j;

	curr_j = curr_i->next;
	// Loop interior: simula 'for j from i+1 to size(a)-1'
	while (curr_j != a->top)
	{
		(*total_pairs)++;
		// Se um número maior aparece antes de um menor, é um mistake
		if (curr_i->index > curr_j->index)
			(*mistakes)++;
		curr_j = curr_j->next;
	}
}

/* Calcula a desordem da stack entre 0.0 (ordenada) e 1.0 (pior ordem possível) */
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
	// Loop exterior: simula 'for i from 0 to size(a)-1'
	while (1)
	{
		count_pairs_and_mistakes(a, curr_i, &total_pairs, &mistakes);
		curr_i = curr_i->next;
		// Quando o ponteiro i voltar ao topo, analisámos todos os pares
		if (curr_i == a->top)
			break ;
	}
	if (total_pairs == 0)
		return (0.0);
	// Retorna o rácio exato pedido no guião VI.3.2
	return ((double)mistakes / total_pairs);
}