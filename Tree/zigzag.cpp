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
        right = left = nullptr;
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
        front = rear = 0;
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
    int size()
    {
        return rear - front;
    }
    Node *getfront()
    {
        return arr[front];
    }
};

Node *bulidtreelevelorder()
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
    Node *root = new Node(arr[0]);
    Queue q;
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

void zigzag(Node *node)
{
    Queue q;
    q.push(node);
    bool lefttoright = true;
    while (!q.empty())
    {
        int levelsize = q.size();
        int nodes[levelsize];
        for (int i = 0; i < levelsize; i++)
        {
            Node *curr = q.getfront();
            q.pop();
            nodes[i] = curr->data;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (lefttoright)
        {
            for (int i = 0; i < levelsize; i++)
            {
                cout << nodes[i] << " ";
            }
        }
        else
        {
            for (int i = levelsize - 1; i >= 0; i--)
            {
                cout << nodes[i] << " ";
            }
        }
        lefttoright = !lefttoright;
    }
}
int main()
{
    Node *root = bulidtreelevelorder();
    zigzag(root);

    return 0;
}