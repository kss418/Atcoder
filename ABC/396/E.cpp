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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll x[MAX], y[MAX], z[MAX], c[2], result[MAX];
vector <pll> adj[MAX];
short num[MAX];
bool v[MAX], use[MAX], flag = 1;

void init(){
    for(int i = 1;i <= n;i++) adj[i].clear();
    memset(num, -1, sizeof(num));
    memset(v, 0, sizeof(v));
    memset(use, 0, sizeof(use));
}

void dfs(ll cur, ll pre, ll cnt){
    if(num[cur] != -1){
        if(num[cur] != cnt) flag = 0;
        return;
    }

    num[cur] = cnt; c[cnt]++; v[cur] = 1;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur, cnt ^ co);
    }
}

void det(ll cur, ll pre, ll dep){
    if(use[cur]) return; use[cur] = 1;
    ll now = (c[0] >= c[1] ? num[cur] : num[cur] ^ 1);
    result[cur] |= (now << dep);
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        det(nxt, cur, dep);
    }
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> x[i] >> y[i] >> z[i];

    for(int i = 0;i < 31;i++){
        init();
        for(int j = 1;j <= m;j++){
            ll now = (z[j] & (1ll << i) ? 1 : 0);
            adj[x[j]].push_back({y[j], now});
            adj[y[j]].push_back({x[j], now});
        }

        for(int j = 1;j <= n;j++){
            if(v[j]) continue;
            c[0] = c[1] = 0;
            dfs(j, -1, 0); det(j, -1, i);
        }
    }
    
    if(flag) for(int i = 1;i <= n;i++) cout << result[i] << " ";
    else cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
