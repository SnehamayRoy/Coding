#include <bits/stdc++.h>
using namespace std;
#define M 1000000000
int coin(int arr[], int ind, int sum, int dp[][100])
{
    if (ind == 0)
    {
        if (sum % arr[ind] == 0)
            return sum / arr[ind];
        else
            return M;
    }
    // not take
    int nottake = 0;
    nottake = coin(arr, ind - 1, sum, dp);
    int take = M;
    if (arr[ind] <= sum)
    {
        take = 1 + coin(arr, ind, sum - arr[ind], dp);
    }
    return min(take, nottake);
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
    int res = coin(arr, n - 1, k, dp);
    if (res >= M)
        cout << -1;
    else
        cout << res;

    return 0;
}