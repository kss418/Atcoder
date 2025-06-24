#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX], nxt[MAX];
vector <pll> adj;

ll tf(ll cur){
    cur %= n; cur += n;
    return cur % n;
}

void run(){
    cin >> n >> m >> k;
    while(m--){
        ll s, e; cin >> s >> e;
        adj.push_back({s - 1, e - 1});
    }

    dp[0] = 1;
    for(int i = 0;i < k;i++){ 
        for(auto& [s, e] : adj){
            nxt[tf(e - i - 1)] += dp[tf(s - i)];
            nxt[tf(e - i - 1)] %= MOD;
        }

        for(auto& [s, e] : adj){
            dp[tf(e - i - 1)] += nxt[tf(e - i - 1)];
            nxt[tf(e - i - 1)] = 0;
        }
    }

    ll result = 0;
    for(int i = 0;i < n;i++){
        result += dp[i];
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}