#include <bits/stdc++.h>
using namespace std;
class heap
{
    int arr[500];
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
            if (arr[parent] > arr[index])
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
            int mini = index;
            if (left <= size && arr[left] < arr[mini])
                mini = left;
            if (right <= size && arr[right] < arr[mini])
                mini = right;
            if (mini != index)
            {
                swap(arr[mini], arr[index]);
                index = mini;
            }
            else
            {
                break;
            }
        }
    }
    int top()
    {
        return arr[1];
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
    heap hp;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        hp.push(ele);
    }
    while (hp.getsize() > 1)
    {
        int first = hp.top();
        hp.pop();
        int second = hp.top();
        hp.pop();
        int sum = first + second;
        total += sum;
        hp.push(sum);
    }
    cout << total << endl;

    return 0;
}