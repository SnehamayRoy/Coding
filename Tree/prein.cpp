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
    int front, rear;

public:
    Queue()
    {
        front = rear = 0;
    }
    void push(Node *n)
    {
        arr[rear++] = n;
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
int searchin(int in[], int instart, int inend, int value)
{
    for (int i = instart; i <= inend; i++)
    {
        if (in[i] == value)
            return i;
    }
    return -1;
}
Node *buildtree(int pre[], int in[], int instart, int inend, int &preind)
{
    if (instart > inend)
        return nullptr;
    int rootval = pre[preind++];
    Node *root = new Node(rootval);
    if (instart == inend)
        return root;
    int inindex = searchin(in, instart, inend, rootval);
    root->left = buildtree(pre, in, instart, inindex - 1, preind);
    root->right = buildtree(pre, in, inindex + 1, inend, preind);
    return root;
}
void levelorder(Node *node)
{
    if (node == nullptr)
        return;
    Queue q;
    q.push(node);
    while (!q.empty())
    {
        Node *curr = q.getfront();
        q.pop();
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
        cout << curr->data << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int pre[n];
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    int prein = 0;
    Node *root = buildtree(pre, in, 0, n - 1, prein);
    levelorder(root);

    return 0;
}