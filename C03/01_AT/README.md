# AT

## W1 (Intro)

### Code testing sugestion:

- Start with some manual testing and then try them in (possibly) the following order;

- Beware of integer (or other types of) overflow;

- Beware of big inputs and time & space taken to run an algorithm (do time complexity analysis on your solution);

- Beware of edge cases (think what they might be). eg.: minimum size/quantity of input, maximum size/quantity of input, repeated input, etc;

- Stress testing.
    - Implement two or more different solutions to the same problem and compare their outputs to the same, randomly generated, inputs. If the output for a given input should always be the same, the outputs from all solutions should be equal. Meaning this is a good way to find if there's a bug in one of the implementations. 

## W2 (Basic Algorithms and Big-O Notation)

Big-O analysis is important but shouldn't be the only thing considered when choosing an algorithm.
This analysis throws away information which, sometimes, could be important for specific problems/situations.

e.g.: Airplane may be the fastest way to travel, but it is good for long distances. For short enough distances, other methods might be better: you don't take an airplane to your street corner, you walk to it. Airplanes are faster than walking/cars, but they are better only starting at some long enough distance. The same goes for algorithms: some are faster/better but it's once you have some big enough input.

## W3 (Greedy Algorithms)

Greedy Algorithms try to solve a given problem by iteratively selecting a local optimum "best action" until the problem is solved. It won't always find the global optimum.

## W4 (Divide and Conquer Algorithms)

Most of them often have a recursive definition that (usually) can be turned into an iterative one. They divide the problem in smaller subproblems until a minimal problem is reached, solved and it goes back solving the bigger problems from the solved subproblems.

Interesting things: Karatsuba's polynomial and big numbers multiplication.

Other quadratic sorting algorithms: insertion sort, bubble sort.

### Linear Search - O(n)

- The array can be in any order;
- Goes through an array from start to end until a given value is found.

### Binary Search - O(log n)

- The array needs to be sorted;
- Makes use of the fact that the array is sorted to find the value faster: it recursively looks at the middle position and goes to the left if the searched value is smaller than the middle one or to the right otherwise.
