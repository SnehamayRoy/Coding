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
    int front;
    int rear;

public:
    Queueforview()
    {
        front = rear = 0;
    }
    void push(Node *data, int value)
    {
        arr[rear].node = data;
        arr[rear].hd = value;
        rear++;
    }
    void pop()
    {
        front++;
    }
    bool empty()
    {
        return front == rear;
    }
    Pairnode getfront()
    {
        return arr[front];
    }
};
Node *insertbst(Node *root, int value)
{
    if (root == nullptr)
        return new Node(value);
    if (value < root->data)
        root->left = insertbst(root->left, value);
    else
        root->right = insertbst(root->right, value);
    return root;
}
bool searchbst(Node *root, int value)
{
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return searchbst(root->left, value);
    else
        return searchbst(root->right, value);
}
Node *insuccess(Node *node)
{
    Node *curr = node;
    while (curr && curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}
void deletebst(Node *&root, int value)
{
    if (root == nullptr)
        return;
    // find the node
    if (value < root->data)
        deletebst(root->left, value);
    else if (value > root->data)
        deletebst(root->right, value);
    else
    {
        // found
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            Node *tmp = insuccess(root->right);
            root->data = tmp->data;
            deletebst(root->right, tmp->data);
        }
    }
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
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
        cout << curr->data << " ";
    }
}
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    int l = height(node->left);
    int r = height(node->right);
    return 1 + max(l, r);
}

void topview(Node *node)
{
    if (node == nullptr)
        return;

    int top[500];
    int offset = 250;
    bool seen[500] = {false};
    Queueforview q;
    q.push(node, 0);
    while (!q.empty())
    {
        Pairnode cur = q.getfront();
        q.pop();
        int ind = cur.hd + offset;
        if (!seen[ind])
        {
            seen[ind] = true;
            top[ind] = cur.node->data;
        }
        if (cur.node->left)
        {
            q.push(cur.node->left, cur.hd - 1);
        }
        if (cur.node->right)
        {
            q.push(cur.node->right, cur.hd + 1);
        }
    }
    for (int i = 0; i < 500; i++)
    {
        if (seen[i])
        {
            cout << top[i] << " ";
        }
    }
}

void bottomview(Node *root)
{
    if (root == nullptr)
        return;
    Queueforview q;
    q.push(root, 0);
    int bottom[500];
    for (int i = 0; i < 500; i++)
    {
        bottom[i] = -1;
    }
    int offset = 250;
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
void rightview(Node *node)
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
            if (i == levelsize - 1)
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
int main(int argc, char *argv[])
{

    freopen(argv[1], "r", stdin);
    freopen("output.txt", "w", stdout);
    Node *root = nullptr;
    int op, x;
    while (cin >> op)
    {
        if (op == 13)
        {
            cout << "Exited due to user command 13 ";
            break;
        }

        switch (op)
        {
        case 1:
            // insert
            cin >> x;
            root = insertbst(root, x);
            cout << "Inserted " << x << endl;
            ;
            break;
        case 2:
            // search
            cin >> x;
            cout << (searchbst(root, x) ? "Found" : "Not Found") << x << endl;
            break;

        case 3:
            cin >> x;
            deletebst(root, x);
            cout << "Deleted" << x << endl;
            break;
        case 4:

            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 5:

            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;
        case 6:

            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Levelorder: ";
            levelorder(root);
            cout << endl;
            break;
        case 8:
            cout << "Height: ";
            cout << height(root) << endl;
            break;
        case 9:
            cout << "Top view: ";
            topview(root);
            cout << endl;
            break;

        case 10:
            cout << "Bottom view: ";
            bottomview(root);
            cout << endl;
            break;

        case 11:
            cout << "Right view: ";
            rightview(root);
            cout << endl;
            break;
        case 12:
            cout << "Left view: ";
            leftview(root);
            cout << endl;
            break;
        }
    }

    return 0;
}
