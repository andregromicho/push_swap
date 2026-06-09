#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* ========================================================================== */
/* 1. ENUMS                                   */
/* ========================================================================== */

/* ** Mapeamento de índices para o array de contadores de operações.
** Ajuda a evitar ter 11 variáveis inteiras soltas na struct de estatísticas.
*/
typedef enum e_ops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_ops;

/* ========================================================================== */
/* 2. STRUCTS                                  */
/* ========================================================================== */

/* ** Camada 1: O Nó da Lista (Duplamente Ligado)
** Guarda o valor original e o índice simplificado (0 a N-1).
*/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* ** Camada 2: A Estrutura da Stack
** Guarda o ponteiro para o nó que está no topo e o tamanho atual (O(1)).
*/
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* ** Camada 3a: Dados do Modo --bench
** Guarda todas as métricas exigidas para o relatório final no stderr.
*/
typedef struct s_bench
{
	double	disorder;      /* % de desordem com duas casas decimais */
	char	*strategy;     /* Nome da estratégia utilizada */
	char	*complexity;   /* Classe de complexidade teórica */
	int		total_ops;     /* Contador geral de operações */
	int		op_count[11];  /* Array indexado pelo enum t_ops */
}	t_bench;

/* ** Camada 3b: Ativação de Flags
** Funciona como booleanos (0 = Falso, 1 = Verdadeiro) detetados no parsing.
*/
typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
	int silent;
}	t_flags;

/* ** Camada 3c: O Contentor Principal (O "Cérebro" do Programa)
** Junta as stacks A e B, os controlos de flags e as estatísticas de teste.
** É a única struct que precisas de passar como argumento no teu Hub de Algoritmos.
*/
typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_flags	flags;
	t_bench	bench;
}	t_data;

/* ========================================================================== */
/* 3. FUNCTION PROTOTYPES                                  */
/* ========================================================================== */

/* Parsing e validação */
int		init_and_parse(t_data *data, int argc, char **argv);
int		validate_flags(t_data *data);
int		ft_strcmp(char *s1, char *s2);
int		is_digit_str(char *str);
int		ft_atoi_protected(char *str, int *result);
char	**ft_split(char const *s, char c);
void	free_matrix(char **matrix);

/* Stack utilities */
int		has_duplicate(t_stack *stack, int value);
int		add_back_circular(t_stack *stack, int value);
int		get_node_position(t_stack *stack, int target_index);
void	reindex_stack(t_stack *stack);
void	rank_stack(t_stack *stack);

/* Operações de stack */
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* Algoritmos de ordenação */
void	algorithm_hub(t_data *data);
void	run_bubble_sort(t_data *data);
void	run_chunk_sort(t_data *data);
void	run_radix_sort(t_data *data);
void	run_adaptive_sort(t_data *data);
void	run_insertion_sort(t_data *data);

/* Cálculos */
double	compute_disorder(t_stack *a);

/* Benchmark e output */
void	print_disorder_fd(double disorder, int fd);
void	print_bench_report_pure(t_bench *bench);

/* String utilities */
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);

#endif
