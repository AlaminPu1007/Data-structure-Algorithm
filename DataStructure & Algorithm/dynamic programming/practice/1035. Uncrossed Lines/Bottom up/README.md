# 1035. Uncrossed Lines

This problem involved about, you are given two integer arrays `nums1` and `nums2`. We write the integers of `nums1` and `nums2` (in the order they are given) on two separate horizontal lines.

## Problem description

For better problem description, please visit [LeetCode Page](https://leetcode.com/problems/uncrossed-lines/description/)

**Approach :**<br/>

1. `Problem Analysis`:

    - We are given two arrays `nums1` and `nums2`.
    - The goal is to find the maximum number of uncrossed connecting lines between the two arrays.
    - A connecting line is drawn between `nums1[i]` and `nums2[j]` if `nums1[i] == nums2[j]`, and the lines do not intersect.

2. `Algorithm`:

    - Use `dynamic programming` to solve the problem.
    - Define a DP table `dp[i][j]` to store the maximum number of uncrossed lines between the subarrays `nums1[0..i-1]` and `nums2[0..j-1]`.
    - Initialize the first row and first column of the DP table to `0` because no lines can be drawn if one of the arrays is empty.
    - Iterate through the arrays:
        - If `nums1[i - 1] == nums2[j - 1]`, draw a line and add `1` to the result from `dp[i - 1][j - 1]`.
        - If `nums1[i - 1] != nums2[j - 1]`, skip either `nums1[i - 1]` or `nums2[j - 1]` and take the maximum result from `dp[i - 1][j]` or `dp[i][j - 1]`.
    - Return `dp[n][m]`, which contains the result for the full arrays.

3. `Steps`:
    - Initialize a DP table `dp` of size `(n + 1) x (m + 1)` with `0`.
    - Fill the first row and first column with `0`.
    - Iterate through the arrays using nested loops:
        - If the current elements match, update `dp[i][j]` as `1 + dp[i - 1][j - 1]`.
        - If the current elements do not match, update `dp[i][j]` as `max(dp[i - 1][j], dp[i][j - 1])`.
    - Return `dp[n][m]`.

**Complexity Analysis :**<br/>

-   Time-complexity: `O(n * m)` - where `n` is the size of `nums1` and `m` is the size of `nums2`.
-   Space-Complexity: `O(n * m)` - due to the DP table.
