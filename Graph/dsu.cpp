#include <bits/stdc++.h>
using namespace std;
class dsu
{
public:
    vector<int> size, parent;
    dsu(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    void unionBySize(int a, int b)
    {
        int nodeA = find(a);
        int nodeB = find(b);
        if (nodeA == nodeB)
            return;
        if (size[nodeA] > size[nodeB])
        {
            parent[nodeB] = nodeA;
            size[nodeA] += size[nodeB];
        }
        else
        {
            parent[nodeA] = nodeB;
            size[nodeB] += size[nodeA];
        }
    }
};

int main()
{
    int n;
    cin >> n;
    dsu d(n);
    d.unionBySize(0, 1);
    d.unionBySize(2, 3);
    d.unionBySize(3, 4);
    cout << d.find(0) << " " << d.find(4);

    return 0;
}