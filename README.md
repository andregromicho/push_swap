*This project has been created as part of the 42 curriculum by abrandao, goperez-.*

Push Swap - 42 School Project
A stack sorting program using limited operations, implemented in C.

# 📋 Description
push_swap is a 42 School project that sorts a sequence of numbers using two stacks (A and B) with only a limited set of operations:

Available Operations
sa: Swap the top of A

sb: Swap the top of B

ss: Swap both tops

pa: Move top of B to A

pb: Move top of A to B

ra: Rotate A (top goes to bottom)

rb: Rotate B

rr: Rotate both

rra: Reverse rotate A

rrb: Reverse rotate B

rrr: Reverse rotate both

# 🚀 Instructions
## Compilation
This project should be used with a bash terminal.

```bash
make          # Compiles the project
make clean    # Removes object files
make fclean   # Removes everything including the executable
make re       # Recompiles everything
```

## 💻 Usage
```bash
./push_swap [numbers]
./push_swap [numbers] --simple          # Bubble Sort (O(n²))
./push_swap [numbers] --medium          # Chunk Sort (O(n√n))
./push_swap [numbers] --complex         # Radix Sort (O(n*k))
./push_swap [numbers] --adaptive        # Adaptive (automatic)
./push_swap [numbers] --bench           # Benchmark Mode with report
```

## Examples
```bash
# Simple sorting
./push_swap 3 2 1

# With numbers inside quotes
./push_swap "9 8 7 6 5 4 3 2 1"

# With benchmarking
./push_swap --bench "5 3 1 4 2"

# Specific algorithm
./push_swap --simple "5 3 1 4 2"
```

# 🎯 Explanation and justification of the algorithms selected

A single sorting algorithm is rarely optimal for every data distribution. In `push_swap`, where the efficiency score depends strictly on the total number of operations, we designed a **Multi-Strategy Hybrid Engine**. 

By evaluating both the **dataset size ($N$)** and the **initial state of disorder**, the program dynamically routes the input to the most efficient algorithm, preventing the execution of redundant moves.

---

### 1. Small Sort Optimization ($\le 5$ elements)
* **Algorithm Used:** Hardcoded state-machine for $N=3$; Cost-minimization push for $N=4$ and $N=5$.
* **Justification:** For miniature datasets, the overhead of calculating complex data structures or sorting bit-by-bit is highly inefficient. 
  * **$N \le 3$:** Sorted in a maximum of **2 operations** using a hardcoded decision tree that analyzes the relationship between the three nodes.
  * **$N = 4$ and $N = 5$:** The algorithm locates the smallest absolute values, calculates the shortest path to the top (using either `ra` or `rra`), pushes them to Stack B, calls `sort_3` on Stack A, and pushes them back. This guarantees a safe pass under the strict 42 evaluation thresholds (under 12 operations for 5 numbers).

---

### 2. Bubble Sort (`--simple`)
* **Complexity:** $O(n^2)$
* **Justification:** While Bubble Sort is generally inefficient for large random datasets, it features a crucial property: it is highly effective on **nearly sorted data**. If a stack of 100 elements only has 2 or 3 numbers out of place (a low disorder percentage), Bubble Sort can fix those localized anomalies using immediate `sa` or targeted single-rotation operations, achieving sorted state far quicker than heavy restructuring algorithms.

---

### 3. Chunk Sort (`--medium`)
* **Complexity:** $O(n\sqrt{n})$
* **Justification:** When a dataset exhibits moderate disorder, a pure Radix sort might over-rotate the stack, while a Bubble sort would trigger too many comparisons. Chunk Sort bridges this gap by applying a **Divide and Conquer** philosophy:
  1. The dataset is logically sliced into $B$ sub-blocks (chunks), where the optimal number of chunks is mathematically proportional to $\sqrt{n}$.
  2. Numbers belonging to the lowest active chunk are filtered and pushed to Stack B.
  3. By keeping elements of similar value grouped together in Stack B, the final push back to Stack A requires minimal rotation overhead, drastically reducing the operation count for medium-sized stacks (e.g., 100 elements).

---

### 4. Radix Sort (`--complex`)
* **Complexity:** $O(n \times k)$ where $k$ is the number of bits required to represent the largest index.
* **Justification:** For large, highly chaotic datasets (e.g., 500 random elements), standard comparison-based algorithms risk hitting their worst-case scenarios. Radix Sort offers a deterministic solution.
  * By first flattening the raw integers into consecutive **indices from $0$ to $N-1$**, we eliminate the issue of negative numbers and large gaps.
  * The algorithm processes the dataset bit-by-bit, from the Least Significant Bit (LSB) to the Most Significant Bit (MSB). Elements with a `0` bit are pushed to Stack B, while elements with a `1` bit are rotated in Stack A. 
  * Because its execution path is bound strictly to bit depth rather than element value comparisons, it provides a stable, predictable, and highly safe operation count that comfortably passes the 500-element evaluation benchmark.

---

### 5. The Adaptive Engine (The Core Innovation)
Instead of forcing a static algorithm onto every payload, the default behavior of our `push_swap` analyzes the data's **Disorder Coefficient** before making a move.

$$\text{Disorder } (\%) = \frac{\text{Number of Inversions}}{\text{Total Possible Inversions}}$$

By establishing thresholds ($20\%$ and $50\%$), the program avoids the common pitfall of running a high-overhead Radix Sort on an array that only needed a few rotations to be solved, maximizing performance across all grading criteria.

# Contributions
We abrandao and goperez- worked together on this code, writing each function as the normal workflow required it to complete each part of the complete project, attempted to improve its efficiency in some algorithms, and tested it for efficiency, memory leaks and error management. We also consulted with other students that had already completed the project on the internal logic of the program, how to demonstrate if we understood the code and the specifics of the evaluation process.

# Resources
- Library Functions Manual
- We used the provided checker for linux.
- [Radix sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)

## AI Usage Disclosure
- AI (Gemini 3 Flash) was used complementarily during this project.

- Documentation: Assisting in formatting this README to maintain consistency with previous project documentation.