#include <bits/stdc++.h>
using namespace std;
int getlen(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}
void copy(char src[], char des[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}
void ssort(char arr[][20], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (getlen(arr[j]) > getlen(arr[j + 1]))
            {
                char tmp[20];
                copy(arr[j], tmp);
                copy(arr[j + 1], arr[j]);
                copy(tmp, arr[j + 1]);
            }
        }
    }
}
bool checkpossible(char str1[], char str2[])
{
    int s1 = getlen(str1);
    int s2 = getlen(str2);
    if (s1 != 1 + s2)
        return false;
    int first = 0;
    int second = 0;
    while (first < s1 && second < s2)
    {
        if (str1[first] == str2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }
    if (first == s1 && second == s2)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    char arr[n][20];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ssort(arr, n);

    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkpossible(arr[i], arr[prev]))
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    cout << maxi;

    return 0;
}