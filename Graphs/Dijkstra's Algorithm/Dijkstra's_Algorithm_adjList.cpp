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
