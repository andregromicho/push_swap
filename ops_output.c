/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:49:39 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/15 16:42:18 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	emit_op(t_data *data, const char *op, int len, int op_index)
{
	if (!data || !op)
		return ;
	if (op_index >= 0 && op_index <= RRR)
	{
		data->bench.op_count[op_index]++;
		data->bench.total_ops++;
	}
	write(1, op, len);
}
