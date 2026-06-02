#include "push_swap.h"

static int	check_and_set_flags(t_data *data, char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (data->flags.simple = 1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (data->flags.medium = 1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (data->flags.complex = 1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (data->flags.adaptive = 1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (data->flags.bench = 1);
	return (0);
}

int	validate_flags(t_data *data)
{
	int	algorithm_strategies;

	if (!data)
		return (0);
	// Soma quantas estratégias foram ativadas
	algorithm_strategies = data->flags.simple 
		+ data->flags.medium 
		+ data->flags.complex 
		+ data->flags.adaptive;

	// Se ativaram mais do que uma ao mesmo tempo, é Erro!
	if (algorithm_strategies > 1)
		return (0);

	// Se não ativaram nenhuma, o teu programa ativa o modo inteligente por defeito
	if (algorithm_strategies == 0)
		data->flags.adaptive = 1;

	return (1);
}