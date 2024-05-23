## 494. Target Sum

This problem involved about, you are given an integer array nums and an integer target.<br/>

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

# Problem description

For better problem description, please visit [LeetCode Page](https://leetcode.com/problems/target-sum/description/)

**Approach :**<br/>

1. Calculate the total sum `sum` of the elements in `nums`.
2. Check if `sum < abs(target)` or `(sum - target) < 0` or `(sum - target) % 2 == 1`. If true, return 0.
3. Calculate the required sum `targetSum` as `(target + sum) / 2`.
4. Initialize a DP table `dp` of size `(n+1) x (targetSum + 1)`.
5. Initialize the first row of `dp` to 0 and the first column to 1.
6. Iterate through each element of `nums` and for each possible sum from 0 to `targetSum`, update `dp` based on whether the current element can be included or excluded.
7. Return `dp[n][targetSum]`.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n * targetSum)` - Constructing the DP table requires iterating through each element of the array `nums` and for each element, iterating through each possible sum from 0 to `targetSum`.

- Space-Complexity: `O(n * targetSum)` - The DP table requires `(n + 1) x (targetSum + 1)` space.