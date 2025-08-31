#include <bits/stdc++.h>
using namespace std;

int connected(vector<int> adj[], int n)
{
    vector<int> visited(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++)
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
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << connected(adj, n) << endl;

    return 0;
}