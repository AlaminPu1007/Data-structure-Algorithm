// This code solves the Matrix Chain Multiplication (MCM) problem using recursion.
// It finds the minimum number of scalar multiplications needed to multiply a chain of matrices.

// References: https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Main function to initiate the matrix chain multiplication
  int mcm(vector<int> &arr)
  {
    // i is the starting index of the matrix chain, and j is the ending index
    int i = 1, j = arr.size() - 1;
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

    // Call the recursive function to get the minimum cost
    return recursive_mcm(arr, i, j, dp);
  }

private:
  // Recursive function to calculate the minimum cost of multiplying matrices from index i to j
  int recursive_mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
  {

    // Base case: when the chain length is 1, no multiplication is needed
    if (i >= j)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    // Initialize the minimum cost to the maximum possible value
    int ans = INT_MAX;

    // to avoid empty set or empty multiplication we will iterate till k <= (j-1)
    for (int k = i; k < j; k++)
    {
      // now split multiplication into two group
      // after getting minimum cost for each group then sum up with current matrix multiplication
      // Iterate over possible places to split the matrix chain

      int tempAns = (
          // (i to k)
          recursive_mcm(arr, i, k, dp) +

          // (k+1 to j)
          recursive_mcm(arr, k + 1, j, dp) +

          // now inclusive current matrix sum
          /*
            ex:
                1) (AB) = some_cost  // get from (i to k)
                2) (CD) = some_cost  // get from (k+1 to j)
                now get the equation (1) and (2) from below

                ex: we get new dimension after multiplication: for (AB) = (40 * 30), for (CD) = (30 * 30)
                new matrix would be: (AB) * (CD) => (40 * 30 * 30 * 30) => (40 *30 * 30) // `30 * 30` -> this will exclude for new matrix dimension
          */

          // Cost of multiplying the resulting two matrices
          // The dimensions of the resulting matrix are arr[i-1] x arr[k] and arr[k] x arr[j]

          arr[i - 1] * arr[k] * arr[j]

      );

      // Update the answer with the minimum cost found
      ans = min(ans, tempAns);
    }

    // Return the minimum cost for multiplying matrices from i to j
    return dp[i][j] = ans;
  }
};

int main(void)
{
  Solution obj;
  vector<int> arr = {40, 20, 30, 10, 30};
  cout << obj.mcm(arr) << endl;
  return 0;
}