# Equivalence-Relation
This project was used to excercise my knowledge of arrays and functions.

# Objective
My goal was to create a tool that manages an equivalnce relation that
can be changed by the program. The equivalence relation is always over a set
of integers {1,2,3,...,n} for some n. Initially, each number is in its own
equivalence relation {1},{2},{3},...,{n}

#Functions 
1. newER(n) returns an array of n+1 integers (allocated in the heap). This
   array will be used to store the bosses.

2. leader(R,x) returns the leader of x in the equivalence relation R.

3. equivalent(R,x,y) returns true if x and y are currently in the same 
   equivalence relation R.

4. merge(R,x,y) merges the equivalence classes of x and y in R as follows.
   First, it finds the leaders x' and y' of x and y. if x' and y' are different
   (so x and y are not already in the same equivalence class) then y' becomes
   the new boss of x'

5. destroyER(R) deallocates R.

6. showER(R,n) prints the entire contents of array R (of size n) in a readable
   format for debugging.
