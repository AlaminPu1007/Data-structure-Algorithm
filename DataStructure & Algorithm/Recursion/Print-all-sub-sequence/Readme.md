# Using recursion(Backtracking) to printf all subsequence

**Approach :**<br>

Since we are generating subsets two cases will be possible, either you can pick the character or you cannot pick the character and move to the next character.<br>

// from below this out-put, we get first 4 element from first recursion, and last four element we will get after remove pop_back last element from string<br>
// after complete first recursion properly then call next recursion method.

- out put will be (312, 31, 32, 3, 12, 1, 2,{}) <br>

**Complexity :**<br>
Time Complexity: O(2^n)<br>

Space Complexity: O(n), recursion stack.<br>
