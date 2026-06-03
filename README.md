*This project has been created as part of the 42 curriculum by dvasilev and zscekic.*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of stack operations while producing the smallest possible number of instructions.

The program receives a list of integers as arguments, validates the input, and outputs a sequence of operations that sorts the numbers in ascending order. Only the operations specified by the subject are allowed:

- sa, sb, ss – swap
- pa, pb – push
- ra, rb, rr – rotate
- rra, rrb, rrr – reverse rotate

The challenge is not only to sort the numbers correctly but also to minimize the number of operations required.

### Team and Contributions

| Teammate | Focus Areas & Contributions |
| :--- | :--- |
| **dvasilev** | Input validation, Bubble Sort, Radix sort, Main push_swap, Makefile and README.md |
| **zscekic** | Stack operations, Small Stack Sorting, Chunk Based Sort, Adaptive algorithm, Disorder & Benchmark |

## Instructions

### Compilation
To compile the project:
```bash
make
```

This will generate:
```
push_swap
```

### Available Makefile Rules

```bash
make all    # compile push_swap
make clean  # remove object files
make fclean # remove object files and executable
make re     # rebuild everything
```

### Usage

```
./push_swap [flags] [numbers...]
```
*Example:*
```
./push_swap 2 1 3 4 5 6
```
*Example output:*
```
sa
ra
ra
ra
...
```
The output represents the sequence of operations required to sort the input stack.

### Available Flags
| Flag | Strategy / Mode | Description |
| :--- | :--- | :--- |
| `--simple` | Bubble Sort | Forces the program to use basic sorting. |
| `--medium` | Chunk-based Sort | Forces the program to use the chunk-based sorting algorithm. |
| `--complex` | Radix Sort | Forces the program to use the Radix sort algorithm. |
| `--adaptive` | Dynamic Selection | **(Default)** Automatically selects the most efficient algorithm based on the input size. |
| `--bench` | Benchmark Mode | Outputs performance metrics (e.g., total operation count) |

## Algorithms & Complexity Analysis

To get the highest score on the 42 evaluation benchmarks, the program dynamically switches its sorting strategy based on the size of the input dataset ($n$). Values are indexed (coordinate compression) beforehand so the algorithms operate on a compact range from $0$ to $n - 1$.

### 1. Simple Regime ($n \le 5$)
* **Strategy:** **Small Sort & Bubble Sort**
* **How it works:** For $n \le 3$, it uses a hardcoded analytical sort (max 3 moves). For up to 5 elements, it repeatedly compares adjacent elements, optimization pushes the smallest numbers to Stack B, sorts Stack A, and pushes them back.
* **Rationale:** Bubble sort is one of the simplest algorithms to adapt to `push_swap` operations, requiring minimal overhead. At this scale, it easily keeps instructions under the 12-move threshold.
* **Complexity:** * **Time:** $\mathcal{O}(1)$ — The input size is tightly bounded, so the maximum number of moves never exceeds a small constant.
  * **Space:** $\mathcal{O}(1)$ — No extra memory is allocated; it operates entirely within the stacks.

### 2. Medium Regime ($6 \le n \le 100$)
* **Strategy:** **Chunk-based Sort**
* **How it works:** Divides the indexed values into smaller ranges (chunks). Elements belonging to the current chunk are pushed from Stack A to Stack B. Once all chunks are processed, elements are efficiently sorted back into Stack A in the correct order.
* **Rationale:** It takes advantage of both stacks to organize values efficiently. Pure Radix sort takes too many moves at this size; Chunk-based sort provides an excellent balance of complexity and performance, comfortably beating the 42 benchmark limit of **700 operations** for 100 numbers.
* **Complexity:** * **Time:** $\mathcal{O}(n^2)$ worst-case, but chunking optimizations bring the operational count closer to $\mathcal{O}(n \sqrt{n})$ on average.
  * **Space:** $\mathcal{O}(n)$ — Requires a temporary array to pre-index the values.

### 3. Complex Regime ($n > 100$)
* **Strategy:** **Radix Sort (Bitwise)**
* **How it works:** The algorithm examines each bit of the indexed values from right to left. Elements with a `0` in the current bit position are pushed to Stack B, while elements with a `1` remain in Stack A via rotations. Stack B is then pushed back to Stack A, and the process repeats for the next bit.
* **Rationale:** It is simple to implement and provides highly predictable performance for larger datasets. Unlike Quick Sort or Merge Sort adaptations, it completely avoids complex partition management or recursion. This guarantees a passing score under the **5500 operations** limit for 500 numbers.
* **Complexity:** * **Time:** $\mathcal{O}(n \log n)$ — It performs exactly $n$ checks for every bit required to represent the largest index.
  * **Space:** $\mathcal{O}(n)$ — Requires an array to hold the indexed values.

---

### Complexity & Target Summary

| Regime | Input Size ($n$) | Chosen Algorithm | Time Complexity | Space Complexity | 42 Project Target |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Simple** | $n \le 5$ | Small / Bubble Sort | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Max 12 instructions |
| **Medium** | $6 \le n \le 100$ | Chunk-based Sort | $\mathcal{O}(n \sqrt{n})$ | $\mathcal{O}(n)$ | Under 700 instructions |
| **Complex** | $n > 100$ | Radix Sort | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ | Under 5500 instructions |

## Features
- Input validation
- Duplicate detection
- Integer overflow protection
- Multiple sorting strategies
- Doubly linked list stack implementation
- Benchmarking support

## Resources
The following references were useful for understanding and implementing the functions in this project:

- https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/
- https://www.geeksforgeeks.org/dsa/swap-given-nodes-in-a-doubly-linked-list-without-modifying-data/
- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- https://www.geeksforgeeks.org/dsa/merge-sort/
- https://www.geeksforgeeks.org/dsa/radix-sort/
- https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp/
- https://push-swap42-visualizer.vercel.app/


## AI usage
ChatGPT and Gemini was used for:

- Understanding data structures and algorithms
- Understanding implementation approaches
- Clarifying C language concepts
- Reviewing memory management and Makefile behavior
- Debugging
- Readme file generation