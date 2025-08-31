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

public:
    Queue()
    {
        start = end = nullptr;
    }
    bool isEmpty()
    {
        return start == nullptr;
    }
    void enqueue(int data)
    {
        Node *newnode = new Node(data);
        if (start == nullptr)
        {
            start = end = newnode;
        }
        else
        {
            end->next = newnode;
            end = newnode;
        }
    }
    void dequeue()
    {
        if (start == nullptr)
            return;
        Node *tmp = start;
        start = start->next;
        delete tmp;
    };
    int peek()
    {
        if (start != nullptr)
            return start->data;
        else
            return -1;
    }
};
void insertnode(Node *&head, int n)
{
    Node *newnode = new Node(n);
    if (head == nullptr)
    {
        head = newnode;
        newnode->next = newnode;
        return;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next != head)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
        newnode->next = head;
    }
}
int maxi(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void maxnext(Node *&head, int k, Queue &q)
{
    int max = -1000;
    Node *start = head;
    for (int i = 0; i < k; i++)
    {
        start = start->next;
        max = maxi(max, start->data);
    }
    q.enqueue(max);
}
void printlist(Node *&head, int n)
{
    Node *start = head;
    for (int i = 0; i < n; i++)
    {
        cout << start->data << " ";
        start = start->next;
    }
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    Node *head = nullptr;
    Queue q;
    int value;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertnode(head, value);
    }
    Node *start = head;
    for (int i = 0; i < n; i++)
    {
        maxnext(start, k, q);
        start = start->next;
    }
    Node *update = head;
    for (int i = 0; i < n; i++)
    {
        if (!q.isEmpty())
        {
            update->data = q.peek();
            q.dequeue();
        }

        update = update->next;
    }
    printlist(head, n);

    return 0;
}
