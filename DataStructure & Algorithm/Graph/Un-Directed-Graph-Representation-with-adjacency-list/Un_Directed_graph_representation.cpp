// Process to represent undirected graph in c++, with adjacency list
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This is an undirected graph, thats why we need to update both node1,node2
    void insertIntoGraph(vector<int> graph[], int node1, int node2)
    {
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    };

    void TraversalGraph(vector<int> graph[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "graph of edage " << i << endl;
            for (auto item : graph[i])
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    Solution obj;
    vector<int> graph[6];

    obj.insertIntoGraph(graph, 1, 2);
    obj.insertIntoGraph(graph, 1, 3);
    obj.insertIntoGraph(graph, 2, 3);
    obj.insertIntoGraph(graph, 3, 4);

    // traverse graph
    obj.TraversalGraph(graph, 6);

    return 0;
}