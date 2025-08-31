#include <iostream>
using namespace std;
int power(int n, int p)
{
    if (p == 0)
        return 1;
    int res = n;
    while (p > 1)
    {
        res = res * n;
        p--;
    }
    return res;
}
int evaluation(int arr[], int n, int value)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = result + arr[i] * power(value, i);
    }
    return result;
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
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         if (evaluation(arr2, f + 1, arr[j]) > evaluation(arr2, f + 1, arr[j + 1]))
    //             swap(arr[j], arr[j + 1]);
    //     }
    // }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (evaluation(arr2, f + 1, arr[j]) < evaluation(arr2, f + 1, arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
