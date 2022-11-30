Name: Om Vivek Gharge
PRN: 2020BTEIT00041

The given python code uses Process/Pipe paradigm to communicate the solutions to
the parent processes.

Quicksort:
-Partition the list according to a random pivot.
-Quicksort the left half-list.
-Quicksort the right half-list.
So a parallel version comes from the realization that
the two sorts are independent of one another after the
partition:
-Partition the list according to a random pivot.
-Quicksort the two half-lists in parallel.

This is not typical quicksort; it is NlogN in memory
and does not sort the argument lyst as a side effect,
but rather returns a sorted version of the lyst.

Using a shared memory array results in locks.  Even
with the additional memory, there is usually a
reasonable speedup here.

Here we take a random list of integers to sort and 
then sort it using Sequential,Parallel and also built-in quicksort algorithm.
And then compare the time taken by each one.

ONE SUCH OUTPUT IS:
Sequential quicksort: 1.698092 sec
Parallel quicksort: 1.968003 sec
Built-in sorted: 0.103999 sec


