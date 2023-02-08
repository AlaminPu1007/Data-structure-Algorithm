/**
 * Code to detect cycle of a graph, using DFS Graph traversal algorithm
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // called Bfs algorithm to detect cycle
                if (detectCycle(i, vis, adj) == true)
                    return true;
            }
        }

        return false;
    };

private:
    bool detectCycle(int n, int vis[], vector<int> adj[])
    {
        // mark first node as visited
        vis[n] = 1;
        // define an queue with pair, which hold to node with it's parent
        //  -1 means it has no parent, starting node
        queue<pair<int, int>> q;
        q.push({n, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            // removed it from queue
            q.pop();
            // get adjacency list of given node
            for (auto adjacentNode : adj[node])
            {

                if (!vis[adjacentNode])
                {
                    // mark as visited
                    vis[adjacentNode] = 1;
                    // push inside queue also
                    q.push({adjacentNode, node});
                }
                // if adjacent node is visited and is not it's own parent node
                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        // there's no cycle
        return false;
    };
};

int main(void)
{
    Solution obj;
    vector<int> adj[5] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    bool res = obj.isCycle(5, adj);
    cout << "Result is : " << res << endl;
    return 0;
}