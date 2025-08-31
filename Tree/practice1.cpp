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
struct Pairnode
{
    Node *node;
    int hd;
};
class Queue
{
    Node *arr[500];
    int front, rear;

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
        return rear == front;
    }
    Node *getfront()
    {
        return arr[front];
    }
    int getsize()
    {
        return rear - front;
    }
};
class Queueforview
{
    Pairnode arr[500];
    int front, rear;

public:
    Queueforview()
    {
        front = rear = 0;
    }
    void push(Node *node, int value)
    {
        arr[rear++] = {node, value};
    }
    void pop()
    {
        front++;
    }
    bool empty()
    {
        return rear == front;
    }
    Pairnode getfront()
    {
        return arr[front];
    }
};
// Node *buildtreelevelorder()
// {
//     int x;
//     cin >> x;
//     if (x == -1)
//         return nullptr;
//     Node *root = new Node(x);
//     Queue q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *curr = q.getfront();
//         q.pop();
//         int l, r;
//         cin >> l;
//         if (l != -1)
//         {
//             curr->left = new Node(l);
//             q.push(curr->left);
//         }
//         cin >> r;
//         if (r != -1)
//         {
//             curr->right = new Node(r);
//             q.push(curr->right);
//         }
//     }
//     return root;
// }

Node *buildtreelevelorder()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 0 || arr[0] == -1)
        return nullptr;
    Node *root = new Node(arr[0]);
    Queue q;
    q.push(root);
    int i = 1;
    while (i < n && !q.empty())
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
// void topview(Node *node)
// {
//     if (node == nullptr)
//         return;
//     Queueforview q;
//     int top[500];
//     bool seen[500] = {false};
//     int offset = 250;
//     q.push(node, 0);
//     while (!q.empty())
//     {
//         Pairnode curr = q.getfront();
//         q.pop();
//         int ind = curr.hd + offset;
//         if (!seen[ind])
//         {
//             seen[ind] = true;
//             top[ind] = curr.node->data;
//         }
//         if (curr.node->left)
//         {
//             q.push(curr.node->left, curr.hd - 1);
//         }
//         if (curr.node->right)
//         {
//             q.push(curr.node->right, curr.hd + 1);
//         }
//     }
//     for (int i = 0; i < 500; i++)
//     {
//         if (seen[i])
//         {
//             cout << top[i] << " ";
//         }
//     }
// }

void bottomview(Node *node)
{
    if (node == nullptr)
        return;
    Queueforview q;
    int bottom[500];
    for (int i = 0; i < 500; i++)
    {
        bottom[i] = -1;
    }
    int offset = 250;
    q.push(node, 0);
    while (!q.empty())
    {
        Pairnode curr = q.getfront();
        q.pop();
        int ind = curr.hd + offset;
        bottom[ind] = curr.node->data;
        if (curr.node->left)
        {
            q.push(curr.node->left, curr.hd - 1);
        }
        if (curr.node->right)
        {
            q.push(curr.node->right, curr.hd + 1);
        }
    }
    for (int i = 0; i < 500; i++)
    {
        if (bottom[i] != -1)
        {
            cout << bottom[i] << " ";
        }
    }
}

void leftview(Node *node)
{
    if (node == nullptr)
        return;
    Queue q;
    q.push(node);
    while (!q.empty())
    {
        int levelsize = q.getsize();
        for (int i = 0; i < levelsize; i++)
        {
            Node *curr = q.getfront();
            q.pop();
            if (i == 0)
            {
                cout << curr->data << " ";
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node *root = buildtreelevelorder();
    leftview(root);
    cout << endl;
    return 0;
}