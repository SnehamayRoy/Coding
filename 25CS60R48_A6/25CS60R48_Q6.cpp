#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int src, int m)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(m, INT_MAX);
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int cur_dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            if (dis[it.first] > cur_dis + it.second)
            {
                dis[it.first] = cur_dis + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }

    return dis;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int, int>>> adj(m);
    for (int i = 0; i < n; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    int src;
    cin >> src;
    vector<int> res(m);
    res = dijkstra(adj, src, m);
    for (auto it : res)
    {
        if (it != INT_MAX)
        {
            cout << it << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << endl;

    return 0;
}