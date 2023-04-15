// Works for both 1 or 0 based indexed Graph
class DisjointSet
{
    vector<int> parent, size;
public:
    DisjointSet(int v)
    {
        size.resize(v + 1, 1);
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

    void unionBySize(int u, int v)
    {
        int u_ulp = findPar(u); // u_ulp == ultimate parent of u
        int v_ulp = findPar(v); // v_ulp == ultimate parent of v
        if (u_ulp == v_ulp) return;

        if (size[u_ulp] < size[v_ulp])
        {
            parent[u_ulp] = v_ulp;
            size[v_ulp] += size[u_ulp];
        }
        else
        {
            parent[v_ulp] = u_ulp;
            size[u_ulp] += size[v_ulp];
        }
    }
};
