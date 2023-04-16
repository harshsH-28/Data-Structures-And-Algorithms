// We can also use one array for cycle detection, one array will be visited array and we can use it like this --> visited -> 1, pathVisited -> 2, not visited -> 0
bool dfs(int s, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited)
{
    visited[s] = true;
    pathVisited[s] = true;

    for (auto i : adj[s])
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited))
                return true;
        }
        // Four Cases visi == 0 && pvisi == 0, like this cases are 00, 01, 10, 11
        // 0
        if (pathVisited[i] == 1) return true;
    }

    pathVisited[s] = false;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V), pathVisited(V);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited))
                return true;
        }
    }

    return false; // Means we have not found any cycle
}
