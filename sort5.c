/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@ai>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12  by Copilot                              #+#    #+#             */
/*   Updated: 2026/06/12  by Copilot                             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate the stack A until target_index is on top, then push to B */
static void	bring_index_to_top_and_push(t_data *data, int target_index)
{
    int pos;
    int half;

    if (!data || !data->a)
        return ;
    pos = get_node_position(data->a, target_index);
    if (pos < 0)
        return ;
    half = data->a->size / 2;
    if (pos <= half)
    {
        while (pos-- > 0)
            ra(data);
    }
    else
    {
        while (pos++ < data->a->size)
            rra(data);
    }
    pb(data);
}

void	sort_5(t_data *data)
{
    int pushed;

    if (!data || !data->a)
        return ;
    if (data->a->size <= 3)
    {
        sort_3(data);
        return ;
    }
    pushed = 0;
    /* push two smallest elements (indices 0 and 1) to B */
    while (data->a->size > 3 && pushed < 2)
    {
        /* always search for the current smallest remaining index (pushed) */
        bring_index_to_top_and_push(data, pushed);
        pushed++;
    }
    /* sort remaining 3 in A */
    sort_3(data);
    /* push back from B to A */
    while (data->b->size > 0)
        pa(data);
    /* final adjustment */
    if (data->a->top && data->a->top->next && data->a->top->index > data->a->top->next->index)
        sa(data);
}
