#include <iostream>
using namespace std;
class stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    void push(int n)
    {
        if (top + 1 == capacity)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
            arr[++top] = n;
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
            top--;
    }
    int peek()
    {
        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            return arr[top];
    }
    ~stack()
    {
        delete[] arr;
    }
};

int main()
{
    stack s(10);
    s.push(5);
    s.push(10);
    s.push(12);
    s.pop();
    s.pop();

    cout << s.peek() << endl;

    return 0;
}