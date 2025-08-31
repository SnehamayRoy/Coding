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
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] > size[b])
        {
            parent[b] = a;
            size[a] += size[b];
        }
        else
        {
            parent[a] = b;
            size[b] += size[a];
        }
    }
};
int main()
{
    int V, E;
    cin >> V >> E;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int mst = 0;
    // vector<pair<int, int>> msts;
    dsu d(V + 1);

    for (int i = 0; i < E; i++)
    {
        int w = get<0>(edges[i]);
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);
        if (d.find(u) != d.find(v))
        {
            mst += w;
            d.unionBySize(u, v);
        }
    }
    cout << mst << endl;
    return 0;
}