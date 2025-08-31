#include <bits/stdc++.h>
using namespace std;

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
    int count[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        count[i] = 1;
    }

    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }

            else if (arr[i] > arr[prev] && 1 + dp[prev] == dp[i])
            {
                count[i] += count[prev];
            }
        }
        maxi = (maxi, dp[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            cnt += count[i];
        }
    }
    cout << cnt;
    return 0;
}