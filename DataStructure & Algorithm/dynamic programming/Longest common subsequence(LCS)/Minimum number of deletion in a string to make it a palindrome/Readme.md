# Minimum number of deletion in a string to make it a palindrome

This problem involved about,

## Problem description

For better problem description, please visit [LeetCode Page](https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1)

### Recursion

**Approach :**<br/>

1. **Initialization:**

    - Reverse the input string to get `revStr`.

2. **DFS Function:**

    - If either of the string lengths (`n` or `m`) is zero, return 0.
    - If the last characters of both strings match, increment the count by 1 and recursively call the DFS function excluding these characters from both strings.
    - If the last characters do not match, find the maximum LCS by either excluding the last character of the original string or the reversed string.

3. **Result Calculation:**

    - The minimum deletions required would be the difference between the original string length and the LCS length.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(2 ^ n)` - because it explores all possible subsequences.

-   Space-Complexity: `O(n + m)` - due to the recursion stack where `n` and `m` are the lengths of the input strings.

<br/>
<br/>

### Recursion with memoization

**Approach :**<br/>

1. **Initialization:**

    - Reverse the input string to get `revStr`.
    - Initialize a 2D vector `dp` of size `(n+1) x (n+1)` with all elements set to `-1` to store intermediate LCS results.

2. **DFS Function with Memoization:**

    - If either of the string lengths (`n` or `m`) is zero, return 0.
    - If the result for the current state `(n, m)` is already computed (`dp[n][m] != -1`), return the stored result.
    - If the last characters of both strings match, store and return the result of 1 plus the LCS of the remaining substrings.
    - If the last characters do not match, store and return the maximum LCS by either excluding the last character of the original string or the reversed string.

3. **Result Calculation:**
    - The minimum deletions required would be the difference between the original string length and the LCS length.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n ^ 2)` - due to the memoization of results for each substring pair.

-   Space-Complexity: `O(n ^ 2)` - for storing the intermediate results in the 2D vector `dp`.

<br/>
<br/>

### Bottom up or Tabulation approach (Accepted solution)

**Approach :**<br/>

1. **Initialization:**

    - Reverse the input string to get `revStr`.
    - Initialize a 2D vector `dp` of size `(n+1) x (n+1)` with all elements set to `0` to store the lengths of LCS.

2. **Fill DP Table:**

    - Use nested loops to fill the `dp` table:
        - If characters `str[i-1]` and `revStr[j-1]` match, set `dp[i][j]` to `1 + dp[i-1][j-1]`.
        - Otherwise, set `dp[i][j]` to the maximum of `dp[i-1][j]` and `dp[i][j-1]`.

3. **Result Calculation:**

    - The minimum deletions required would be the difference between the original string length and the value `dp[n][n]`, which is the length of the LCS.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(2 ^ n)` - time due to the nested loops filling the `dp` table.

-   Space-Complexity: `O(n + m)` - for storing the intermediate results in the 2D vector `dp`.
