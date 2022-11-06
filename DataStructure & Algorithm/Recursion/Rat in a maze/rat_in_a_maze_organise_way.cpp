// https://takeuforward.org/data-structure/rat-in-a-maze/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Main mathod
    vector<string> findPath(vector<vector<int>> &m)
    {
        vector<string> ans;
        // define an visit array also n*n matrix
        vector<vector<int>> visited(m.size(), vector<int>(m.size(), 0));

        // Recursive method to find valid findPath
        int row = 0, col = 0;
        int row_postition[] = {+1, 0, 0, -1}, col_postition[] = {0, -1, +1, 0};

        if (m[0][0] == 1)
            findValidPath(row, col, m, visited, "", ans, m.size(), row_postition, col_postition);

        return ans;
    };

    void findValidPath(int row, int col, vector<vector<int>> &original_array, vector<vector<int>> &visited, string move, vector<string> &ans, int n, int row_postition[], int col_postition[])
    {
        if (row == (n - 1) && col == (n - 1))
        {
            ans.push_back(move);
            return;
        }

        string dir = "DLRU";

        for (int i = 0; i < n; i++)
        {
            int nextMoveRow = row + row_postition[i];
            int nextMoveCol = col + col_postition[i];

            if (nextMoveCol >= 0 && nextMoveRow >= 0 && nextMoveCol < n && nextMoveRow < n && !visited[nextMoveRow][nextMoveCol] && original_array[nextMoveRow][nextMoveCol] == 1)
            {
                visited[nextMoveRow][nextMoveCol] = 1;

                findValidPath(nextMoveRow, nextMoveCol, original_array, visited, move + dir[i % dir.size()], ans, n, row_postition, col_postition);

                visited[nextMoveRow][nextMoveCol] = 0;
            }
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