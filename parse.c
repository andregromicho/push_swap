/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goperez- <goperez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 20:17:45 by goperez-          #+#    #+#             */
/*   Updated: 2026/06/09 20:50:11 by goperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	parse_flag(t_data *data, char *arg)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		data->flags.bench = 1;
		return (1);
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
	{
		data->flags.adaptive = 1;
		return (1);
	}
	else if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		data->flags.simple = 1;
		return (1);
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		data->flags.medium = 1;
		return (1);
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		data->flags.complex = 1;
		return (1);
	}
	return (0);
}

static int	handle_arguments(t_data *data, char *arg)
{
	int	value;

	if (parse_flag(data, arg))
		return (1);
	if (!ft_atoi(arg, &value))
		return (0);
	if (has_duplicate(data->a, value))
		return (0);
	if (!add_back_circular(data->a, value))
		return (0);
	return (1);
}

int	process_input(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split_args;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (0);
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			return (0);
		j = 0;
		while (split_args[j])
		{
			if (!handle_arguments(data, split_args[j]))
				return (free_matrix(split_args), 0);
			j++;
		}
		free_matrix(split_args);
		i++;
	}
	return (1);
}
