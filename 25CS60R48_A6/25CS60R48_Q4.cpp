#include <bits/stdc++.h>
using namespace std;

bool check(int start, vector<vector<int>> &adj, vector<int> &colour)
{
    queue<int> q;
    q.push(start);
    colour[start] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto it : adj[curr])
        {
            if (colour[it] == -1)
            {
                colour[it] = !colour[curr];
                q.push(it);
            }
            else
            {
                if (colour[it] == colour[curr])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int m;
    cin >> m;
    vector<vector<int>> adj(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> colr(m, -1);
    bool res = true;
    for (int i = 0; i < m; i++)
    {
        if (colr[i] == -1)
        {
            if (!check(i, adj, colr))
            {
                res = false;
                break;
            }
        }
    }
    if (res == false)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    return 0;
}