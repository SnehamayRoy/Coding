#include <iostream>
using namespace std;
class Queue
{
private:
    int *arr;
    int size;
    int start;
    int end;
    int capacity;

public:
    Queue(int cap)
    {
        arr = new int[cap];
        capacity = cap;
        start = 0;
        end = -1;
        size = 0;
    }
    void enqueue(int value)
    {
        if (size == capacity)
            cout << "Queue is full" << endl;
        else
        {
            end = (end + 1) % capacity;
            arr[end] = value;
            size++;
        }
    }
    void dequeue()
    {
        if (size == 0)
            cout << "Queue is empty" << endl;
        else
        {
            start = (start + 1) % capacity;
            size--;
        }
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }
    int rear()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[end];
    }
};
int main()
{
    Queue q(5);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.dequeue();
    cout << q.front() << endl;
    return 0;
}