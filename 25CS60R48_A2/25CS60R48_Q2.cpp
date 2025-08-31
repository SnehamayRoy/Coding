#include <iostream>
#include <cmath>
using namespace std;

int n;
int queens[20]; // queens[row] = column of queen in that row

// Check if a queen can be placed at (row, col)
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
            return false; // same column or diagonal
    }
    return true;
}

// Recursive function to solve N-Queens
bool solve(int row)
{
    if (row == n)
        return true; // all queens placed

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            queens[row] = col; // place queen
            if (solve(row + 1))
                return true; // recurse
            // backtrack automatically
        }
    }
    return false; // no valid column in this row
}

int main()
{
    cin >> n;

    if (solve(0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == queens[i])
                    cout << "Q ";
                else
                    cout << "* ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "no solution\n";
    }

    return 0;
}
