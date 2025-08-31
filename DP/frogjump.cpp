#include <bits/stdc++.h>
using namespace std;
int mini(int arr[], int dp[], int ind)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind == 0)
        return 0;
    if (ind == 1)
        return abs(arr[0] - arr[1]);
    return dp[ind] = min(abs(arr[ind] - arr[ind - 1]) + mini(arr, dp, ind - 1), abs(arr[ind] - arr[ind - 2]) + mini(arr, dp, ind - 2));
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
    int dp[n];
    memset(dp, -1, sizeof(dp));
    cout << mini(arr, dp, n - 1);

    return 0;
}