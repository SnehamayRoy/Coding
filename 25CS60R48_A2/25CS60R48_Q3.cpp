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

void sumup(int arr[], int ind, int k, int sum[], int cur, int n)
{

    if (k == 0)
    {
        for (int i = 0; i < cur; i++)
        {
            cout << sum[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = ind; i < n; i++)
    {
        // Skip duplicate numbers at the same level
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > k)
            break; // Optimization: No need to proceed further if number is greater than remaining sum

        sum[cur] = arr[i];
        sumup(arr, i + 1, k - arr[i], sum, cur + 1, n); // i + 1 ensures we don't reuse same element
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    bsort(arr, n);
    sumup(arr, 0, k, sum, 0, n);
    return 0;
}