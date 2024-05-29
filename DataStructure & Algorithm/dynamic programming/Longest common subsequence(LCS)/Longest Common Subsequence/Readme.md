## 1143. Longest Common Subsequence

This problem involved about, given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

# Problem description

For better problem description, please visit [LeetCode Page](https://leetcode.com/problems/longest-common-subsequence/description/)

### Recursive solution without memoization

**Approach :**<br/>

1. **Initialize DFS Function**:

   - Create a private DFS function that recursively finds the LCS length by comparing characters from the end of both strings.

2. **Base Cases**:

   - If either index `n` (for `text1`) or `m` (for `text2`) is less than 0, return 0 because we have reached the end of one string.

3. **Character Comparison**:

   - If the characters at the current indices `n` and `m` of `text1` and `text2` respectively are the same, recursively call DFS for the previous indices and add 1 to the result.
   - If the characters are different, recursively call DFS for:
     - The previous index of `text1` and the current index of `text2`.
     - The current index of `text1` and the previous index of `text2`.
   - Return the maximum of the two recursive calls.

4. **Return Result**:
   - Call the DFS function from the `longestCommonSubsequence` function with the last indices of both strings.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(2 ^ n)` - The time complexity is `O(2^n)` in the worst case because each character comparison can lead to two recursive calls. However, this is highly inefficient and can be optimized using dynamic programming.

- Space-Complexity: `O(n + m)` - The space complexity is `O(n + m)` due to the recursion stack.

<br/>

### Recursive with memoization(Top down) Approach

**Approach :**<br/>

1. **Initialization**:
   - Define the recursive function `DFS` to compute the LCS of substrings.
   - Use a 2D array `dp` to store the results of subproblems. `dp[i][j]` represents the length of the LCS of `text1[0...i]` and `text2[0...j]`.
2. **Base Case**:

   - If either string is empty (`n < 0` or `m < 0`), return 0 because an empty string has no common subsequence with any string.

3. **Recursive Case**:

   - If `text1[n] == text2[m]`, include this character in the LCS and recurse for the remaining substrings (`n-1` and `m-1`).
   - If `text1[n] != text2[m]`, find the maximum LCS by either excluding the current character of `text1` or `text2` and recursing accordingly.

4. **Memoization**:
   - Check if the result for the current state (`dp[n][m]`) is already computed. If yes, return the stored result.
   - Store the computed result in `dp[n][m]` before returning it.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n^2 * m^2)` - Each state `O(n^2 * m^2)` is computed once, and there are `n * m` such states.

- Space-Complexity: `O(n * m)` - The space required for the `dp` array is `n * m`.

<br/>

### Bottom up (Tabulation) approach

**Approach :**<br/>

1. **Initialization**:

   - Initialize a 2D array `dp` of size `(n+1) x (m+1)` with all elements initialized to 0. Here, `n` and `m` are the lengths of `text1` and `text2` respectively.
   - The cell `dp[i][j]` represents the length of the longest common subsequence of `text1.substr(0, i)` and `text2.substr(0, j)`.

2. **Dynamic Programming**:

   - Iterate through `text1` and `text2` using nested loops.
   - If the characters at the current indices match, increment the value in `dp[i][j]` by 1 plus the value in the top-left diagonal cell (`dp[i-1][j-1]`).

   - If the characters don't match, take the maximum of the values from the cell above (`dp[i-1][j]`) and the cell to the left (`dp[i][j-1]`).

3. **Result**:

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n * m)` - We iterate through the entire 2D `dp` array once, where `n` and `m` are the lengths of `text1` and `text2` respectively.

- Space-Complexity: `O(n * m)` - We use a 2D array `dp` of size `(n+1) x (m+1)` to store the lengths of longest common subsequences.