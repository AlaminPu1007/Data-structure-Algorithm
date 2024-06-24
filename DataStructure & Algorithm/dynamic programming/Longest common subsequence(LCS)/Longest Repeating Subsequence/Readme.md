# Longest Repeating Subsequence

This problem involved about, given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.<br/>

## Problem description

For better problem description, please visit [LeetCode Page](https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1)

### Recursion Approach (Time limit exceed)

**Approach :**<br/>

1. `Dynamic Programming with Recursion :`- Use a recursive approach with dynamic programming to find the longest repeating subsequence.
2. `Recursive Function :`
    - Define a recursive function `DFS` that takes two indices `i` and `j` for the two strings being compared.
    - Compare characters from the end of the strings and use memoization to store intermediate results.
    - If the characters match and the indices are different, include this character in the subsequence.
    - If they do not match or the indices are the same, recursively check the subsequences excluding the current character from one of the strings.

**Algorithm :**<br/>

1. Define the recursive function `DFS` with parameters `str1`, `i`, `str2`, `j`.
2. Base Case:
    - If `i <= 0` or `j <= 0`, return 0.
3. Recursive Case:
    - If `str1[i-1]` is equal to `str2[j-1]` and `i` is not equal to `j`, return `1 + DFS(str1, i-1, str2, j-1)`.
    - Otherwise, return the maximum of `DFS(str1, i-1, str2, j)` and `DFS(str1, i, str2, j-1)`.
4. Initialize the recursive process with `DFS(str, n, str, n)`.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(2 ^ n)` - The time complexity is `O(2^n)` in the worst case because each character comparison can lead to two recursive calls. However, this is highly inefficient and can be optimized using dynamic programming.

-   Space-Complexity: `O(n + m)` - The space complexity is `O(n + m)` due to the recursion stack.

<br/>
<br/>

### Recursion + Memoization Approach (Time limit exceed)

**Approach :**<br/>

1. `Dynamic Programming with Recursion and Memoization :` Use a recursive approach with dynamic programming and memoization to find the longest repeating subsequence.

2. `Recursive Function :`
    - Define a recursive function `DFS` that takes two indices `i` and `j` for the two strings being compared.
    - Compare characters from the end of the strings and use memoization to store intermediate results.
    - If the characters match and the indices are different, include this character in the subsequence.
    - If they do not match or the indices are the same, recursively check the subsequences excluding the current character from one of the strings.

**Algorithm :**<br/>

1. Define the recursive function `DFS` with parameters `str1`, `i`, `str2`, `j`, and `dp`.
2. Base Case:
    - If `i <= 0` or `j <= 0`, return 0.
3. Check the cache:
    - If `dp[i][j]` is not `-1`, return `dp[i][j]`.
4. Recursive Case:
    - If `str1[i-1]` is equal to `str2[j-1]` and `i` is not equal to `j`, set `dp[i][j]` to `1 + DFS(str1, i-1, str2, j-1, dp)`.
    - Otherwise, set `dp[i][j]` to the maximum of `DFS(str1, i-1, str2, j, dp)` and `DFS(str1, i, str2, j-1, dp)`.
5. Initialize the memoization table `dp` with size `(n+1) x (n+1)` and all values set to `-1`.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n^2 * m^2)` - Each state `O(n^2 * m^2)` is computed once, and there are `n * m` such states.

-   Space-Complexity: `O(n * m)` - The space required for the dp array is `n * m`.

<br/>
<br/>

### Bottom up (Tabulation) approach

**Approach :**<br/>

1. `Dynamic Programming :` Use a 2D table to store the length of the longest repeating subsequence.
2. `Table Definition :`
    - Define `dp[i][j]` to be the length of the longest repeating subsequence of `str[0..i-1]` and `str[0..j-1]`.

**Algorithm :**<br/>

1. Initialize a 2D vector `dp` with dimensions `(n+1) x (n+1)` and all values set to `0`, where `n` is the length of the string `str`.
2. Iterate through each character in the string using two nested loops:
    - For each pair of indices `(i, j)`, check if `str[i-1]` is equal to `str[j-1]` and `i` is not equal to `j`.
    - If the characters match and the indices are different, set `dp[i][j] = 1 + dp[i-1][j-1]`.
    - Otherwise, set `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
3. The value at `dp[n][n]` will be the length of the longest repeating subsequence.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n * m)` - We iterate through the entire 2D dp array once, where n and m are the lengths of text1 and text2 respectively.
-   Space-Complexity: `O(n * m)` - We use a 2D array dp of size (n+1) x (m+1) to store the lengths of longest common subsequences.