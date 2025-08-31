#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int ind, int prev, int n, int dp[][100])
{
    if (ind == n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int take = 0;
    int not_take = 0;
    not_take = lis(arr, ind + 1, prev, n, dp);
    if (prev == -1 || arr[ind] > arr[prev])
    {
        take = 1 + lis(arr, ind + 1, ind, n, dp);
    }
    return dp[ind][prev + 1] = max(take, not_take);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int dp[100][100];
    // for (int i = 0; i < 100; i++)
    //     for (int j = 0; j < 100; j++)
    //     {
    //         dp[i][j] = -1;
    //     }
    // cout << lis(arr, 0, -1, n, dp);
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
                dp[i] = max(1 + dp[prev], dp[i]);
        }
        maxi = (maxi, dp[i]);
    }
    cout << maxi;
    return 0;
}