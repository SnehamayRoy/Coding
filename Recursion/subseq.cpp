#include <bits/stdc++.h>
using namespace std;
void subseq(char arr[], int n, int ind, char sub[], int curr)
{
    if (ind == n)
    {
        if (curr == 0)
            cout << "{}" << endl;
        else
        {
            sub[curr] = '\0';
            cout << sub << endl;
            return;
        }
    }
    sub[curr] = arr[ind];
    subseq(arr, n, ind + 1, sub, curr + 1);
    subseq(arr, n, ind + 1, sub, curr);
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    char sub[n + 1];
    subseq(arr, n, 0, sub, 0);

    return 0;
}