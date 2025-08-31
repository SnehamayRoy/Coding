#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>> &Matrix, vector<vector<int>> &visited, int m, int n)
{
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                if ((delrow == 0 && delcol != 0) || (delrow != 0 && delcol == 0))

                {
                    int nrow, ncol;
                    nrow = row + delrow;
                    ncol = col + delcol;
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && Matrix[nrow][ncol] == 'O' && !visited[nrow][ncol])
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> Matrix(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            Matrix[i][j] = x;
        }
    }
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        if (Matrix[0][i] == 'O' && !visited[0][i])
        {
            bfs(0, i, Matrix, visited, m, n);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (Matrix[m - 1][i] == 'O' && !visited[m - 1][i])
        {
            bfs(m - 1, i, Matrix, visited, m, n);
        }
    }
    for (int i = 1; i < m - 1; i++)
    {
        if (Matrix[i][0] == 'O' && !visited[i][0])
        {
            bfs(i, 0, Matrix, visited, m, n);
        }
    }
    for (int i = 1; i < m - 1; i++)
    {
        if (Matrix[i][n - 1] == 'O' && !visited[i][n - 1])
        {
            bfs(i, n - 1, Matrix, visited, m, n);
        }
    }
    vector<vector<char>> result(m, vector<char>(n));
    ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Matrix[i][j] == 'O' && !visited[i][j])
                result[i][j] = 'X';
            else
                result[i][j] = Matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}