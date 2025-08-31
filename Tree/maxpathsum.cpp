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
        left = nullptr;
        right = nullptr;
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
    int size()
    {
        return rear - front;
    }
    Node *getfront()
    {
        return arr[front];
    }
};

Node *builldtreelevelorder()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    Node *root = new Node(x);
    Queue q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.getfront();
        q.pop();
        int l, r;
        cin >> l;
        if (l != -1)
        {
            curr->left = new Node(l);
            q.push(curr->left);
        }
        cin >> r;
        if (r != -1)
        {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}
int maxpathsum(Node *node, int &maxi)
{
    if (node == nullptr)
    {
        return 0;
    }
    int l = maxpathsum(node->left, maxi);
    int r = maxpathsum(node->right, maxi);
    maxi = max(maxi, l + r + node->data);

    return node->data + max(l, r);
}

int main()
{
    Node *root = builldtreelevelorder();
    int maxi = INT_MIN;
    maxpathsum(root, maxi);
    cout << maxi << endl;

    return 0;
}