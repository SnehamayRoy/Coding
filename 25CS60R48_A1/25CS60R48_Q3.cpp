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
void insertion(Node *&head, int value)
{
    Node *newnode = new Node(value);
    if (head == nullptr)
    {
        head = newnode;
        newnode->next = newnode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != head)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
    newnode->next = head;
}

int deletion(Node *&head, int k, int n)
{
    Node *start = head;
    Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < k; j++)
        {
            last = start;
            start = start->next;
        }
        last->next = start->next;
        delete start;
        start = last->next;
    }
    return start->data;
}
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    Node *head = nullptr;
    for (int i = 1; i <= n; i++)
    {
        insertion(head, i);
    }
    cout << deletion(head, k, n) << endl;
    return 0;
}