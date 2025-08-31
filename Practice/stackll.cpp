#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class stack
{
private:
    Node *top;
    int size = 0;

public:
    stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int data)
    {
        Node *newnode = new Node(data);
        newnode->next = top;
        top = newnode;
        size++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node *temp = top;
        int item = top->data;
        top = top->next;
        delete temp;
        size--;
        return item;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    int getsize()
    {
        return size;
    }
};

int main()
{
    stack s;
    s.push(7);
    s.push(9);
    s.pop();
    cout << s.peek() << endl;
    cout << s.getsize() << endl;

    return 0;
}