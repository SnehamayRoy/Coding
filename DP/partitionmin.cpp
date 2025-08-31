#include <bits/stdc++.h>
using namespace std;
bool subset(int arr[], int n, int ind, int sum, int dp[][100])
{
    if (sum == 0)
        return true;
    if (ind == n)
        return false;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    // take
    bool take = subset(arr, n, ind + 1, sum - arr[ind], dp);
    // not take
    bool not_take = subset(arr, n, ind + 1, sum, dp);
    return dp[ind][sum] = take || not_take;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i; i < n; i++)
    {
        cin >> arr[i];
    }

    return 0;
}