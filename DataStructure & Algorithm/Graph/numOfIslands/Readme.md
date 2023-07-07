## Number of Islands – II – Online Queries

This Problem involved about, You are given a n,m which means the row and column of the 2D matrix and an array of size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.

# Problem description

For better problem description, please visit [GeekForGeeks Page](https://practice.geeksforgeeks.org/problems/number-of-islands/1)

**Approach (Algorithm):**<br/>

-   First, we will iterate over all the queries selecting each at a time. Now, we can get the row and the column of the cell given in that query.
-   Then, we will check that cell in the visited array, if the cell is previously visited or not
    1. If the cell is previously visited, we will just take the current count into our account storing that count value in our answer array and we will move on to the next query.
    2. Otherwise, we will mark the cell as visited in the visited array and increase the value of the counter variable by 1
        - Now, it’s time to connect the adjacent islands properly. For that, we will check all four adjacent cells of the current cell. If any island is found, we will first check if they(the current cell and the adjacent cell that contains an island) are already connected or not using the findUPar() method.
        - For checking, we will first convert the indices of the current cell and the adjacent cell into the numbers using the specified formula. Then we will check their ultimate parents.
        - If the ultimate parents are different, we will decrease the counter value by 1 and perform the union(either unionBySize() or unionByRank()) between those two numbers that represent the cells.
        - Similarly, checking all four sides and making the required changes in the counter variable, we will put the counter value into our answer array

3. After performing step 2 for all the queries, we will get our final answer array containing the results for all the queries.

**Complexity Analysis :**<br/>

-   Time-Complexity: `O(Q*4α) ~ O(Q)` - where Q = no. of queries. The term 4α is so small that it can be considered constant.
-   Space-Complexity: `O(Q) + O(N*M) + O(N*M)`, - where Q = no. of queries, N = total no. of rows, M = total no. of columns. The last two terms are for the parent and the size array used inside the Disjoint set data structure. The first term is to store the answer
