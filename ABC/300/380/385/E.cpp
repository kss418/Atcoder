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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll ind[MAX];
vector <ll> adj[MAX];

ll dfs(ll cur){
    ll ret = INF;
    sort(all(adj[cur]), [](ll a, ll b){
        return ind[a] > ind[b];
    });

    ll x = 0, y = 0;
    for(auto& nxt : adj[cur]) {
        x++; y = ind[nxt] - 1;
        ret = min(ret, n - x * y - x - 1);
    }
    
    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i < n;i++) {
        ll s, e; cin >> s >> e;
        ind[s]++; ind[e]++;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }  

    ll result = INF;
    for(int i = 1;i <= n;i++){
        result = min(result, dfs(i));
    }

    cout << result;

     
    return 0;
}
