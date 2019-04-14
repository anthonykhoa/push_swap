This project is about sorting integers on a stack. The project gives you only two stacks to work with, stacks A and B.
Stack A will be filled with a list of integers. The goal of the project is to sort the integers in stack A into ascending order, using only a limited instruction set and stacks A and B. Furthermore.. the project calls them stacks, but they are not true stacks - I would instead call them circular linked lists.
Take a look at the project PDF for more details on the project!
Here are only instructions allowed for using in sorting the Stacks:

SA : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

SB : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

SS : sa and sb at the same time.

PA : push a - take the first element at the top of b and put it at the top of a. Do
     nothing if b is empty.
     
PB : push b - take the first element at the top of a and put it at the top of b. Do
     nothing if a is empty.
     
RA : rotate a - shift up all elements of stack a by 1. The first element becomes
     the last one.
     
RB : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

RR : ra and rb at the same time.

RRA : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

RRB : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

RRR : rra and rrb at the same time.

ALGORITHM METHODOLOGY:

3 #'s: see sort_3 function of solve.c file
4 #'s: PB 2 times, use swap if necessary on each stack, call mergesort
5 #'s: PB 2 times, use sort_3 on stack A, use swap on stack B if necessary to sort, call mergesort

3)use PA until stack B is empty.

FOR BIG LISTS (6 or more numbers):
-A bottom up merge sort is the algorithm implemented. I assign node values to each integer in stacks A and B
 in order to keep track of which numbers to merge with one another.

1)push half of stack A onto stack B (accomplished in n / 2 steps)

2)Assign node values to indicate which subarrays to merge with each other.

3)Leftovers will be assigned a node value of 0, indicating they are leftover numbers that need to be merged.

4)My algorithm is recursive and works like so:
     a. increase size of subarray (multiplies by 2 each time)
     b. re rank nodes since size of subarray has changed 
     c. merge all nodes with each other

My code sorts 500 numbers in ~6500 steps.
