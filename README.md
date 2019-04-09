# push_swap
WORK IN PROGRESS

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

FOR SMALL LISTS (5 numbers or less):
-A bubble sort is used.

1)Take higher half of numbers of stack A and put it into Stack b. 
  Ex: if the integers in stack A are {1, 2, 3, 4, 5, 6, 7, 8, 9} (can be any order too,  
  I just used this for clarity... The stack could be {3,1,2,6,4,5,7,9,8} too) then we put 6, 7, 8, and 9 into Stack B.

2)Sort A while sorting B. Then finish sorting for B if still unsorted.
  Stack A will be sorted in ascending order, while Stack B will be sorted in descending order.
  I am sorting stack A and while sorting stack B with the same algorithm template.
  Therefore when Stack A is finished, it is possible stack B will be finished sorting too. Sorting both stacks
  with the same Stack is possible because of instructions SS, RR, and RRR.

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

My code currenly sorts 500 numbers in 6560 steps, but I need to hit 5300 steps in order to pass. blehhh
