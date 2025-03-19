#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
template<typename T>T gcd(T a, T b) {if (a == 0 || b == 0)return a ^ b; return gcd(b, a % b);}
int mod = 1000000007;
int solve2(int i, int x, vector<int> &coins, vector<vector<int>> &dp) {
    // cout<<i<<" "<<x<<endl;
    if(x == 0) return 0;
    if(i == 0) return 1e9;

    if(dp[i][x] != -1) return dp[i][x];

    int take = INT_MAX;
    if(coins[i-1] <= x) {
        take = 1 + solve2(i, x-coins[i-1], coins, dp);
    }
    int ntake = solve2(i-1, x, coins, dp);

    return dp[i][x] = min(take, ntake);
}
void solve()
{
    int n, k; cin>>n>>k;

    vector<int> arr(n);
    for(auto& el: arr) cin>>el;

    while(k--) {
        int query; cin>>query;

        int l = -1, r = n;

        /*
            Two Invariances
            
            1. Find the element less than or equal to x. i.e. a[i] <= x
                a[l] <= x
                a[r] > x

                return l in this case because l will contain our element which we want to find.

            2. Find the element greater than or equal to x. i.e. a[i] >= x
                a[l] < x
                a[r] >= x

                return r in this case because r will contain our element which we want to find.
        */

        while(r > l+1) {
            int m = (l+r)/2;

            if(arr[m] < query) {
                l = m;
            } else {
                r = m;
            }
        }

        if(r < n && arr[r] == query) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        // cout<<r+1<<endl;
    }
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
