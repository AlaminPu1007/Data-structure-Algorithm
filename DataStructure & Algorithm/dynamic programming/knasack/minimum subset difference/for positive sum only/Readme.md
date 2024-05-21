## Minimum sum partition (NOTE: This solution is only work for positive sum.)

This problem involved about, Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference.<br/>

# Problem description

For better problem description, please visit [GFG](https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1)

**Approach :**<br/>

1. Calculate the total sum of all elements in the given array.
2. Initialize a DP table `dp` of size `(n+1) x (total_sum/2 + 1)` with `false` values.
3. Set `dp[i][0]` to `true` for all `i` from 0 to `n`.
4. Iterate through each element `nums[i]` and for each possible sum `j` from 1 to `total_sum/2`:
   - Update `dp[i][j]` based on whether `nums[i]` can be included to achieve sum `j`.
5. Collect all valid sums from the last row of the DP table.
6. Compute the minimum difference between the total sum and twice each valid sum.
7. Return the minimum difference as the result.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n * m)` - Constructing the DP table requires iterating through each element of the array `nums` and for each element, iterating through each possible sum from 1 to `total_sum/2`.

- Space-Complexity: `O(n * m)` - The DP table requires `(n+1) x (sum/2 + 1)` space.