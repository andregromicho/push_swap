# Push Swap - Projeto Escola 42

Um programa de ordenação de stacks usando operações limitadas, implementado em C.

## 📋 Descrição

O push_swap é um projeto da Escola 42 que ordena uma sequência de números através de duas stacks (A e B) usando apenas um conjunto limitado de operações:

### Operações Disponíveis
- `sa`: Troca o topo de A
- `sb`: Troca o topo de B
- `ss`: Troca ambos os topos
- `pa`: Move topo de B para A
- `pb`: Move topo de A para B
- `ra`: Rotaciona A (topo vai para base)
- `rb`: Rotaciona B
- `rr`: Rotaciona ambas
- `rra`: Rotação inversa de A
- `rrb`: Rotação inversa de B
- `rrr`: Rotação inversa em ambas

## 🚀 Compilação

```bash
make          # Compila o projeto
make clean    # Remove ficheiros objeto
make fclean   # Remove tudo incluindo o executável
make re       # Recompila tudo
```

## 💻 Uso

```bash
./push_swap [números]
./push_swap [números] --simple          # Bubble Sort (O(n²))
./push_swap [números] --medium          # Chunk Sort (O(n√n))
./push_swap [números] --complex         # Radix Sort (O(n*k))
./push_swap [números] --adaptive        # Adaptativo (automático)
./push_swap [números] --bench           # Modo Benchmark com relatório
```

### Exemplos

```bash
# Ordenação simples
./push_swap 3 2 1

# Com números entre aspas
./push_swap "9 8 7 6 5 4 3 2 1"

# Com benchmarking
./push_swap --bench "5 3 1 4 2"

# Algoritmo específico
./push_swap --simple "5 3 1 4 2"
```

## 🎯 Algoritmos Implementados

### 1. Bubble Sort (--simple)
- Complexidade: O(n²)
- Uso: Dados já parcialmente ordenados
- Método: Comparação e troca simples

### 2. Chunk Sort (--medium)
- Complexidade: O(n√n)
- Uso: Desordem média
- Método: Divisão em chunks de tamanho √n

### 3. Radix Sort (--complex)
- Complexidade: O(n * k)
- Uso: Dados muito desordenados
- Método: Ordenação por bits (binária)

### 4. Insertion Sort (adaptativo, desordem baixa)
- Complexidade: O(n²)
- Ativação: Desordem < 20%

### 5. Modo Adaptativo (padrão)
Escolhe automaticamente baseado no nível de desordem:
- Desordem < 20%: Insertion Sort
- 20% ≤ Desordem < 50%: Chunk Sort
- Desordem ≥ 50%: Radix Sort

## 📊 Modo Benchmark

Ao usar `--bench`, o programa:
1. Calcula o percentual de desordem inicial
2. Executa o algoritmo escolhido
3. Exibe relatório com:
   - Percentual de desordem
   - Estratégia utilizada
   - Classe de complexidade
   - Total de operações
   - Contagem por tipo de operação

## 🏗️ Estrutura do Projeto

```
├── main.c                    # Função principal e inicialização
├── parse.c / parse_utils.c   # Parsing de argumentos
├── push_swap.h               # Headers e estruturas
├── stack_utils.c             # Gerenciamento de stacks circulares
├── rank_stack.c              # Ranking de valores
├── ft_utils.c                # Funções auxiliares (ft_strlen, etc.)
├── ops_*.c                   # Operações de stack
├── *_sort.c                  # Algoritmos de ordenação
├── disorder.c                # Cálculo de desordem
├── show_benchmark.c          # Relatório de benchmark
└── Makefile                  # Build system
```

## 🔍 Detalhes Técnicos

### Estrutura de Dados
- **Stack Circular Duplamente Ligada**: O(1) para rotações
- **Ranking de Valores**: Índices simplificados 0 a N-1

### Validações
- Detecção de duplicados
- Proteção contra overflow (INT_MAX/MIN)
- Suporte a números negativos
- Validação de flags exclusivas

## 📝 Notas Importantes

1. **Circular**: As stacks são circulares para rotações O(1)
2. **Ranking**: Após parsing, os valores são ranqueados (0 = menor)
3. **Desordem**: Calculada antes de executar o algoritmo
4. **Flags**: --simple, --medium, --complex, --adaptive e --bench são exclusivas
5. **Output**: Operações no stdout, benchmark no stderr

## ✨ Recursos Principais

- ✅ Compilação sem erros com `-Wall -Wextra -Werror`
- ✅ Suporte a números negativos e grandes
- ✅ Múltiplos algoritmos com complexidades diferentes
- ✅ Modo adaptativo inteligente
- ✅ Relatório detalhado de benchmark
- ✅ Proteção contra memory leaks
- ✅ Entrada flexível (múltiplos argumentos ou aspas)

## 🎓 Objetivos Alcançados

- [x] Implementação de todas as operações de stack
- [x] Algoritmos de ordenação com diferentes complexidades
- [x] Modo adaptativo baseado em desordem
- [x] Benchmark detalhado
- [x] Tratamento de erros completo
- [x] Código limpo e bem comentado

---

**Autor**: André Gromicho  
**Projeto**: School 42  
**Data**: 2024
