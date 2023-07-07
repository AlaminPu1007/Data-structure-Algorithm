#include <bits/stdc++.h>
using namespace std;

// create Disjoint data-structure
class Disjoint
{
public:
    vector<int> rank, parents;
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parents.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parents[i] = i;
    };

    int findUltimateParent(int node)
    {
        if (node == parents[node])
            return node;

        return parents[node] = findUltimateParent(parents[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parents[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parents[ulp_v] = ulp_u;
        }
        else
        {
            parents[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // initialize disjoint data-structure
        Disjoint obj(n * m);
        // define answer
        vector<int> ans;
        // define visited array to ensure visit a node only one time
        int vis[n][m];

        // initialize visited array with
        memset(vis, 0, sizeof vis);
        int count = 0;
        // traverse through queries
        for (auto item : operators)
        {
            int row = item[0];
            int col = item[1];

            if (vis[row][col])
            {
                ans.push_back(count);
                continue;
            }

            vis[row][col] = 1;
            count++;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            // traverse through 4 direction of matrix except diagonal
            for (int ind = 0; ind < 4; ind++)
            {
                int adjRow = row + delRow[ind];
                int adjCol = col + delCol[ind];

                if (isValid(adjRow, adjCol, n, m))
                {
                    if (vis[adjRow][adjCol])
                    {
                        int node = row * m + col;
                        int adjNode = adjRow * m + adjCol;

                        if (obj.findUltimateParent(node) != obj.findUltimateParent(adjNode))
                        {
                            count--;
                            obj.UnionByRank(node, adjNode);
                        }
                    }
                }
            }
            ans.push_back(count);
        }

        return ans;
    }

private:
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
};

int main()
{

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans)
    {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}