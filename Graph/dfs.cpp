#include <bits/stdc++.h>
using namespace std;

// vector<int> dfs(vector<int> adj[], int n)
// {
//     vector<int> dfs;
//     vector<int> visited(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         if (!visited[i])
//         {
//             stack<int> s;
//             s.push(i);
//             visited[i] = 1;
//             while (!s.empty())
//             {
//                 int curr = s.top();
//                 s.pop();
//                 dfs.push_back(curr);
//                 for (int j = adj[curr].size() - 1; j >= 0; j--)
//                 {
//                     int neighbour = adj[curr][j];
//                     if (!visited[neighbour])
//                     {
//                         visited[neighbour] = 1;
//                         s.push(neighbour);
//                     }
//                 }
//             }
//         }
//     }
//     return dfs;
// }

void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &ls)
{

    visited[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, ls);
        }
    }
    return;
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
    // traversal = dfs(adj, n);
    vector<int> visited(n + 1, 0);
    vector<int> ls;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, ls);
        }
    }
    for (auto it : ls)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}