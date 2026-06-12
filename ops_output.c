#include "push_swap.h"

void	emit_op(t_data *data, const char *op, int len, int op_index)
{
	if (!data || !op)
		return ;
	/* Always count ops so --count-only can report totals even when --bench isn't set */
	if (op_index >= 0 && op_index <= RRR)
	{
		data->bench.op_count[op_index]++;
		data->bench.total_ops++;
	}
	/* Only print operations when not in count-only mode */
	if (!data->flags.count_only)
		write(1, op, len);
}
