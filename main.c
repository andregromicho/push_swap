/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:33:28 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/12 16:45:54 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Liberta toda a memória alocada da stack */
static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->top;
	if (current)
	{
		t_node *start = current;
		while (current && (tmp = current->next, 1))
		{
			free(current);
			current = tmp;
			if (current == start)
				break ;
		}
	}
	free(stack);
}

/* Liberta toda a estrutura de dados e printa o relatório se necessário */
static void	cleanup_and_exit(t_data *data, int exit_code)
{
	if (!data)
		return ;
	if (data->flags.bench)
		print_bench_report(&data->bench);
	if (data->a)
		free_stack(data->a);
	if (data->b)
		free_stack(data->b);
	free(data);
	exit(exit_code);
}

/* Inicializa as stacks vazias */
static t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = ft_calloc(1, sizeof(t_stack));
	if (!data)
		return (NULL);
	data->b = ft_calloc(1, sizeof(t_stack));
	if (!data->b)
	{
		free(data->a);
		free(data);
		return (NULL);
	}
	data->bench.strategy = "";
	data->bench.complexity = "";
	return (data);
}

/* #include <stdio.h>
void    print_stacks_debug(t_data *data)
{
    t_node  *current;
    int     i;

    if (!data)
        return ;
    
    // --- Print Stack A ---
    printf("--- STACK A (Size: %d) ---\n", data->a->size);
    if (data->a && data->a->top)
    {
        current = data->a->top;
        i = 0;
        while (i < data->a->size)
        {
            printf("[Node %d] Value: %10d | Index: %d\n", i, current->value, current->index);
            current = current->next;
            i++;
        }
    }
    else
        printf("(Empty)\n");

    // --- Print Stack B ---
    printf("\n--- STACK B (Size: %d) ---\n", data->b->size);
    if (data->b && data->b->top)
    {
        current = data->b->top;
        i = 0;
        while (i < data->b->size)
        {
            printf("[Node %d] Value: %10d | Index: %d\n", i, current->value, current->index);
            current = current->next;
            i++;
        }
    }
    else
        printf("(Empty)\n");
    printf("---------------------------\n\n");
} */

/* Função principal */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (1);
	data = init_data();
	if (!data)
		return (1);
	if (!process_input(data, argc, argv))
		cleanup_and_exit(data, 1);
	rank_stack(data->a);
	if (!validate_flags(data))
		cleanup_and_exit(data, 1);
	data->bench.disorder = compute_disorder(data->a) * 100.0;
	algorithm_hub(data);
/* 	print_stacks_debug(data);
 */	cleanup_and_exit(data, 0);
	return (0);
}
