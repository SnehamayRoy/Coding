#include <iostream>
using namespace std;
int power(int n, int p)
{
    int res = n;
    if (p == 0)
        return 1;
    while (p > 1)
    {
        res = res * n;
        p--;
    }
    return res;
}
int eval(int arr[], int size, int value)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res + arr[i] * power(value, i);
    }
    return res;
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
    int f;
    cin >> f;
    int arr2[f + 1];
    for (int i = 0; i < f + 1; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (eval(arr2, f + 1, arr[j]) > eval(arr2, f + 1, arr[min]))
                min = j;
        }
        swap(arr[min], arr[i]);
    }
    for (int i = n; i < 0; i++)
    {
        cout << arr[i];
    }

    return 0;
}