#include <iostream>
using namespace std;
struct Node
{
    string data;
    Node *next;
    Node(string value)
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
    void push(string s)
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
    string peek()
    {
        return top->data;
    }
};
string prefix(string s)
{
    stack st;
    for (auto i : s)
    {
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
            st.push(string(1, i));
        else
        {
            string s1 = st.peek();
            st.pop();
            string s2 = st.peek();
            st.pop();
            st.push(string(1, i) + s2 + s1);
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