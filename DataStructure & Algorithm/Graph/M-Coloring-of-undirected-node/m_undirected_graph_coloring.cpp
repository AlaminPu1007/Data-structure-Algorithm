
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int N, int m)
    {
        int color[N] = {0};
        if (solve(0, graph, color, N, m) == true)
            return true;

        return false;
    };
    // Recursive method to fill color array with m color
    bool solve(int node, bool graph[101][101], int color[], int N, int m)
    {
        if (node == N)
            return true;

        // try with every single possible color
        for (int i = 1; i <= m; i++)
        {
            if (is_Safe_To_Color(node, graph, color, N, i))
            {
                cout << i << "is safe true" << endl;
                color[node] = i;
                if (solve(node + 1, graph, color, N, m))
                    return true;

                // if it's not true, then need to remove previous added color
                color[node] = 0;
            }
        }

        return false;
    };

    //  method to fill with color
    bool is_Safe_To_Color(int node, bool graph[101][101], int color[], int N, int col)
    {
        for (int i = 0; i < N; i++)
            cout << color[i] << " ";
        cout << endl;
        // traverse to N
        for (int k = 0; k < N; k++)
        {
            if (k != node && graph[k][node] == 1 && color[k] == col)
                return false;
        }
        return true;
    }
};

int main(void)
{
    Solution obj;

    bool graph[101][101];
    int N = 4, m = 2;
    // fill array with bool value
    memset(graph, false, sizeof graph);

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    // define undirected graph
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;

    bool result = obj.graphColoring(graph, N, m);
    // result - 1(true), 0(false)
    cout << "Final Result -> " << result << endl;

    return 0;
}