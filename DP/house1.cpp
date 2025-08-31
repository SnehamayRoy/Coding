#include <bits/stdc++.h>
using namespace std;
int house(int arr[], int dp[], int ind)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind == 0)
        return arr[0];
    if (ind == 1)
        return max(arr[0], arr[1]);
    return dp[ind] = max(house(arr, dp, ind - 1), arr[ind] + house(arr, dp, ind - 2));
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
    // int dp[n];
    // memset(dp, -1, sizeof(dp));
    // cout << house(arr, dp, n - 1);
    // dp[0]=arr[0];
    // dp[1]=max(arr[0],arr[1]);
    int h1 = arr[0];
    int h2 = max(arr[0], arr[1]);
    int p;
    for (int i = 2; i < n; i++)
    {
        p = max(arr[i] + h1, h2);
        h1 = h2;
        h2 = p;
    }
    cout << p;

    return 0;
}