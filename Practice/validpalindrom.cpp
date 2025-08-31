#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class stack
{
private:
    Node *top;
    int size = 0;

public:
    stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int data)
    {
        Node *newnode = new Node(data);
        newnode->next = top;
        top = newnode;
        size++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node *temp = top;
        int item = top->data;
        top = top->next;
        delete temp;
        size--;
        return item;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    int getsize()
    {
        return size;
    }
};
bool validpalindrome(string s)
{
    stack st;
    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
            st.push(i);
        else if (i == ')' || i == '}' || i == ']')
        {
            if (st.isEmpty())
                return false;
            if (i == ')' && st.peek() != '(' || i == '}' && st.peek() != '{' || i == ']' && st.peek() != '[')
                return false;
            st.pop();
        }
    }
    return st.isEmpty();
}

int main()
{
    string s;
    cin >> s;
    cout << validpalindrome(s) << endl;
    return 0;
}
