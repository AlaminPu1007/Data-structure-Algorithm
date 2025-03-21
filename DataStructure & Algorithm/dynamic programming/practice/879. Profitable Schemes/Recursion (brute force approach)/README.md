# 879. Profitable Schemes

This problem involved about, there is a group of n members, and a list of various crimes they could commit. The ith crime generates a `profit[i]` and requires `group[i]` members to participate in it. If a member participates in one crime, that member can't participate in another crime.

## Problem description

For better problem description, please visit [LeetCode Page](https://leetcode.com/problems/profitable-schemes/description/)

**Approach :**<br/>

1. `Problem Analysis`:

    - We are given `n` people, a minimum required profit `minProfit`, and two arrays `group` and `profit`.
    - `group[i]` represents the number of people required for the `i-th` crime.
    - `profit[i]` represents the profit generated by the `i-th` crime.
    - The goal is to find the number of schemes (combinations of crimes) that:
        - Use at most `n` people.
        - Generate at least `minProfit` profit.

2. `Algorithm`:

    - Use `recursion with memoization` to explore all possible combinations of crimes.
    - For each crime, decide whether to include it in the scheme or not.
    - If a crime is included, update the number of people used and the total profit.
    - If the number of people exceeds `n`, backtrack.
    - If all crimes are processed, check if the total profit meets or exceeds `minProfit`.
    - Use memoization to avoid redundant calculations.

3. `Steps`:
    - Define a recursive function `Solved`:
        - If the number of people exceeds `n`, return `0`.
        - If all crimes are processed, return `1` if the total profit meets or exceeds `minProfit`; otherwise, return `0`.
        - Recursively compute the number of schemes by:
            - Excluding the current crime.
            - Including the current crime (if the number of people does not exceed `n`).
        - Return the sum of the two results modulo `1e9 + 7`.
    - Call the recursive function with initial parameters `(0, 0, 0)`.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(2^n)` - an exponential time complexity in the worst case.
-   Space-Complexity: `O(n)` - recursive stack.
