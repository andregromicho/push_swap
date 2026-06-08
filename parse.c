#include "push_swap.h"

/* Liberta a matriz gerada pelo ft_split para evitar Memory Leaks */
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

/* Ativa as flags na struct se encontrar argumentos de texto válidos */
static int	check_and_set_flags(t_data *data, char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		data->flags.bench = 1;
		data->flags.silent = 1;
		return (1);
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
	{
		data->flags.adaptive = 1;
		return (1);
	}
	else if (ft_strcmp(arg, "--simple") == 0)
	{
		data->flags.simple = 1;
		return (1);
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		data->flags.medium = 1;
		return (1);
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		data->flags.complex = 1;
		return (1);
	}
	return (0);
}

/* Bloco atómico: valida se é flag ou número, vê duplicados e insere */
static int	parse_and_add(t_data *data, char *arg)
{
	int	value;

	// 1. Se for uma flag de texto válida, ativa-a e avança sem dar erro
	if (check_and_set_flags(data, arg))
		return (1);
	// 2. Se não for flag, tem de ser obrigatoriamente um número válido
	if (!ft_atoi_protected(arg, &value))
		return (0);
	// 3. Verifica se o número já existe na stack
	if (has_duplicate(data->a, value))
		return (0);
	// 4. Insere fisicamente no fim da lista circular
	if (!add_back_circular(data->a, value))
		return (0);
	return (1);
}

/* Varre o argv, lida com aspas através  de split e popula a Stack A*/
int	init_and_parse(t_data *data, int argc, char **argv)
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
		if (!split_args || !split_args[0])
		{
			free_matrix(split_args);
			return (0);
		}
		j = 0;
		while (split_args[j])
		{
			if (!parse_and_add(data, split_args[j]))
			{
				free_matrix(split_args);
				return (0);
			}
			j++;
		}
		free_matrix(split_args);
		i++;
	}
	return (1);
}