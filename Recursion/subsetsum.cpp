#include <bits/stdc++.h>
using namespace std;
bool found = false;
void subsum(int arr[], int n, int sum, int ind, int cur, int sub[])
{
    if (ind == n)
    {
        if (sum == 0)
        {
            found = true;
            for (int i = 0; i < cur; ++i)
            {
                cout << sub[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    sub[cur] = arr[ind];
    subsum(arr, n, sum - arr[ind], ind + 1, cur + 1, sub);
    subsum(arr, n, sum, ind + 1, cur, sub);
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int arr[n];
    int sub[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    subsum(arr, n, k, 0, 0, sub);
    if (!found)
        cout << -1;

    return 0;
}