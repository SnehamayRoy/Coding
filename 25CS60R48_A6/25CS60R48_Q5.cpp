#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>> &adj, int src, int m)
{
    vector<int> dis(m, -1);
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int curr_dis = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (dis[it] == -1)
            {
                dis[it] = curr_dis + 1;
                q.push({it, dis[it]});
            }
        }
    }
    return dis;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> adj(m);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin >> src;
    vector<int> res;
    res = shortestPath(adj, src, m);
    for (int i = 0; i < m; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}