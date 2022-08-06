#include <bits/stdc++.h>
using namespace std;

int minWeightVertex(int *weight, int v, bool *visited)
{
    int min = INT_MAX;
    int ans = 0;
    for (int i = 0; i < v; i++)
    {
        if (min > weight[i] && !visited[i])
        {
            min = weight[i];
            ans = i;
        }
    }
    return ans;
}

void prims(int **graph, int v, int e)
{
    bool *visited = new bool[v]();
    int *parent = new int[v];
    int *weight = new int[v];

    for (int i = 0; i < v; i++)
    {
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < (v - 1); i++)
    {
        int curr = minWeightVertex(weight, v, visited);
        visited[curr] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[curr][j] != 0 && !visited[j])
            {
                if (graph[curr][j] < weight[j])
                {
                    weight[j] = graph[curr][j];
                    parent[j] = curr;
                }
            }
        }
    }

    for (int i = 1; i < v; i++)
    {
        cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << weight[i] << endl;
    }
    delete[] visited;
    delete[] weight;
    delete[] parent;
}

int main()
{
    int v, e;
    cin >> v >> e;

    int **graph = new int *[v];
    for (int i = 0; i < v; i++)
    {
        graph[i] = new int[v]();
    }

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        graph[f][s] = w;
        graph[s][f] = w;
    }

    prims(graph, v, e);

    for (int i = 0; i < v; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
