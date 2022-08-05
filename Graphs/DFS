#include <bits/stdc++.h>
using namespace std;

// Depth First Search
void print(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i] == 1)
            {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

void print(int **edges, int n)
{
    bool *visited = new bool[n]();
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            print(edges, n, i, visited);
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

    print(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
