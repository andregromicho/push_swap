#include "push_swap.h"

/* Liberta toda a memória alocada da stack */
static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack || !stack->top)
	{
		free(stack);
		return ;
	}
	current = stack->top;
	while (1)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		if (current == stack->top)
			break ;
	}
	free(stack);
}

/* Liberta toda a estrutura de dados e printa o relatório se necessário */
static void	cleanup_and_exit(t_data *data, int exit_code)
{
	if (!data)
		return ;

	// Se o modo --bench estava ativo, printa o relatório antes de sair
	if (data->flags.bench)
		print_bench_report_pure(&data->bench);

	// Liberta as stacks
	if (data->a)
		free_stack(data->a);
	if (data->b)
		free_stack(data->b);

	// Liberta a struct principal
	free(data);

	exit(exit_code);
}

/* Inicializa as stacks vazias */
static t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);

	// Inicializa Stack A
	data->a = malloc(sizeof(t_stack));
	if (!data->a)
	{
		free(data);
		return (NULL);
	}
	data->a->top = NULL;
	data->a->size = 0;

	// Inicializa Stack B
	data->b = malloc(sizeof(t_stack));
	if (!data->b)
	{
		free(data->a);
		free(data);
		return (NULL);
	}
	data->b->top = NULL;
	data->b->size = 0;

	// Inicializa as flags
	data->flags.simple = 0;
	data->flags.medium = 0;
	data->flags.complex = 0;
	data->flags.adaptive = 0;
	data->flags.bench = 0;
	data->flags.silent = 0;

	// Inicializa os dados do benchmark
	data->bench.disorder = 0.0;
	data->bench.strategy = "";
	data->bench.complexity = "";
	data->bench.total_ops = 0;
	for (int i = 0; i < 11; i++)
		data->bench.op_count[i] = 0;

	return (data);
}

/* Função principal */
int	main(int argc, char **argv)
{
	t_data	*data;

	// Validação básica de argumentos
	if (argc < 2)
		return (1);

	// Inicializa a estrutura principal
	data = init_data();
	if (!data)
		return (1);

	// Faz parsing dos argumentos e popula a Stack A
	if (!init_and_parse(data, argc, argv))
	{
		cleanup_and_exit(data, 1);
	}

	// Faz ranking dos valores (menor=0, segundo_menor=1, etc)
	rank_stack(data->a);

	// Valida as flags (garante exclusividade entre estratégias)
	if (!validate_flags(data))
	{
		cleanup_and_exit(data, 1);
	}

	// Calcula a desordem inicial para os cálculos adaptativos
	data->bench.disorder = compute_disorder(data->a) * 100.0;

	// Escolhe e executa o algoritmo apropriado
	algorithm_hub(data);

	// Printa o relatório de benchmark (se --bench foi usado) e faz cleanup
	cleanup_and_exit(data, 0);

	return (0);
}
