#include <bits/stdc++.h>
using namespace std;
int lcs(char s1[], char s2[], int m, int n, int dp[][100])
{
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m] == s2[n])
    {
        dp[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, dp);
    }
    else
    {
        dp[m][n] = max(lcs(s1, s2, m, n - 1, dp), lcs(s1, s2, m - 1, n, dp));
    }
    return dp[m][n];
}

int main()
{
    int m;
    cin >> m;
    char s1[m];
    for (int i = 0; i < m; i++)
    {
        cin >> s1[i];
    }
    int n;
    cin >> n;
    char s2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s2[i];
    }
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    cout << lcs(s1, s2, m - 1, n - 1, dp);
    return 0;
}