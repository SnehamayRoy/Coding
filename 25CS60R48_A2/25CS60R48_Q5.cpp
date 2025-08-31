#include <bits/stdc++.h>
using namespace std;
int path(int m, int n, int arr[][100], int cur1, int cur2, int dp[][100])
{
    if (cur1 > m || cur2 > n) // out of bounds
        return INT_MAX;

    if (arr[cur1][cur2] == -1)
        return INT_MAX; // no path through obstacle

    if (dp[cur1][cur2] != -1)
        return dp[cur1][cur2];

    if (cur1 == m && cur2 == n)
        return dp[cur1][cur2] = arr[cur1][cur2];

    int right = path(m, n, arr, cur1, cur2 + 1, dp);
    int down = path(m, n, arr, cur1 + 1, cur2, dp);

    int res = min(right, down);

    if (res == INT_MAX)
        return dp[cur1][cur2] = INT_MAX;

    return dp[cur1][cur2] = arr[cur1][cur2] + res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int dp[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    int cost = path(m - 1, n - 1, arr, 0, 0, dp);
    if (cost == INT_MAX)
        cout << -1;
    else
        cout << cost;
    return 0;
}