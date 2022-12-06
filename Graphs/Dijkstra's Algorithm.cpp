#include <bits/stdc++.h>
using namespace std;

int minDistanceVertex(int *dist, int v, bool *visited)
{
    int min = INT_MAX;
    int ans = 0;
    for (int i = 0; i < v; i++)
    {
        if (min > dist[i] && !visited[i])
        {
            min = dist[i];
            ans = i;
        }
    }
    return ans;
}

void dijkstra(int **graph, int v, int e)
{
    bool *visited = new bool[v]();
    int *dist = new int[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;

    for (int i = 0; i < (v - 1); i++)
    {
        int curr = minDistanceVertex(dist, v, visited);
        visited[curr] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[curr][j] != 0 && !visited[j])
            {
                int pathCost = dist[curr] + graph[curr][j];
                if (pathCost < dist[j])
                {
                    dist[j] = pathCost;
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    delete[] visited;
    delete[] dist;
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

    dijkstra(graph, v, e);

    for (int i = 0; i < v; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
