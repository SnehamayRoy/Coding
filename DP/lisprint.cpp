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
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    int maxi = 1;
    int hash[n];
    int lastindex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastindex = i;
        }
    }
    int lis[maxi];
    int i = 0;
    while (hash[lastindex] != lastindex)
    {
        lis[i++] = arr[lastindex];
        lastindex = hash[lastindex];
    }
    lis[i] = arr[lastindex];

    for (int j = i; j >= 0; --j)
    {
        cout << lis[j] << " ";
    }

    return 0;
}