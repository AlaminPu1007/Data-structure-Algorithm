#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> parents, size;

public:
    Solution(int n)
    {
        parents.resize(n + 1);
        size.resize(n + 1);

        // initialize parent's
        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
            size[i] = 1;
        }
    }

    // this method help us to find ultimate(root parent) of given node
    int findParent(int node)
    {
        if (node == parents[node])
            return node;

        else
            return parents[node] = findParent(parents[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parents[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parents[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(void)
{
    Solution obj(7);

    obj.unionBySize(1, 2);
    obj.unionBySize(2, 3);
    obj.unionBySize(4, 5);
    obj.unionBySize(6, 7);
    obj.unionBySize(5, 6);

    // if 3 and 7 same or not
    if (obj.findParent(3) == obj.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    obj.unionBySize(3, 7);

    // if 3 and 7 same or not
    if (obj.findParent(3) == obj.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    return 0;
}