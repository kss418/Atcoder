#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], arr;
ll dp[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        ret += solve(nxt, cur);
    }

    if(adj[cur].size() == 1) return ret = 1;
    return ++ret;
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++) {
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    memset(dp, -1, sizeof(dp));
    solve(1); ll sum = 0;
    for(auto& nxt : adj[1]){
        sum += solve(nxt);
        arr.push_back(solve(nxt));
    }
    sort(all(arr)); sum -= arr.back();
    
    cout << sum + 1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
