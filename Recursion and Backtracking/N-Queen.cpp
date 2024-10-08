#include<bits/stdc++.h>
using namespace std;

int a[11][11];

bool position(int n, int row, int col)
{
    // Upper path
    for (int i = row - 1; i >= 0; i--)
    {
        if (a[i][col] == 1)
            return false;
    }
    // Upper Left Diagonal path
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (a[i][j] == 1)
            return false;
    }
    // Upper Right Diagonal Path
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (a[i][j] == 1)
            return false;
    }

    return true;
}

void nQueenHelper(int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (position(n, row, j))
        {
            a[row][j] = 1;
            nQueenHelper(n, row + 1);
            a[row][j] = 0;
        }
    }
}

void nQueen(int n)
{
    memset(a, 0, 11 * 11 * sizeof(int));
    nQueenHelper(n, 0);
}

int main() {

    int n;
    cin >> n;
    nQueen(n);
    return 0;
}
