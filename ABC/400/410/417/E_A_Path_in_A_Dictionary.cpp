#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], result;
bool v[MAX];
ll x, y, flag;

void dfs(ll cur){
    if(v[cur]) return; v[cur] = 1;
    result.push_back(cur);

    if(cur == y){
        if(flag) return; flag = 1;
        for(auto& i : result) cout << i << " ";
        return;
    }

    for(auto& nxt: adj[cur]) dfs(nxt);
    result.pop_back();
}

void run(){
    cin >> n >> m >> x >> y; flag = 0;
    for(int i = 1;i <= n;i++) adj[i].clear();
    result.clear(); memset(v, 0, sizeof(v));

    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++) sort(all(adj[i]));
    dfs(x); cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}