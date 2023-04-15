// Works for both 1 or 0 based indexed Graph
class DisjointSet
{
    vector<int> parent, rank;
public:
    DisjointSet(int v)
    {
        rank.resize(v + 1, 0);
        parent.resize(v + 1);
        for (int i = 0; i <= v; i++)
            parent[i] = i;
    }

    int findPar(int u)
    {
        if (u == parent[u]) return u;
        // Path Compression
        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int u_ulp = findPar(u); // u_ulp == ultimate parent of u
        int v_ulp = findPar(v); // v_ulp == ultimate parent of v
        if (u_ulp == v_ulp) return;

        if (rank[u_ulp] < rank[v_ulp])
            parent[u_ulp] = v_ulp;
        else if (rank[u_ulp] > rank[v_ulp])
            parent[v_ulp] = u_ulp;
        else
        {
            parent[v_ulp] = u_ulp;
            rank[u_ulp]++;
        }
    }
};
