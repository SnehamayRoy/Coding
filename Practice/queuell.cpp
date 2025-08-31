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
class Queue
{
private:
    Node *start, *end;
    int size;

public:
    Queue()
    {
        start = end = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return start == nullptr;
    }
    void enqueue(int data)
    {
        Node *newnode = new Node(data);
        if (isEmpty())
        {
            start = end = newnode;
        }
        else
        {
            end->next = newnode;
            end = newnode;
        }
        size++;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node *tmp = start;
        int item = tmp->data;
        start = start->next;
        delete tmp;
        size--;
        return item;
    }
};

int main()
{
    return 0;
}
