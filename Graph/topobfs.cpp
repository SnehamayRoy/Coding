#include <bits/stdc++.h>
using namespace std;

vector<int> topo(vector<vector<int>> &adj, vector<int> &indegree)
{
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        topo.push_back(curr);
        q.pop();
        for (auto it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int> result = topo(adj, indegree);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}