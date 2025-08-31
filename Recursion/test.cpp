#include <iostream>
using namespace std;
void f(int i, int n)
{
    if (i > n)
        return;
    f(i + 1, n);
    cout << i << " ";
}
int main()
{
    int n = 5;
    f(1, 5);
    return 0;
}
