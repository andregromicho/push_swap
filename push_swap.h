/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:17:56 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/15 16:33:22 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef enum e_ops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_ops;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_bench
{
	double	disorder;
	char	*strategy;
	char	*complexity;
	int		total_ops;
	int		op_count[11];
}	t_bench;

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_bench	bench;
}	t_data;

typedef struct s_rank_pair
{
	int	value;
	int	pos;
}	t_rank_pair;

int		process_input(t_data *data, int argc, char **argv);
int		validate_flags(t_data *data);
void	free_matrix(char **matrix);

/* Stack utilities */
int		has_duplicate(t_stack *stack, int value);
int		add_back_circular(t_stack *stack, int value);
int		get_node_position(t_stack *stack, int target_index);
void	rank_stack(t_stack *stack);

/* Stack Operations */
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* Sort Algorithms */
void	algorithm_hub(t_data *data);
void	run_bubble_sort(t_data *data);
void	run_chunk_sort(t_data *data);
void	run_radix_sort(t_data *data);
void	run_adaptive_sort(t_data *data);

void	sort_3(t_data *data);
void	sort_5(t_data *data);

/* Disorder Calculator */
double	compute_disorder(t_stack *a);

/* Benchmark e output */
void	print_disorder_fd(double disorder, int fd);
void	print_bench_report(t_bench *bench);
void	emit_op(struct s_data *data, const char *op, int len, int op_index);

#endif
