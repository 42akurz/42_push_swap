# 42_push_swap - 42 School Project

## About

* This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

* The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted.  
You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.  

* The goal ?  
Write a program in C called push_swap which calculates and displays on the standard output the instructions, that sort the integers received as arguments.

* The learning objectives of this project are rigor, use of C and use of basic algorithms. Especially looking at the complexity of these basic algorithms.

* Within your mandatory part you are allowed to use the following functions:  
malloc, free, exit, write, read

## Operations

* The goal is to sort in ascending order numbers into stack a.  
* To do this you have the following operations at your disposal:

| Operations | Explanation |
| :--- | :--- |
| sa | swap a - swap the first 2 elements at the top of stack a |
| sb | swap b - swap the first 2 elements at the top of stack b |
| ss | sa and sb at the same time |
| pa | push a - take the first element at the top of b and put it at the top of a |
| pb | push b - take the first element at the top of a and put it at the top of b |
| ra | rotate a - shift up all elements of stack a by 1. The first element becomes the last one |
| rb | rotate b - shift up all elements of stack b by 1. The first element becomes the last one |
| rr | ra and rb at the same time |
| rra | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one |
| rrb | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one |
| rrr | rra and rrb at the same time |
