#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<int> adj[])
    {
        // initialize vis array with 0
        int vis[V] = {0};

        // iterate over visit array to detect list of provinces of graph
        // (graph can be present multiple time), without connecting each other
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // called dfs method, with node, parent, and adjacency list
                // starting parent will always be -1
                // if it's
                if (DFS_Algo(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }

private:
    // method to detect cycle of graph using DFS algorithm
    bool DFS_Algo(int node, int parent, vector<int> adj[], int vis[])
    {
        // first mark node as visited
        vis[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            // unvisited adjacent node
            if (!vis[adjacentNode])
            {
                if (DFS_Algo(adjacentNode, node, adj, vis))
                    return true;
            }
            // visited node but not a parent node
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    // print adjacency list of graph
    void show_adj_list(int V, vector<int> adj[])
    {
        for (int i = 0; i < V; i++)
        {
            cout << i + 1 << " => "
                 << " ";
            for (auto item : adj[i])
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution obj;
    // V = 7, E = 2
    vector<int> adj[7] = {{2, 3}, {1, 5}, {4, 1, 6}, {3}, {2, 7}, {3, 7}, {5, 6}};

    obj.show_adj_list(7, adj);
    bool ans = obj.isCycle(7, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}