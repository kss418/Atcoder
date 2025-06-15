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
vector <pll> adj[MAX];
bool v[MAX][1101];
deque <pll> q;

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }

    q.push_back({1, 0});
    v[1][0] = 1;

    while(!q.empty()){
        auto [cur, cw] = q.front(); q.pop_front();

        for(auto& [nxt, co] : adj[cur]){
            if(v[nxt][cw ^ co]) continue;
            q.push_back({nxt, cw ^ co});
            v[nxt][cw ^ co] = 1;
        }
    }

    for(int i = 0;i < 1024;i++){
        if(!v[n][i]) continue;
        cout << i; return;
    }

    cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

