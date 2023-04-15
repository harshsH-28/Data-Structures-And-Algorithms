#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
class DisjointSet
{
    vector<int> parent, rank, size;
public:

    DisjointSet(int v)
    {
        rank.resize(v + 1, 0);
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

    void unionByRank(int u, int v)
    {
        int u_ulp = findPar(u);
        int v_ulp = findPar(v);
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

    void unionBySize(int u, int v)
    {
        int u_ulp = findPar(u);
        int v_ulp = findPar(v);
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
void solve()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;
    solve();
    return 0;
}
