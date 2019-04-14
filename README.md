This project comprises of two parts: the push_swap program, and the checker program.
The push_swap program is the main focus of this project - it generates a list of instructions that should be able
to sort a stack.
The checker program takes in a list of numbers just like push_swap. After taking in this list of numbers, the user is
able to type in their own commands to sort the stack themselves. Pressing enter with nothing written will terminate this
mode. At the end of this mode, "OK" will appear if the stack is sorted, and "KO" if not.

EXTRA OPTIONS:
-In the checker program, use command "plz" to check if instructions generated from push_swap actually sort the list. This
 will skip the user from manually inputting commands themselves.
-In the checker program, use command "-v" to enter stack visualizer mode - this mode lets you see what happens after each
  instruction gets applied
 to the stack.
-"plz" and "-v" options can be applied together. Ex: ./checker "-v" "plz" "3" "2" 1"
-I've provided a random number generator with 4 list sizes: 500, 100, 5, and 3. Type in make followed by the number
 you want, and a file named nums will automatically open up with your random list of numbers. 
  Ex: make 500
 -If you want to pick your own list size, enter the command "make rn" and then enter ./rn <#>
  Ex: ./rn 333

The project gives you only two stacks to work with, stacks A and B.
Stack A will be filled with a list of integers. The goal of the project is to sort the integers in stack A into ascending
order, using only a limited instruction set and stacks A and B. Furthermore.. the project calls them stacks, but they are
not true stacks - I would instead call them circular linked lists.
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
