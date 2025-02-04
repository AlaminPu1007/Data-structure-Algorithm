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

1. `Recursive Division`:

    - The expression is divided into smaller sub-expressions using operators.
    - For each operator, we recursively calculate the number of ways to evaluate the left and right sub-expressions to `true` or `false`.

2. `Base Cases`:

    - If the start index `i` is greater than the end index `j`, it's an invalid case, so return `0`.
    - If `i == j`, check if the single character matches the desired result (`true` or `false`).

3. `Operator Handling`:

    - For each operator (`&`, `|`, `^`), compute the number of ways to achieve the desired result (`true` or `false`) based on the truth tables of the operators.

4. `Modulo Operation`:
    - Since the result can be large, use modulo `10^9 + 7` to prevent integer overflow.

**Complexity Analysis :**<br/>

-   Time-Complexity:

    1.  The recursive function explores all possible ways to parenthesize the expression.
    2.  For each operator, it splits the problem into two sub-problems.
    3.  The time complexity is exponential, approximately `O(2^n)`, where `n` is the length of the string.

-   Space-Complexity: `O(n)` -
    1.  The space complexity is determined by the recursion stack.
    2.  In the worst case, the recursion depth can be `O(n)`.
    3.  Therefore, the space complexity is `O(n)`.
