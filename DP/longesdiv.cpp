#include <bits/stdc++.h>
using namespace std;
void bsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
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
    bsort(arr, n);
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    int hash[n];
    int maxi = 1;
    int lastind = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if ((arr[i] % arr[prev] == 0) && (1 + dp[prev] > dp[i]))
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastind = i;
        }
    }
    int lvs[maxi];
    int i = 0;
    while (hash[lastind] != lastind)
    {
        lvs[i++] = arr[lastind];
        lastind = hash[lastind];
    }
    lvs[i] = arr[lastind];
    for (int j = i; j >= 0; j--)
    {
        cout << lvs[j] << " ";
    }
    return 0;
}