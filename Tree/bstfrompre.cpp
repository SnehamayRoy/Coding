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
Node *build(int arr[], int &index, int n, int up)
{
    if (index == n || arr[index] > up)
    {
        return nullptr;
    }
    int rootval = arr[index++];
    Node *root = new Node(rootval);
    root->left = build(arr, index, n, rootval);
    root->right = build(arr, index, n, up);

    return root;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    return 0;
}