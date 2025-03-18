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

    - Use `dynamic programming with memoization` to solve the problem.
    - Define a DP table `dp[i][j]` to store the maximum number of uncrossed lines between the subarrays `nums1[i..n-1]` and `nums2[j..m-1]`.
    - If `nums1[i] == nums2[j]`, draw a line and recursively compute the result for the remaining subarrays.
    - If `nums1[i] != nums2[j]`, skip either `nums1[i]` or `nums2[j]` and recursively compute the result.
    - Use memoization to avoid redundant calculations.

3. `Steps`:
    - Initialize a DP table `dp` of size `(n + 1) x (m + 1)` with `-1` to represent uncomputed states.
    - Define a recursive function `Solved`:
        - If either `i` or `j` exceeds the array bounds, return `0`.
        - If the result for the current state `(i, j)` is already computed, return it.
        - If `nums1[i] == nums2[j]`, draw a line and recursively compute the result for `(i + 1, j + 1)`.
        - If `nums1[i] != nums2[j]`, skip either `nums1[i]` or `nums2[j]` and recursively compute the result.
        - Store the result in the DP table and return it.
    - Call the recursive function with initial parameters `(0, 0)`.

**Complexity Analysis :**<br/>

-   Time-complexity: `O(n * m)` - where `n` is the size of `nums1` and `m` is the size of `nums2`.
-   Space-Complexity: `O(n * m)` - due to the DP table.
