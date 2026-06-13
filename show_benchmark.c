/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_benchmark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:52:03 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/13 12:44:41 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder_fd(double disorder, int fd)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)disorder;
	decimal_part = (int)((disorder - integer_part) * 100);
	if (decimal_part < 0)
		decimal_part *= -1;
	ft_putnbr_fd(integer_part, fd);
	write(fd, ".", 1);
	if (decimal_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal_part, fd);
	write(fd, "%\n", 2);
}

/* Auxiliar para imprimir os dados gerais do benchmark */
static void	print_bench_meta(t_bench *bench)
{
	ft_putstr_fd("\n========== PUSH_SWAP BENCHMARK REPORT ==========\n", 2);
	ft_putstr_fd("Computed Disorder      : ", 2);
	print_disorder_fd(bench->disorder, 2);
	ft_putstr_fd("Strategy Used          : ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd("\nComplexity Class       : ", 2);
	ft_putstr_fd(bench->complexity, 2);
	ft_putstr_fd("\nTotal Operations       : ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n------------------------------------------------\n", 2);
}

/* Auxiliar para imprimir os contadores individuais de cada operação */
static void	print_bench_ops(t_bench *bench)
{
	ft_putstr_fd("  sa : ", 2);
	ft_putnbr_fd(bench->op_count[SA], 2);
	ft_putstr_fd(" |  sb : ", 2);
	ft_putnbr_fd(bench->op_count[SB], 2);
	ft_putstr_fd(" |  ss : ", 2);
	ft_putnbr_fd(bench->op_count[SS], 2);
	ft_putstr_fd("\n  pa : ", 2);
	ft_putnbr_fd(bench->op_count[PA], 2);
	ft_putstr_fd(" |  pb : ", 2);
	ft_putnbr_fd(bench->op_count[PB], 2);
	ft_putstr_fd(" |  ra : ", 2);
	ft_putnbr_fd(bench->op_count[RA], 2);
	ft_putstr_fd(" |  rb : ", 2);
	ft_putnbr_fd(bench->op_count[RB], 2);
	ft_putstr_fd("\n  rr : ", 2);
	ft_putnbr_fd(bench->op_count[RR], 2);
	ft_putstr_fd(" | rra : ", 2);
	ft_putnbr_fd(bench->op_count[RRA], 2);
	ft_putstr_fd(" | rrb : ", 2);
	ft_putnbr_fd(bench->op_count[RRB], 2);
	ft_putstr_fd(" | rrr : ", 2);
	ft_putnbr_fd(bench->op_count[RRR], 2);
	ft_putstr_fd("\n================================================\n\n", 2);
}

/* Função principal (Hub) apelidada pelo teu programa */
void	print_bench_report(t_bench *bench)
{
	if (!bench)
		return ;
	print_bench_meta(bench);
	print_bench_ops(bench);
}
