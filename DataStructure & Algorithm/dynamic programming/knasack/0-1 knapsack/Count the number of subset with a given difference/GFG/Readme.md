## Partitions with Given Difference

This problem involved about, given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2.

# Problem description

For better problem description, please visit [GFG Page](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

### This approach is for Tabulation process

**Approach :**<br/>

1. Calculate the total sum `sum` of the elements in `arr`.
2. Check if `(sum - d)` is negative or odd. If true, return 0.
3. Calculate the required sum `reqSum` as `(d + sum) / 2`.
4. Initialize a DP table `dp` of size `(n+1) x (reqSum + 1)`.
5. Initialize the first row of `dp` to 0 and the first column to 1.
6. Iterate through each element of `arr` and for each possible sum from 0 to `reqSum`, update `dp` based on whether the current element can be included or excluded.
7. Return `dp[n][reqSum]`.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n*m)` - Constructing the DP table requires iterating through each element of the array `arr` and for each element, iterating through each possible sum from 0 to `m`.

- Space-Complexity: `O(n*m)` - The DP table requires `(n+1) x (m + 1)` space.

### Some key point to should be noted

1. **Initial Column Initialization :**<br/>

   - We initialize the first column (j = 0) to 1, assuming that there is only one way to make a subset sum equal to 0, which is by having an empty subset (null subset).

   - This initialization represents the base case, where we have an empty subset contributing to a sum of 0. Hence, dp[i][0] is set to 1 for all i.

2. **Handling Zeroes in the Array :**<br/>

   - If the array contains zeroes as elements, we need to account for subsets that include these zeroes and still contribute to a sum of 0.

   - For example, if the array contains a single zero, then there are two subsets that contribute to a sum of 0: the null subset {} and the subset containing the zero {0}.

   - By starting j from 0, we ensure that we consider the possibility of including zeroes in subsets and still achieving a sum of 0.