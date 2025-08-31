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
    char pop()
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

    char peek()
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
int priority(char s)
{
    if (s == '^')
        return 3;
    else if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
    else
        return 0;
}

string postfix(string s, int n)
{
    stack st;
    string ans = "";
    for (auto i : s)
    {
        if ((i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
            ans = ans + i;
        else if (i == '(')
            st.push(i);
        else if (i == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                ans = ans + st.peek();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.isEmpty() && priority(i) <= priority(st.peek()))
            {
                ans = ans + st.peek();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.isEmpty())
    {
        ans = ans + st.peek();
        st.pop();
    }
    return ans;
}
int main()
{
    int size;
    cin >> size;
    string s;
    cin >> s;
    cout << postfix(s, size) << endl;

    return 0;
}