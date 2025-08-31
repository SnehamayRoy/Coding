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