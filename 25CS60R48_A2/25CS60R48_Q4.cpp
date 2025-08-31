#include <bits/stdc++.h>
using namespace std;
int num(int arr[], int n, int k, int ind)
{
    if (ind == n)
    {
        if (k == 0)
            return 1;
        else
            return 0;
    }
    return num(arr, n, k - arr[ind], ind + 1) + num(arr, n, k, ind + 1);
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
    int k;
    cin >> k;
    cout << num(arr, n, k, 0);
    return 0;
}