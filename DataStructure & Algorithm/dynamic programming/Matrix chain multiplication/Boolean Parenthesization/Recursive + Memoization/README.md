# Boolean Parenthesization

This problem involved about, given a boolean expression s with following symbols.

```
'T' ---> true
'F' ---> false
and following operators between symbols
& ---> boolean AND
| ---> boolean OR
^ ---> boolean XOR
```

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

## Problem description

For better problem description, please visit [GeekForGeeks Page](https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1)

**Approach :**<br/>

1. `Dynamic Programming (Memoization)`:

    - Use a 3D DP table `dp[i][j][isTrue]` to store the number of ways to evaluate the substring `exp[i...j]` to `true` or `false`.
    - This avoids redundant computations by storing results of subproblems.

2. `Base Cases`:

    - If `i > j`, it's an invalid case, so return `0`.
    - If `i == j`, check if the single character matches the desired result (`true` or `false`).

3. `Operator Handling`:

    - For each operator (`&`, `|`, `^`), compute the number of ways to achieve the desired result (`true` or `false`) based on the truth tables of the operators.
    - Use the results of subproblems (`lT`, `lF`, `rT`, `rF`) to calculate the total number of ways.

4. `Modulo Operation`:
    - Since the result can be large, use modulo `10^9 + 7` to prevent integer overflow.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(n^3)`

    1.  The DP table ensures that each `sub-problem` is solved only once.
    2.  There are `O(n^2)` `sub-problems` (for each `i` and `j`), and each subproblem takes `O(n)` time to compute (due to the loop over operators).
    3.  Therefore, the time complexity is `O(n^3)`.

-   Space-Complexity: `O(n^2)` - The DP table has dimensions `n x n x 2`, so the space complexity is `O(n^2)`.
