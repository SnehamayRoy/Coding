#include <bits/stdc++.h>
using namespace std;
int maxw(int w[], int v[], int n, int k, int ind, int dp[][100])
{
    if (ind == n)
        return 0;
    // take
    int take = 0;
    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    if (w[ind] <= k)
    {
        take = v[ind] + maxw(w, v, n, k - w[ind], ind + 1, dp);
    }
    // not take
    int nottake = 0;
    nottake = maxw(w, v, n, k, ind + 1, dp);
    return dp[ind][k] = max(take, nottake);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int w[n];
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int dp[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << maxw(w, v, n, k, 0, dp);

    return 0;
}