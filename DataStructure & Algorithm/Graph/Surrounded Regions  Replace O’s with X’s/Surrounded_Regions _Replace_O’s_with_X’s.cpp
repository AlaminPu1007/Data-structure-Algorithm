#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        // visit first row, and last row
        for (int i = 0; i < m; i++)
        {
            // for first row
            if (!vis[0][i] && mat[0][i] == 'O')
            {
                // made dfs method call
                DFS(n, m, 0, i, vis, mat, del_row, del_col);
            }

            // for last row
            if (!vis[n - 1][i] && mat[n - 1][i] == 'O')
            {
                // made dfs method call
                DFS(n, m, n - 1, i, vis, mat, del_row, del_col);
            }
        }

        // visit first col, last col
        for (int j = 0; j < n; j++)
        {
            // for first column
            if (!vis[j][0] && mat[j][0] == 'O')
            {
                // made dfs method call
                DFS(n, m, j, 0, vis, mat, del_row, del_col);
            }

            // for last column
            if (!vis[j][m - 1] && mat[j][m - 1] == 'O')
            {
                // made dfs method call
                DFS(n, m, j, m - 1, vis, mat, del_row, del_col);
            }
        }

        // fill left 'O' with 'X'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }

private:
    void DFS(int n, int m, int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int del_row[], int del_col[])
    {
        // make every visit array as visited
        vis[row][col] = 1;

        // vis matrix at top,right,bottom, left direction
        for (int i = 0; i < 4; i++)
        {
            // get new-row, new-col accordion to row, col
            int new_row = del_row[i] + row;
            int new_col = del_col[i] + col;

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && mat[new_row][new_col] == 'O')
            {
                // make dfs method call
                DFS(n, m, new_row, new_col, vis, mat, del_row, del_col);
            }
        }
    }
};

int main()
{

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}