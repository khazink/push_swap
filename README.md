*This project has been created as part of the 42 curriculum by kkaman.*

# Description

Push_swap is a sorting algorithm project designed to sort data on a stack using a limited set of instructions, with the ultimate goal of achieving the lowest possible number of actions. It forces you to manipulate different sorting algorithms and choose the most appropriate solution for optimized data sorting in C.

The mechanics revolve around two stacks, a and b:

    Initially, stack a contains a random number of unique negative and/or positive integers.

    Stack b is completely empty.

    The objective is to sort the numbers in stack a in ascending order using only a specific set of operations, keeping the instruction count as small as possible.

## Instructions

### Compilation
The project includes a Makefile that complies with standard 42 requirements (all, clean, fclean, re).

To compile the push_swap executable, navigate to the root directory and run:
```bash
make
```

### Execution
The program takes a list of integers as an argument, which populates stack a. The first argument provided will be at the top of the stack.
```bash
./push_swap 2 1 3 6 5 8
```

To count the number of operations used to sort the numbers, run:
```bash
./push_swap 4 67 3 87 23 | wc -l
```

To run the `checker` program to check if the `push_swap` program actually sorts the numbers, run:
```shell
ARG="4 67 3 87 23" ; ./push_swap $ARG | ./checker $ARG
```

(If the input is valid, it will output the shortest sequence of instructions required to sort the stack, separated by newlines.)

### Allowed Operations

To achieve the sorted stack, you are restricted to the following moves:

    sa (swap a) / sb (swap b): Swap the first 2 elements at the top of stack a or b.

    ss: Execute sa and sb simultaneously.

    pa (push a) / pb (push b): Take the top element of one stack and push it to the top of the other.

    ra (rotate a) / rb (rotate b): Shift up all elements of a stack by 1. The first element becomes the last.

    rr: Execute ra and rb simultaneously.

    rra (reverse rotate a) / rrb (reverse rotate b): Shift down all elements of a stack by 1. The last element becomes the first.

    rrr: Execute rra and rrb simultaneously.

## Technical Details & Structure

This implementation utilizes a cost-calculation-based algorithm (often referred to as the Turk algorithm or a mechanical sort). Instead of chunking, it evaluates the precise cost of moving every individual node from one stack to its correct position in the other stack, always executing the "cheapest" move.

    parse_args.c: Validates input, handles edge cases, and initializes the linked list.

    sort_small.c: Hardcoded, highly optimized logic for sets of 3 elements.

    sort_large.c: The main sorting logic loop utilized for larger datasets.

    calculate_cost.c & execute_move.c: The core engine that calculates the necessary rotations for both stacks and executes the cheapest combined move.

    final_alignment.c: Rotates the stack to properly align the smallest integer to the top of stack a once all elements are sorted.

## Resources

References & Documentation

    Push_swap - 42 Docs - An overview of the project and common approaches.

    Push_Swap Turk algorithm explained in 6 steps - Medium
    
    Sort Like a Mechanical Turk - Fast, Efficient, and Memory-Safe - https://github.com/yomazini/42cursus-push_swap - yomazini 

## AI Usage
During the development of this project, AI was utilized for the following tasks:

    Code Structuring & Logic Analysis: Discussing the trade-offs between different algorithmic approaches (like Radix sort vs. Cost-based insertion) to determine the best method for minimizing instruction counts.

    Refactoring & Optimization: Assisting in analyzing functions like calculate_cost.c to identify edge cases in rotation calculations and ensure the logic cleanly handles double rotations (rr, rrr).
