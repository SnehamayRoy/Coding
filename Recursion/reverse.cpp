#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void rev(int arr[], int f, int l)
{
    if (f >= l)
        return;
    swap(arr[f], arr[l]);
    rev(arr, f + 1, l - 1);
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
    rev(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}