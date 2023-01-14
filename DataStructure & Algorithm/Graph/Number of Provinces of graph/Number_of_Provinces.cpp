#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // to change adjacency matrix to list
        vector<int> adjList[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        // define an visited array
        int vis[V] = {0};
        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // count no of provinces
                count++;
                // called DFS
                DFS_SEARCH(vis, adjList, i);
            }
        }
        return count;
    }

private:
    // call recursive method of DFS_SEARCH
    void DFS_SEARCH(int vis[], vector<int> adjList[], int node)
    {
        // mark the more as visited
        vis[node] = 1;
        for (auto item : adjList[node])
        {
            if (!vis[item])
                DFS_SEARCH(vis, adjList, item);
        }
    }
};

int main(void)
{
    Solution obj;
    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    int res = obj.numProvinces(adj, 3);
    cout << res << endl;
    return 0;
}