#include <iostream>
using namespace std;

// Function to swap two characters
void swapChar(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

// Recursive function to generate permutations
void permute(char s[], int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i <= r; i++)
            cout << s[i];
        cout << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swapChar(s[l], s[i]); // place ith char at index l
        permute(s, l + 1, r); // recurse for remaining characters
        swapChar(s[l], s[i]); // backtrack
    }
}

int main()
{
    int n;
    cin >> n;
    char s[20]; // assuming n <= 20
    for (int i = 0; i < n; i++)
        cin >> s[i];

    permute(s, 0, n - 1);

    return 0;
}
