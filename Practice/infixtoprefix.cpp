#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char value)
    {
        data = value;
        next = nullptr;
    }
};
class stack
{
private:
    Node *top;

public:
    stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(char n)
    {
        Node *newnode = new Node(n);
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (isEmpty())
            return;
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    char peek()
    {
        return top->data;
    }
};
string reverseandswap(string s)
{
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '(')
            ans = ans + ')';
        else if (s[i] == ')')
            ans = ans + '(';
        else
            ans = ans + s[i];
    }
    return ans;
}
string reverse(string s)
{
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans = ans + s[i];
    }
    return ans;
};
int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
string prefix(string s)
{
    stack st;
    string ans = "";
    for (auto i : s)
    {
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
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
            while (!st.isEmpty() && (priority(i) < priority(st.peek()) || (priority(i) == priority(st.peek()) && i != '^')))
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
    string s;
    cin >> s;
    cout << reverse(prefix(reverseandswap(s))) << endl;
    return 0;
}