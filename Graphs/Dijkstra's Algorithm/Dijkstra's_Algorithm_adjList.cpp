// We can also use Set instead of Priority Queue but not much improvement in TC, but Set will helps you save uneccessary iteration but it will use log(setSize).
// Set basically erase an old value in set which we will iterate over later but we found the better value from it,
// so from erasing that value, in future we don't need to do the iteration for old value.
// TC -> O(ElogV)
// SC -> O(V + E)
class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // Pair Min-Heap
        
        dist[S] = 0;
        pq.push({0,S}); // pair.first -> distance & pair.second -> vertex
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();
            
            for(auto adjNodes: adj[vertex])
            {
                int adjNode = adjNodes[0];
                int edgeWt = adjNodes[1];
                
                if(dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
    }
};
