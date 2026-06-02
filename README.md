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
./push_swap 2 1 3 4 5 6
```
Example output:
```
sa
ra
ra
ra
...
```
The output represents the sequence of operations required to sort the input stack.


## Algorithms

### Simple - Small Sort

For very small datasets (up to 5), a custom sorting strategy is used. By combining swap, rotate, and reverse rotate operations, the stack can be sorted with a minimal number of moves.

### Simple O(n^2) - Bubble sort
Bubble sort repeatedly compares adjacent elements and swaps them when they are in the wrong order. The process continues until no more swaps are needed, meaning the stack is sorted.

**Bubble sort was selected because:**
- It is one of the simplest O(n²) sorting algorithms to adapt to the push_swap operations.
- It performs well for very small datasets.
- It requires minimal logic and overhead.

### Medium O(n√n) - Chunk based sort
Chunk based sorting divides the indexed values into smaller ranges (chunks). Elements belonging to the current chunk are pushed from stack A to stack B. Once all chunks have been processed, elements are pushed back to stack A in the correct order.

**Chunk based sort was selected because:**
- It performs well on medium-sized datasets.
- It takes advantage of both stacks to organize values efficiently.
- It provides a good balance between implementation complexity and performance.

### Complex O(n*logn) - Radix sort
The algorithm works by examining each bit of the indexed values:

Elements with a 0 in the current bit position are pushed to stack B.
Elements with a 1 remain in stack A through rotations.
Elements are pushed back from stack B to stack A.
The process repeats for every bit until the stack is sorted.

**Radix sort was selected because:**
- It is simple to implement and easy to understand.
- It provides predictable performance for larger datasets.
- Unlike quick sort and merge sort adaptations, it does not require complex partition management or recursion.

Before applying radix sort, values are indexed (coordinate compression) so that the algorithm operates on a compact range from 0 to n - 1.


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