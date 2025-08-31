#include <bits/stdc++.h>
using namespace std;
int frogk(int arr[], int ind, int n, int dp[], int k)
{
    if (dp[ind] != -1)
        return dp[ind];
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i > n; i++)
    {
        cin >> arr[i];
    }
    int dp[n];
    memset(dp, -1, sizeof(dp));
    int k;
    cin >> k;

    return 0;
}