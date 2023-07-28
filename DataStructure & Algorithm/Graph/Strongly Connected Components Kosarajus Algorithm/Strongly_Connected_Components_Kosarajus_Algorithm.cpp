/** NOT SUBMITTED YET, because submission has some error issue */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kosaraju(int n, vector<vector<int>> &edges)
    {
        int res = 0;
        vector<int> adj[n];

        vector<int> vis(n, 0);
        stack<int> st;

        // making adjacency list
        for (auto item : edges)
        {
            cout << item[0] << "->" << item[1] << endl;
            adj[item[0]].push_back(item[1]);
        }

        for (int i = 0; i < n; i++)
        {
            cout << "node ->" << i << " = ";
            for (auto item : adj[i])
            {
                cout << item << " ";
            }
            cout << endl;
        }

        // Make DFS called to get starting node
        // STEP-1 to get starting node, according to their finishing time
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                DFS(i, vis, adj, st);
            }
        }

        vector<int> adjReverse[n];

        // Reverse the edges of each node
        for (int i = 0; i < n; i++)
        {
            // mark vis array as initial state
            vis[i] = 0;
            for (auto item : adj[i])
            {
                adjReverse[item].push_back(i);
            }
        }

        while (!st.empty())
        {
            // get top most node from stack
            int node = st.top();
            // removed item from stack
            st.pop();

            if (!vis[node])
            {
                // count component
                res++;
                DfsForStrongComponent(node, vis, adjReverse);
            }
        }

        return res;
    }

private:
    void DFS(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        // mark node as visited
        vis[node] = 1;

        for (auto item : adj[node])
        {
            if (!vis[item])
                DFS(item, vis, adj, st);
        }
        st.push(node);
    }
    // this dfs method help us to detect strongly connected component
    void DfsForStrongComponent(int node, vector<int> &vis, vector<int> adjReverse[])
    {
        // mark as visited
        vis[node] = 1;

        // traverse graph according to node
        for (auto item : adjReverse[node])
        {
            if (!vis[item])
                DfsForStrongComponent(item, vis, adjReverse);
        }
    }
};

int main()
{

    int n = 5;
    vector<vector<int>> edges = {
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4},
    };

    Solution obj;
    int ans = obj.kosaraju(n, edges);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}