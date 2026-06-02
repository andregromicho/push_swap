#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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
	int	silent;
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

#endif