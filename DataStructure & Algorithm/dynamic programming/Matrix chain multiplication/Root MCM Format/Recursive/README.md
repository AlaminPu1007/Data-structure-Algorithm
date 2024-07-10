# Matrix Chain Multiplication (MCM)

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array `arr[] of size N (such that N = number of matrices + 1)` where the ith matrix has the dimensions `(arr[i-1] x arr[i])`.

## Problem description

For better problem description, please visit [GFG](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

**Approach :**<br/>

1. **Recursive Method**: Use a recursive function to find the minimum cost to multiply the matrices.

2. **Divide and Conquer**: Split the problem into smaller subproblems and solve each subproblem independently.

3. **Memoization**: (Not implemented in the code below) Store the results of subproblems to avoid redundant calculations.

**Algorithm :**<br/>

1. **Base Case**: When the chain length is 1 (i.e., `i >= j`), no multiplication is needed.

2. **Recursive Case**:

    - Iterate over possible places to split the matrix chain.
    - Calculate the cost of multiplying the resulting two matrices.
    - Sum up the cost of the current matrix multiplication with the minimum cost of each subgroup.
    - Update the answer with the minimum cost found.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(2^n)` - The recursive function `recursive_mcm` explores all possible ways to parenthesize the matrix chain, leading to a branching factor of 2 at each level `(due to the for loop iterating over k)`.

-   Space-Complexity: `O(n)` - where `n` is the depth of the recursion tree. The maximum depth of the recursion tree is `n`.