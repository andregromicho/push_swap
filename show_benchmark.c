#include "push_swap.h"

void print_disorder_fd(double disorder, int fd)
{
    int integer_part;
    int decimal_part;

    integer_part = (int)disorder;
    // Captura as duas primeiras casas decimais (ex: 23.456 -> 0.456 * 100 = 45)
    decimal_part = (int)((disorder - integer_part) * 100);
    if (decimal_part < 0)
        decimal_part *= -1;

    ft_putnbr_fd(integer_part, fd);
    write(fd, ".", 1);
    if (decimal_part < 10)
        write(fd, "0", 1); // Garante que 23.05 não vira 23.5
    ft_putnbr_fd(decimal_part, fd);
    write(fd, "%\n", 2);
}

void print_bench_report_pure(t_bench *bench)
{
    ft_putstr_fd("\n========== PUSH_SWAP BENCHMARK REPORT ==========\n", 2);
    
    ft_putstr_fd("Computed Disorder      : ", 2);
    print_disorder_fd(bench->disorder, 2);
    
    ft_putstr_fd("Strategy Used          : ", 2);
    ft_putstr_fd(bench->strategy, 2);
    ft_putstr_fd("\n", 2);
    
    ft_putstr_fd("Complexity Class       : ", 2);
    ft_putstr_fd(bench->complexity, 2);
    ft_putstr_fd("\n", 2);
    
    ft_putstr_fd("Total Operations       : ", 2);
    ft_putnbr_fd(bench->total_ops, 2);
    ft_putstr_fd("\n------------------------------------------------\n", 2);
    
    // Exemplo para algumas operações (basta repetir o padrão para as restantes)
    ft_putstr_fd("  sa : ", 2); ft_putnbr_fd(bench->op_count[SA], 2);
    ft_putstr_fd(" |  sb : ", 2); ft_putnbr_fd(bench->op_count[SB], 2);
    ft_putstr_fd(" |  ss : ", 2); ft_putnbr_fd(bench->op_count[SS], 2);
    ft_putstr_fd("\n", 2);
    
    ft_putstr_fd("  pa : ", 2); ft_putnbr_fd(bench->op_count[PA], 2);
    ft_putstr_fd(" |  pb : ", 2); ft_putnbr_fd(bench->op_count[PB], 2);
    ft_putstr_fd("\n================================================\n\n", 2);
}