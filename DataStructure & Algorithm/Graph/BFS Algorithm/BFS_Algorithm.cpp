#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> BFSSearch(int totalNode, vector<int> adj[])
    {
        vector<int> res;
        queue<int> Q;

        int visited[totalNode] = {0};

        // make starting node as visited
        visited[1] = 1;

        // starting node
        Q.push(1);

        // Till queue empty
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();

            // store visited path inside vector
            res.push_back(node);

            // now push the adjacency list of node in queue
            for (auto item : adj[1])
            {
                if (!visited[item])
                {
                    // make item as a visited
                    visited[item] = 1;
                    Q.push(item);
                }
            }
        }

        return res;
    }

    // method to insert adjacency list in array of graph
    void AddEdges(vector<int> adj[], int node1, int node2)
    {
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    // Method to print adjacency list of node
    void PrintGraph(vector<int> adj[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "for " << i << " => ";
            for (auto item : adj[i])
                cout << item << " ";

            cout << endl;
        }
    }
};

int main(void)
{
    Solution obj;
    int N = 11;

    vector<int> adj[N];

    // insert node into graph
    obj.AddEdges(adj, 1, 2);
    obj.AddEdges(adj, 1, 7);
    obj.AddEdges(adj, 2, 3);
    obj.AddEdges(adj, 2, 6);
    obj.AddEdges(adj, 7, 8);
    obj.AddEdges(adj, 7, 10);
    obj.AddEdges(adj, 3, 4);
    obj.AddEdges(adj, 3, 5);
    obj.AddEdges(adj, 8, 9);

    // print graph adjacency list
    obj.PrintGraph(adj, N);

    cout << endl;

    vector<int> res = obj.BFSSearch(N, adj);

    cout << "Visited Path of Graph : " << endl;

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}