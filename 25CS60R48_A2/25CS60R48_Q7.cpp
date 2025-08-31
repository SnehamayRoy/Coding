#include <bits/stdc++.h>
using namespace std;

int bitonic(int arr[], int n, int ind, bool dec, int prev)
{
    if (ind == n)
        return 0;

    int take = 0, not_take = 0;

    // Take if valid
    if (!dec) // Increasing phase
    {
        if (arr[ind] > prev)
            take = 1 + bitonic(arr, n, ind + 1, false, arr[ind]); // continue increasing

        // allow turning point to decreasing
        if (arr[ind] < prev)
            take = max(take, 1 + bitonic(arr, n, ind + 1, true, arr[ind])); // switch to decreasing
    }
    else // Already in decreasing phase
    {
        if (arr[ind] < prev)
            take = 1 + bitonic(arr, n, ind + 1, true, arr[ind]); // continue decreasing
    }

    // Not take
    not_take = bitonic(arr, n, ind + 1, dec, prev);

    return max(take, not_take);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << bitonic(arr, n, 0, false, INT_MIN) << endl;

    return 0;
}
