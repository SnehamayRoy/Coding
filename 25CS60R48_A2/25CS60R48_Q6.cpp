#include <bits/stdc++.h>
using namespace std;
int palin(char arr[], int start, int end, int dp[][100])
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (dp[start][end] != -1)
        return dp[start][end];
    if (arr[start] == arr[end])
    {
        return dp[start][end] = 2 + palin(arr, start + 1, end - 1, dp);
    }
    int not_start = palin(arr, start + 1, end, dp);
    int not_end = palin(arr, start, end - 1, dp);
    return dp[start][end] = max(not_start, not_end);
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int dp[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    cout << palin(arr, 0, n - 1, dp);

    return 0;
}