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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], ind[MAX], result;
pll p[MAX];
vector <pll> adj[MAX];
deque <ll> q;

void init(ll cur, ll co, ll pre = -1){
    p[cur] = {pre, co}; ind[pre]++;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        init(nxt, co, cur);
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    init(1, 0);
    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push_back(i);
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        auto [nxt, co] = p[cur];
        if(nxt == -1) break;
        result += abs(a[cur]) * co;
        a[nxt] += a[cur];
        if(!--ind[nxt]) q.push_back(nxt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

