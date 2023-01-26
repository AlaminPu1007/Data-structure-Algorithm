#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // initialize visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // count no of islands, (count of starting node)
        int count = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    // called bfs method
                    BFS(row, col, vis, grid);

                    count++;
                }
            }
        }

        return count;
    }

private:
    void BFS(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // make everything as visited
        vis[row][col] = 1;

        queue<pair<int, int>> Q;

        Q.push({row, col});

        while (!Q.empty())
        {
            int row_value = Q.front().first;
            int col_value = Q.front().second;

            // now pop queue
            Q.pop();

            // visit matrix, at 8 direction
            for (int del_row = -1; del_row <= 1; del_row++)
            {
                for (int del_col = -1; del_col <= 1; del_col++)
                {
                    int new_row = row_value + del_row;
                    int new_col = col_value + del_col;

                    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1' && !vis[new_row][new_col])
                    {
                        // make as visited
                        vis[new_row][new_col] = 1;

                        // push into queue
                        Q.push({new_row, new_col});
                    }
                }
            }
        }
    }
};

int main(void)
{
    Solution obj;

    vector<vector<char>> grid = {
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'},
    };

    int res = obj.numIslands(grid);
    cout << res << endl;
    return 0;
}