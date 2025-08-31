#include <bits/stdc++.h>
using namespace std;

class heap
{
    int arr[100];
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void push(int data)
    {
        size++;
        arr[size] = data;
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    int top()
    {
        if (size == 0)
            return -1;
        return arr[1];
    }
    void pop()
    {
        if (size == 0)
            return;
        arr[1] = arr[size];
        size--;
        int index = 1;
        while (index <= size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;
            if (left <= size && arr[left] > arr[largest])
            {
                largest = left;
            }
            if (right <= size && arr[right] > arr[largest])
            {
                largest = right;
            }
            if (largest != index)
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else
                break;
        }
    }
    int getsize()
    {
        return size;
    }
};

int main()
{
    int n;
    cin >> n;
    heap h;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        h.push(ele);
    }
    int arr[n];
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = h.top();
        h.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}