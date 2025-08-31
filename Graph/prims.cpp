#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);
    pq.push({0, 0});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visited[node] == 1)
            continue;
        ;
        visited[node] = 1;
        sum += weight;
        for (auto it : adj[node])
        {
            int u = it.first;
            int w = it.second;
            if (!visited[u])
            {
                pq.push({w, u});
            }
        }
    }
    cout << sum << endl;
    return 0;
}