/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:53:14 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/09 20:53:15 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_flags(t_data *data)
{
	int	algorithm_strategies;

	if (!data)
		return (0);
	algorithm_strategies = data->flags.simple
		+ data->flags.medium
		+ data->flags.complex
		+ data->flags.adaptive;
	if (algorithm_strategies > 1)
		return (0);
	if (algorithm_strategies == 0)
		data->flags.adaptive = 1;
	return (1);
}
