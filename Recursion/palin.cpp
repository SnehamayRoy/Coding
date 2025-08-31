#include <bits/stdc++.h>
using namespace std;
bool palin(char arr[], int s, int e)
{
    if (s >= e)
        return true;
    if (arr[s] != arr[e])
        return false;
    return palin(arr, s + 1, e - 1);
}

int main()
{
    int n;
    cin >> n;
    char *arr = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (palin(arr, 0, n - 1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}