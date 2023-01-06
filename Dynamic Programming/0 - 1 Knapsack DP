// 0 - 1 Knapsack Problem

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// template<typename T>T gcd(T a, T b) {if (a == 0 || b == 0)return a ^ b; return gcd(b, a % b);}
int knapsack(int idx, int c, vector<int> &v, vector<int> &w, vector<vector<int>> &dp)
{
    if (idx < 0 || c == 0)
        return 0;
    if (dp[idx][c] != -1) return dp[idx][c];
    int ntake = knapsack(idx - 1, c, v, w, dp);
    int take = INT_MIN;
    if (c >= w[idx])
        take = v[idx] + knapsack(idx - 1, c - w[idx], v, w, dp);
    return dp[idx][c] = max(ntake, take);
}
void solve()
{
    int n, c; cin >> n >> c;
    vector<int> v(n), w(n);
    for (auto &i : v)
        cin >> i;
    for (auto &i : w)
        cin >> i;
    vector<vector<int>> dp(n, vector<int>(c + 1));
    for (int i = w[0]; i <= c; i++)
        dp[0][i] = v[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            int ntake = dp[i - 1][j];
            int take = INT_MIN;
            if (j >= w[i])
                take = v[i] + dp[i - 1][j - w[i]];
            dp[i][j] = max(ntake, take);
        }
    }
    cout << dp[n - 1][c] << endl;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast;
    int t = 1, k = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << k << ": ";
        solve();
        ++k;
    }
    return 0;
}
