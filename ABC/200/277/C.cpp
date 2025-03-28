#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result;
map <ll, vector <ll>> adj;
map <ll, bool> v;

void dfs(ll cur){
    if(v[cur]) return; v[cur] = 1;
    result = max(cur, result);

    for(auto& nxt: adj[cur]) dfs(nxt);
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    dfs(1); cout << result;


    return 0;
}
