#include <bits/stdc++.h>
using namespace std;
int sum(int arr[], int n, int ind, int k, int dp[][100])
{
    if (k == 0)
        return 1;
    if (ind == n)
        return 0;
    if (dp[ind][k] != -1)
        return dp[ind][k];
    // take
    int take = sum(arr, n, ind + 1, k - arr[ind], dp);
    // not take
    int nottake = sum(arr, n, ind + 1, k, dp);
    return dp[ind][k] = take + nottake;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total = total + arr[i];
    }
    int dp[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }
    sum(arr, n, 0, total, dp);
    int dif = 0;
    int result = 0;
    for (int i = 0; i < total; i++)
    {
        if (dp[n - 1][i] != -1)
        {
            dif = abs(i - (total - i));
            if (dif == k)
            {
                result = dp[n - 1][i];
            }
        }
    }
    cout << result;
    return 0;
}