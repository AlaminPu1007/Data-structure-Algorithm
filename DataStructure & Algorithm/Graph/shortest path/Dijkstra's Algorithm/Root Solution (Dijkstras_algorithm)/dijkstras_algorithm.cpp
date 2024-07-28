/*
  Find out the shortest path using Dijkstra's algorithm.
  Time-Complexity: ` O( E * log(V) )`
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  typedef pair<int, int> iPair;

public:
  vector<int> shortestPath(vector<vector<int>> &edges, int source, int n)
  {
    // create a adjacency list using edges
    vector<iPair> adj[n + 1];

    // create a undirected graph or bi-direction graph adjacency list
    for (auto item : edges)
    {
      int u = item[0];
      int v = item[1];
      int w = item[2];

      // create undirected graph
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    // Create a priority queue for storing the nodes as a pair {dist, node}
    // where dist is the distance from source to the node.
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Initialising dis list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> dist(n + 1, INT_MAX);

    // put source node into queue,
    // From source node to source node weight or reached amount is 0.
    // pair {dist, node}
    pq.push({0, 0});

    // also update dis,
    dist[source] = 0;

    // now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
      int dis = pq.top().first;
      int node = pq.top().second;

      // ensure it will pop from queue
      pq.pop();

      // Check for all adjacent nodes of the popped out
      // element whether the prev dist is larger than current or not.
      for (auto adjNode : adj[node])
      {
        int v = adjNode.first;
        int w = adjNode.second;

        // If current distance is smaller,
        // push it into the queue.
        int curDistance = (dis + w);
        if (curDistance < dist[v])
        {
          dist[v] = curDistance;
          pq.push({curDistance, v});
        }
      }
    }

    return dist;
  }
};

int main(void)
{
  Solution obj;
  vector<vector<int>> edges = {
      {0, 1, 4},
      {0, 2, 4},
      {2, 1, 2},
      {2, 3, 3},
      {2, 5, 6},
      {2, 4, 1},
      {3, 5, 2},
      {4, 5, 3}};
  int source = 0, n = 5;
  vector<int> res = obj.shortestPath(edges, source, n);

  for (int i = 0; i <= n; i++)
  {
    cout << "(Node) " << i << " is " << res[i];

    if (i != n)
      cout << " -> ";
  }

  return 0;
}