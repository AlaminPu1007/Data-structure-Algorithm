## Count of subsets sum

This problem involved about, we are given a array of integers, we have to find out the subset where it's summation should be equal to given sum.

### Brute Force Approach

**Approach :**<br/>

1. **Initialize Parameters**:

   - Define the size of the input array `n`.
   - Call the helper function `DFS` with the initial parameters: the `nums` array, `n-1` (the last index), and the target sum.

2. **DFS Function**:
   - The DFS function recursively explores all possible subsets.
   - **Base Cases**:
     - If `sum` is `0`, it means a valid subset is found, so return `1`.
     - If `n` is less than `0` or `sum` is less than `0`, it means no valid subset can be formed, so return `0`.
   - **Recursive Cases**:
     - If the current element (`nums[n]`) is less than or equal to the `sum`, there are two possibilities:
       1. Include the current element in the subset and reduce the `sum` accordingly (`sum - nums[n]`).
       2. Exclude the current element from the subset.
     - If the current element is greater than the `sum`, simply exclude it from the subset.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(2^n)` - The algorithm explores each subset, resulting in a time complexity of `O(2^n)`, where `n` is the number of elements in the array. This exponential time complexity arises because each element can either be included or excluded from the subset.

- Space-Complexity: `O(n)` - The space complexity is `O(n)` due to the recursion stack, which at most goes `n` levels deep.

### DFS with memoization

**Approach :**<br/>

1. **Initialize Parameters**:

   - Define the size of the input array `n`.
   - Initialize a 2D vector `dp` of size `(n+1) x (sum+1)` with `-1` to store intermediate results. This helps in avoiding recomputation of the same sub-problems.
   - Call the helper function `DFS` with the initial parameters: the `nums` array, `n-1` (the last index), the target sum, and the `dp` vector.

2. **DFS Function**:

   - The DFS function recursively explores all possible subsets and uses memoization to store results of sub-problems.

   - **Base Cases**:

     - If `sum` is `0`, it means a valid subset is found, so return `1`.
     - If `n` is less than `0` or `sum` is less than `0`, it means no valid subset can be formed, so return `0`.

   - **Memoization Check**:

     - If the result for `dp[n][sum]` is already computed (not equal to `-1`), return that result to avoid redundant computation.

   - **Recursive Cases**:

     - If the current element (`nums[n]`) is less than or equal to the `sum`, there are two possibilities:

       1. Include the current element in the subset and reduce the `sum` accordingly (`sum - nums[n]`).
       2. Exclude the current element from the subset.

     - If the current element is greater than the `sum`, simply exclude it from the subset.
     - Store the result in `dp[n][sum]` to use it in future sub-problems.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n * m)` - The algorithm now runs in polynomial time due to memoization. Each sub-problem is solved once and stored, resulting in a time complexity of `O(n * m)`.

- Space-Complexity: `O(n * m)` - The space complexity is `O(n * m)` for the `dp` array. Additionally, the recursion stack can go up to `n` levels deep.

### Tabulation Approach (BottomUp Approach)

**Approach :**<br/>

1. Initialize a 2D vector `dp` of size `(n + 1) x (sum + 1)` with all values initialized to `-1`.
2. Initialize `dp[0][i] = 0` for all `i` from `0` to `sum` to represent that there are no subsets possible with a non-zero sum using an empty array.
3. Initialize `dp[i][0] = 1` for all `i` from `0` to `n` to represent that there is only one subset possible with sum `0`, i.e., the empty subset.
4. Iterate through the elements of `nums` and fill the `dp` array accordingly. For each element `nums[i]`, if it's less than or equal to `j`, then `dp[i][j]` can be formed by either including or excluding `nums[i]`. So, `dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j]`. Otherwise, if `nums[i]` is greater than `j`, then `dp[i][j]` can only be formed by excluding `nums[i]`, so `dp[i][j] = dp[i - 1][j]`.
5. Finally, return `dp[n][sum]`, which represents the count of subsets with a sum equal to `sum`.

**Complexity Analysis :**<br/>

- Time-Complexity: `O(n * m)` - where n is the size of the nums array and sum is the target sum. This is because we are filling a 2D array of size `(n + 1) x (sum + 1)`.

- Space-Complexity: `O(n * m)` - as we are using a 2D array of size `(n + 1) x (sum + 1)` to store the intermediate results.