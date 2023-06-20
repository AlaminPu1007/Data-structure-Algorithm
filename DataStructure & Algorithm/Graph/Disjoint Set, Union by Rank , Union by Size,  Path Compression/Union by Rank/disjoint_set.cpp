#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> parents, rank;

public:
    Solution(int n)
    {
        parents.resize(n + 1);
        // initialize parent's
        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }

        // initialize ranks
        rank.resize(n + 1, 0);
    }

    // this method help us to find ultimate(root parent) of given node
    int findParent(int node)
    {
        if (node == parents[node])
            return node;

        else
            parents[node] = findParent(parents[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

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

int main(void)
{
    Solution obj(7);

    obj.unionByRank(1, 2);
    obj.unionByRank(2, 3);
    obj.unionByRank(4, 5);
    obj.unionByRank(6, 7);
    obj.unionByRank(5, 6);

    // if 3 and 7 same or not
    if (obj.findParent(3) == obj.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    obj.unionByRank(3, 7);

    // if 3 and 7 same or not
    if (obj.findParent(3) == obj.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    return 0;
}