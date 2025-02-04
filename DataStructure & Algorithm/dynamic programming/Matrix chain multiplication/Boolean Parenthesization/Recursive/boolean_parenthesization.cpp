/**
 * We follow a recursive approach to solve this problem.
 * For this solution we will get "Time Limit Exceeded".
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

class Solution
{
public:
    // Function to count the number of ways to parenthesize the boolean expression to evaluate to true
    int countWays(string s)
    {
        int n = s.size();
        return Solve(0, n - 1, 1, s);
    }

private:
    // Recursive function to count the number of ways to evaluate the expression to the desired value
    int Solve(int i, int j, int isTrue, string &exp)
    {
        // Base case 1: If i > j, it's an invalid expression, return 0.
        if (i > j)
            return 0;

        // Base case 2: If i and j are the same, evaluate the single character.
        if (i == j)
        {
            if (isTrue == 1)
                return exp[i] == 'T' ? 1 : 0;
            else
                return exp[i] == 'F' ? 1 : 0;
        }

        ll ans = 0;

        // Iterate through the expression.
        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            ll leftTrue = Solve(i, ind - 1, 1, exp);   // Number of ways to make the left expression true.
            ll leftFalse = Solve(i, ind - 1, 0, exp);  // Number of ways to make the left expression false.
            ll rightTrue = Solve(ind + 1, j, 1, exp);  // Number of ways to make the right expression true.
            ll rightFalse = Solve(ind + 1, j, 0, exp); // Number of ways to make the right expression false.

            // Check the operator at the current index and update ways accordingly.
            if (exp[ind] == '&')
            {
                if (isTrue)
                    ans = (ans + (leftTrue * rightTrue) % mod) % mod;
                else
                    ans = (ans + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightFalse) % mod) % mod;
            }
            else if (exp[ind] == '|')
            {
                if (isTrue)
                    ans = (ans + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftTrue * rightTrue) % mod) % mod;
                else
                    ans = (ans + (leftFalse * rightFalse) % mod) % mod;
            }
            else
            { // XOR operator
                if (isTrue)
                    ans = (ans + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod) % mod;
                else
                    ans = (ans + (leftFalse * rightFalse) % mod + (leftTrue * rightTrue) % mod) % mod;
            }
        }
        return ans;
    }
};

int main(void)
{
    Solution obj;
    string s = "T|T&F^T"; // Sample boolean expression

    cout << obj.countWays(s) << endl; // Output the number of ways to evaluate to true
    return 0;
}
