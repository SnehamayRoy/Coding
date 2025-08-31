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
    ~stack()
    {
        delete[] arr;
    }
    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1; // or throw an exception
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int size()
    {
        return top + 1;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();                                    // Output: 10 20 30
    cout << "Top element is: " << s.peek() << endl; // Output: 30
    s.pop();
    s.display();                                   // Output: 10 20
    cout << "Stack size is: " << s.size() << endl; // Output: 2
    return 0;
}
