#include<bits/stdc++.h>
using namespace std;

void printSolution(int** solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}

void helper(int maze[0][19] , int** solution, int n, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        printSolution(solution, n);
        return;
    }
    if (x < 0 || y < 0 || x >= n || y >= n || solution[x][y] == 1 || maze[x][y] == 0)
    {
        return;
    }
    solution[x][y] = 1;
    helper( maze, solution, n, x - 1, y);
    helper( maze, solution, n, x + 1, y);
    helper( maze, solution, n, x, y - 1);
    helper( maze, solution, n, x, y + 1);
    solution[x][y] = 0;
}

void ratMaze(int maze[][19], int n)
{
    int **solution = new int*[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        memset(solution[i], 0, n * sizeof(int));
    }

    helper( maze, solution, n, 0, 0);
}

int main() {
    int n; cin >> n;
    int maze[19][19] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    ratMaze(maze, n);
    return 0;
}
