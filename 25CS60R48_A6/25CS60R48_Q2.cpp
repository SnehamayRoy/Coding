#include <bits/stdc++.h>
using namespace std;

int checkcycle(vector<vector<int>> &adj, vector<int> &indegree)
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
        q.pop();
        topo.push_back(curr);
        for (auto it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo.size();
}

int main()
{
    int m;
    cin >> m;
    cin.ignore();
    vector<vector<int>> adj(m);
    vector<int> indegree(m, 0);
    for (int i = 0; i < m; i++)
    {
        string line;
        getline(cin, line);
        if (line.empty())
            continue;
        stringstream ss(line);
        int v;
        while (ss >> v)
        {
            adj[i].push_back(v);
            indegree[v]++;
        }
    }
    int size = checkcycle(adj, indegree);
    if (size < m)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}