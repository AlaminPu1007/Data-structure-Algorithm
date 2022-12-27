#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // this method help us to visit all node of a graph, using recursion approach
    void MakeDFSPath(int node, vector<int> adj[], vector<int> &ls, int vis[])
    {
        // mark node as visited
        vis[node] = 1;
        // push path
        ls.push_back(node);

        // traverse all its neighbours
        for (auto item : adj[node])
        {
            // if the neighbour is not visited
            if (!vis[item])
                MakeDFSPath(item, adj, ls, vis);
        }
    }

public:
    vector<int> DFS_Algorithm(int n, vector<int> adj[])
    {
        vector<int> ls;
        int vis[n] = {0};
        int startNode = 1;

        // make start node as visited
        vis[startNode] = 1;

        // call an recursive approach
        MakeDFSPath(startNode, adj, ls, vis);
        return ls;
    }
    // method to insert into graph
    void addEdge(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // method to print graph
    void ShowGraph(int n, vector<int> adj[])
    {
        for (int i = 0; i < n; i++)
        {
            cout << "neighbours of " << i << " => { ";
            for (auto item : adj[i])
            {
                cout << item << ", ";
            }
            cout << "}" << endl;
        }
    }
};

int main(void)
{
    Solution obj;
    // if start node is '0' then make (n-1)
    int n = 11;
    vector<int> adj[n];

    // insert into graph
    obj.addEdge(adj, 1, 2);
    obj.addEdge(adj, 1, 7);
    obj.addEdge(adj, 2, 3);
    obj.addEdge(adj, 2, 6);
    obj.addEdge(adj, 3, 4);
    obj.addEdge(adj, 3, 5);
    obj.addEdge(adj, 7, 8);
    obj.addEdge(adj, 7, 10);
    obj.addEdge(adj, 8, 9);

    // Print of graph
    obj.ShowGraph(n, adj);
    // visit node of a graph using DFS algorithm
    vector<int> path = obj.DFS_Algorithm(n, adj);

    cout << endl
         << "Visited path of graph : => ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    return 0;
}