#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll result;
bool v[MAX];

ll dfs(ll cur, ll pre){
    ll ret = 0;
    if(adj[cur].size() == 2) return ret = 1;
    else if(adj[cur].size() != 3) return ret = 0;
    v[cur] = 1;

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += dfs(nxt, cur);
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    ll root = 0;
    for(int i = 1;i <= n;i++) {
        if(v[i]) continue;
        if(adj[i].size() != 3) continue;
        ll now = dfs(i, 0);

        result += (now * (now - 1)) / 2;
    }

    cout << result;


    return 0;
}

