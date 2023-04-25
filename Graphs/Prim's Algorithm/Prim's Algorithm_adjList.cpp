// Prim's Algorihtm using Adjacency List
// Time Complexity => O((V+E)LogE)
// Space Complexity => O(E + V)
int primsAlgo(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, 0);

    int src = 0;
    pq.push({0, src});

    int mstSum = 0;
    while (!pq.empty())
    {
        pair<int, int> topEl = pq.top();
        int vertex = topEl.second;
        int weight = topEl.first;
        pq.pop();

        if (visited[vertex]) continue;

        // Add the vertex to MST
        visited[vertex] = 1;
        mstSum += weight;

        // Exploring the Adjacent Vertices
        for (auto& adjNodes : adj[vertex])
        {
            int adjNode = adjNodes[0];
            int edgeWt = adjNodes[1];

            if (!visited[adjNode])
            {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return mstSum;
}
