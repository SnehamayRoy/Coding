#include <bits/stdc++.h>
using namespace std;

int connected(vector<int> adj[], int n)
{
    vector<int> bfs;
    vector<int> visited(n + 1, 0);
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                bfs.push_back(cur);
                for (auto it : adj[cur])
                {
                    if (visited[it] != 1)
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }

    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vector<int> traversal;
    // traversal = bfs(adj, n);
    // for (auto it : traversal)
    // {
    //     cout << it << " ";
    // }
    cout << connected(adj, n) << endl;

    return 0;
}