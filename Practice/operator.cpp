#include <iostream>
using namespace std;
struct Node
{
    int data;
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

public:
    stack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int s)
    {
        Node *newnode = new Node(s);
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
    int peek()
    {
        return top->data;
    }
};
int prefix(string s)
{
    stack st;
    for (auto i : s)
    {
        if (i >= '0' && i <= '9')
            st.push(i - '0');
        else
        {
            int s1 = st.peek();
            st.pop();
            int s2 = st.peek();
            st.pop();
            if (i == '+')
                st.push(s1 + s2);
            else if (i == '-')
                st.push(s2 - s1);
            else if (i == '*')
                st.push(s2 * s1);
            else if (i == '/')
                st.push(s2 / s1);
            else if (i == '^')
            {
                int res = 1;
                for (int i = 0; i < s1; i++)
                {
                    res = res * s2;
                }
                st.push(res);
            }
        }
    }
    return st.peek();
}
int main()
{
    string s;
    cin >> s;
    cout << prefix(s) << endl;
    return 0;
}