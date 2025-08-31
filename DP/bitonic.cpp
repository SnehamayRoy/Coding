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
    int dp1[n];
    int dp2[n];
    for (int i = 0; i < n; i++)
    {
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
                dp1[i] = max(1 + dp1[prev], dp1[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[i] > arr[prev])
                dp2[i] = max(1 + dp2[prev], dp2[i]);
        }
    }
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    cout << maxi;

    return 0;
}