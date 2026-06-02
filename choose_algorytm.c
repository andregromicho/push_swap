#include "push_swap.h"

void algorithm_hub(t_data *data)
{
    // Calcular a desordem inicial e guardar direto na struct
    data->bench.disorder = calculate_disorder(data->a) * 100.0;

    if (data->flags.simple)
    {
        data->bench.strategy = "Bubble Sort";
        data->bench.complexity = "O(n²)";
        run_bubble_sort(data); // Passa apenas o contentor central!
    }
    else if (data->flags.medium)
    {
        data->bench.strategy = "Chunk Sort";
        data->bench.complexity = "O(n√n)";
        run_chunk_sort(data);
    }
    else if (data->flags.complex)
    {
        data->bench.strategy = "Radix Sort";
        data->bench.complexity = "O(n log n)";
        run_radix_sort(data);
    }
    else
      run_adaptative_sort(data);
}