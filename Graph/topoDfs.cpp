#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topo(vector<vector<int>> adj, int n)
{
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> answer = topo(adj, n);
    for (auto it : answer)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}