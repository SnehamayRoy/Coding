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
};
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
        cout << curr->data << " ";
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
int searchtree(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
Node *buildtree(int post[], int in[], int instart, int inend, int &postindex)
{
    if (instart > inend)
        return nullptr;
    int rootvalue = post[postindex];
    Node *root = new Node(rootvalue);
    postindex--;
    int index = searchtree(in, instart, inend, rootvalue);
    root->right = buildtree(post, in, index + 1, inend, postindex);
    root->left = buildtree(post, in, instart, index - 1, postindex);

    return root;
}
int main()
{
    int n;
    cin >> n;
    int post[n];
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    int postindex = n - 1;
    Node *root = buildtree(post, in, 0, n - 1, postindex);
    levelorder(root);
    cout << endl;
    return 0;
}