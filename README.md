# Push Swap Project - 42 School

## Overview
The Push Swap project is a challenging algorithmic task from 42 School, designed to test your ability to sort numbers using two stacks, named Stack A and Stack B. The objective is to sort the numbers in Stack A in ascending order using a limited set of instructions, while managing and optimizing the use of both stacks and instructions.

## Instructions
The project uses a specific set of instructions to manipulate the stacks:

- `sa` (swap a): Swap the first 2 elements at the top of stack a.
- `sb` (swap b): Swap the first 2 elements at the top of stack b.
- `ss` : `sa` and `sb` at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a.
- `pb` (push b): Take the first element at the top of a and put it at the top of b.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

## Sorting Process
The sorting process involves strategically using these instructions to move elements between Stack A and Stack B, and to arrange them in the correct order. The goal is to achieve this with the least number of moves possible, optimizing the sorting algorithm's efficiency.

## Example
Initial stacks:


After applying a series of instructions, Stack A should be sorted:


## Project Goals
- To develop a deep understanding of sorting algorithms and data structures.
- To practice optimizing code for efficiency and performance.
- To enhance problem-solving and algorithmic thinking skills.

## Contribution
This project is part of the curriculum at 42 School. Contributions and feedback are welcome to improve the algorithm and documentation.

