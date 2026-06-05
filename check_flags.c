#include "push_swap.h"

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