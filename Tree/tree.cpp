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
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }
    void push(Node *data)
    {
        arr[rear] = data;
        rear++;
    }
    void pop()
    {
        if (front < rear)
            front++;
    }
    bool isempty()
    {
        return front == rear;
    }
    Node *getfront()
    {
        return arr[front];
    }
};

Node *buildtreelevelorder()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    Node *root = new Node(x);
    Queue q;
    q.push(root);
    while (!q.isempty())
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

void preorder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);

    cout << node->data << " ";
    inorder(node->right);
}
void postorder(Node *node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);

    cout << node->data << " ";
}
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    int l = 1 + height(node->left);
    int r = 1 + height(node->right);
    return max(l, r);
}

int diameter(Node *node, int &maxi)
{
    if (node == nullptr)
        return 0;
    int l = diameter(node->left, maxi);
    int r = diameter(node->right, maxi);
    maxi = max(maxi, l + r);
    return 1 + max(l, r);
}

int main()
{
    Node *root = buildtreelevelorder();
    // cout << "Preorder traversal : ";
    // preorder(root);
    // cout << endl;
    // cout << "Inorder traversal : ";
    // inorder(root);
    // cout << endl;
    // cout << "Postorder traversal : ";
    // postorder(root);
    // cout << endl;
    // cout << height(root) << endl;
    int maxi = 0;
    diameter(root, maxi);
    cout << maxi << endl;

    return 0;
}