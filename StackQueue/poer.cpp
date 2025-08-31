#include <iostream>
using namespace std;
int power(int n, int p)
{
    int res = n;
    if (p == 0)
        return 1;
    while (p > 1)
    {
        res = res * n;
        p--;
    }
    return res;
}
int main()
{
    cout << power(8, 0) << endl;
    return 0;
}