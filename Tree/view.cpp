#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
class Queue
{
    Node *arr[500];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }
    void push(Node *data)
    {
        arr[rear++] = data;
    }
    void pop()
    {
        front++;
    }
    bool empty()
    {
        return front == rear;
    }
    Node *getfront()
    {
        return arr[front];
    }
};
Node *bulidleveloreder()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 0 || arr[0] == -1)
        return NULL;
    Queue q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        Node *curr = q.getfront();
        q.pop();

        if (i < n && arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main()
{
    Node *root = bulidleveloreder();

    return 0;
}