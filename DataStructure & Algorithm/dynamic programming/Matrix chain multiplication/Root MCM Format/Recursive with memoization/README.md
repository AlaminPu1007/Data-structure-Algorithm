# Matrix Chain Multiplication (MCM) (Using Memoization)

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array `arr[] of size N (such that N = number of matrices + 1)` where the ith matrix has the dimensions `(arr[i-1] x arr[i])`.

## Problem description

For better problem description, please visit [GFG](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

**Approach :**

1. **Recursive Method**: Use a recursive function to find the minimum cost to multiply the matrices.
2. **Divide and Conquer**: Split the problem into smaller subproblems and solve each subproblem independently.
3. **Memoization**: (Not implemented in the code below) Store the results of subproblems to avoid redundant calculations.

**Algorithm :**

1. **Base Case**: When the chain length is 1 (i.e., `i >= j`), no multiplication is needed.
2. **Recursive Case**:

   - Iterate over possible places to split the matrix chain.
   - Calculate the cost of multiplying the resulting two matrices.
   - Sum up the cost of the current matrix multiplication with the minimum cost of each subgroup.
   - Update the answer with the minimum cost found.

**Complexity Analysis :**

-   Time-Complexity: `O(n ^ 3)` - memoization using the dp table avoids redundant calculations. Once a subproblem with indices` (i, j)` is solved, its result is stored in `dp[i][j]` and reused in future calls, reducing redundant computations.

-   Space-Complexity: `O(n^2)` - The dp table is a 2D vector of size `n x n`