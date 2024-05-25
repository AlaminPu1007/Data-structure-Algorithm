## Rod Cutting

This problem involved about, given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.<br/>

# Problem description

For better problem description, please visit [GFG page](https://www.geeksforgeeks.org/problems/rod-cutting0840/1)

### Top Down Approach (Recursion + Memoization)

**Approach :**<br/>

1. **Initialization**:

    - Create an array `lengthArr` where `lengthArr[i]` represents the length of the rod piece, which is `i+1`.
    - Initialize a DP table `dp` of size `(n+1) x (n+1)` with `-1` to indicate uncomputed states.

2. **Recursive Function with Memoization**:

    - Define a recursive function `DFS` that computes the maximum profit for a rod of length `maxLen` using pieces up to index `n`.
    - Base cases:
        - If `n < 0` or `maxLen < 0`, return 0 since no profit can be made.
        - If `dp[n][maxLen]` is already computed, return its value.
    - Recursive cases:
        - If the current piece length `lengthArr[n]` is less than or equal to `maxLen`, compute the maximum profit by either including the current piece or excluding it.
        - If the current piece length `lengthArr[n]` is greater than `maxLen`, exclude it.

3. **Result**:
    - Call the recursive function `DFS` with initial parameters to compute the maximum profit for a rod of length `n`.

#### Algorithm

1. Create an array `lengthArr` of size `n`.
2. Initialize the DP table `dp` of size `(n+1) x (n+1)` with `-1`.
3. Define the recursive function `DFS` to compute the maximum profit.
4. Call `DFS(price, lengthArr, n-1, n, dp)` and return the result.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n ^ 2)` - The DP table requires `(n+1) x (n+1)` space.
-   Space-Complexity: `O(n)` - The recursion stack can go as deep as the number of elements in `lengthArr`.

### Bottom Up Approach (Tabulation Process)

**Approach :**<br/>

1. Create an array `lengthArr` of size `n`.
2. Initialize the DP table `dp` of size `(n+1) x (n+1)` with `0`.
3. Iterate through each piece length from `1` to `n`.
4. For each piece length, iterate through each rod length from `1` to `n`.
5. If the current piece length is less than or equal to the current rod length, update the DP table by considering the maximum profit of including or excluding the piece.
6. Return the value in `dp[n][n]`.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n ^ 2)` - Iterate over the dp array.
-   Space-Complexity: `O(n ^ n)` - we are using an two dimensional array
