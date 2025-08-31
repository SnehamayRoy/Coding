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

public:
    stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int s)
    {
        Node *newnode = new Node(s);
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (isEmpty())
            return;
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    int peek()
    {
        return top->data;
    }
};
int main()
{
}