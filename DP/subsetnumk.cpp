#include <bits/stdc++.h>
using namespace std;
int subsetk(int arr[], int n, int k, int ind, int dp[][100])
{
    if (ind == n)
        return (k == 0) ? 1 : 0;

    if (dp[ind][k] != -1)
        return dp[ind][k];
    // take
    int take = subsetk(arr, n, k - arr[ind], ind + 1, dp);
    int notake = subsetk(arr, n, k, ind + 1, dp);
    return dp[ind][k] = take + notake;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << subsetk(arr, n, k, 0, dp);
    return 0;
}