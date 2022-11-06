#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Main method
    vector<string> findPath(vector<vector<int>> &m)
    {
        vector<string> ans;
        // define an visit array also n*n matrix
        vector<vector<int>> visited(m.size(), vector<int>(m.size(), 0));

        // Recursive method to find valid findPath
        int row = 0, col = 0;

        if (m[0][0] == 1)
            findValidPath(row, col, m, visited, "", ans, m.size());

        return ans;
    };

    void findValidPath(int row, int col, vector<vector<int>> &original_array, vector<vector<int>> &visited, string move, vector<string> &ans, int n)
    {
        if (row == (n - 1) && col == (n - 1))
        {
            ans.push_back(move);
            return;
        }

        // move to down_ward
        if (row + 1 < n && !visited[row + 1][col] && original_array[row + 1][col] == 1)
        {
            // update visited array by 1
            visited[row][col] = 1;

            findValidPath(row + 1, col, original_array, visited, move + "D", ans, n);

            // make visited item as initial state after back_trak
            visited[row][col] = 0;
        }

        // move to Left
        if (col - 1 >= 0 && !visited[row][col - 1] && original_array[row][col - 1] == 1)
        {
            // update visited array by 1
            visited[row][col] = 1;

            findValidPath(row, col - 1, original_array, visited, move + "L", ans, n);

            // make visited item as initial state after back_trak
            visited[row][col] = 0;
        }

        // move to Right
        if (col + 1 < n && !visited[row][col + 1] && original_array[row][col + 1] == 1)
        {
            // update visited array by 1
            visited[row][col] = 1;

            findValidPath(row, col + 1, original_array, visited, move + "R", ans, n);

            // make visited item as initial state after back_trak
            visited[row][col] = 0;
        }

        // move to Up
        if (row - 1 >= 0 && !visited[row - 1][col] && original_array[row - 1][col] == 1)
        {
            // update visited array by 1
            visited[row][col] = 1;

            findValidPath(row - 1, col, original_array, visited, move + "U", ans, n);

            // make visited item as initial state after back_track
            visited[row][col] = 0;
        }
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = obj.findPath(m);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}