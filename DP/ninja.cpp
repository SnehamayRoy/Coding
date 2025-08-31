#include <bits/stdc++.h>
using namespace std;

int point(int arr[][3], int r, int f, int l, int ind)
{
    if (ind == 0)
    {
        if (!r)
            return max(arr[0][1], arr[0][2]);
        else if (!f)
            return max(arr[0][0], arr[0][2]);
        else if (!l)
            return max(arr[0][0], arr[0][1]);
        else
            return max(arr[0][0], max(arr[0][1], arr[0][2]));
    }
    int first = 0;
    int second = 0;
    int third = 0;

    if (r)
    {
        first = arr[ind][0] + point(arr, 0, 1, 1, ind - 1);
    }
    if (f)
    {
        second = arr[ind][1] + point(arr, 1, 0, 1, ind - 1);
    }
    if (l)
    {
        third = arr[ind][2] + point(arr, 1, 1, 0, ind - 1);
    }
    return max(first, max(second, third));
}

int main()
{
    int n;
    cin >> n;
    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << point(arr, 1, 1, 1, n - 1);

    return 0;
}