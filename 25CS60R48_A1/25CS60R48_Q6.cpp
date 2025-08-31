#include <iostream>
using namespace std;

// Merge Sort Implementation
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[1000], R[1000]; // adjust size if needed

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Function to compute max product of 5 numbers
long long maxProductOfFive(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);

    long long prod1 = 1; // top 5 largest
    for (int i = n - 5; i < n; i++)
        prod1 *= arr[i];

    long long prod2 = 1; // 2 smallest + 3 largest
    prod2 = 1LL * arr[0] * arr[1] * arr[n - 1] * arr[n - 2] * arr[n - 3];

    long long prod3 = 1; // 4 smallest + largest
    prod3 = 1LL * arr[0] * arr[1] * arr[2] * arr[3] * arr[n - 1];

    long long maxProd = max(prod1, max(prod2, prod3));
    return maxProd;
}

int main()
{
    int n;
    cin >> n;
    int arr[1000]; // adjust size if needed
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxProductOfFive(arr, n) << endl;
    return 0;
}
