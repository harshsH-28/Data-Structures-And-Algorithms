#include <bits/stdc++.h>
using namespace std;

// Breadth First Search

void print2(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == front)
                continue;
            if (edges[front][i] == 1)
            {
                if (visited[i] == true)
                    continue;
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void print2(int **edges, int n)
{
    bool *visited = new bool[n]();
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            print2(edges, n, i, visited);
    }
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n](); //() automatically assign default value to zero

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n]();
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    print2(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
